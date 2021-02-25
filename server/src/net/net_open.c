#include "net.h"
#include "protocol.h"
#include "err_sys.h"
#include "kernel.h"
#include <stdio.h>
#include <assert.h>

/*设置socket为非阻塞*/
static int setnonblocking(int sockfd)
{
	if(-1 == fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0)|O_NONBLOCK))
	{
		err_sys("FCNTL",EXIT_FAILURE);
	}
	return 0;
}

/*添加epoll监听事件*/
static void add_epoll_event(int epollfd,int fd)
{
	struct epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = fd;
	if(-1 == (epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event)))
	{
		err_sys("EPOLL_CTL_IN",EXIT_FAILURE);
	}

}
/*修改epoll监听事件*/
static void modify_epoll_event(int epollfd,int fd)
{
	struct epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = fd;
	if(-1 == (epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&event)))
	{
		err_sys("EPOLL_CTL_IN",EXIT_FAILURE);
	}

}
void receive_client_connection(pool_t *pool)
{
	int listenfd,udpfd,connfd,epollfd,nfds;

	struct epoll_event events[MAX_EVENTS];    
	bzero(&events,sizeof(events));

	listenfd = init_tcp_listener();
	assert(listenfd > 0);

	udpfd = init_udp();
	assert(udpfd > 0);

	epollfd = epoll_create1(0);
	assert(epollfd != -1);

	add_epoll_event(epollfd,listenfd);
	add_epoll_event(epollfd,udpfd);

	job_queue_item *usrs = (job_queue_item*)malloc(sizeof(job_queue_item)*FDSIZE);
	memset(usrs,0,sizeof(job_queue_item)*FDSIZE);

	for(int i=0;i<FDSIZE;i++)
	{
		usrs[i].epollfd = epollfd;
		usrs[i].src_addrlen = sizeof(struct sockaddr_in);
		usrs[i].dest_addrlen = sizeof(struct sockaddr_in);
	}

	for (;;) 
	{
		nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
		assert(nfds != -1);

		for (int n = 0; n < nfds; ++n) 
		{
			if (events[n].data.fd == listenfd)
			{
				connfd = start_tcp_listen(listenfd);
				assert(connfd != -1);
				usrs[connfd].fd = connfd;
				setnonblocking(connfd);
				add_epoll_event(epollfd,connfd);
			}
			else if(events[n].data.fd == udpfd && events[n].events == EPOLLIN)
			{				
				usrs[udpfd].r_length = recvfrom(udpfd,usrs[udpfd].read_buf,BUFSIZE,0,(struct sockaddr*)&usrs[udpfd].src_addr,&usrs[udpfd].src_addrlen);
				assert(usrs[udpfd].r_length != -1);

				usrs[udpfd].fd = udpfd;
				Thread_Add_Task(pool,deal_data,(void*)&usrs[udpfd]);

			}
			else if(events[n].data.fd == udpfd && events[n].events == EPOLLOUT)
			{
				send_udp_data(udpfd,usrs[udpfd].write_buf,usrs[udpfd].w_length,(struct sockaddr*)&usrs[udpfd].dest_addr,usrs[udpfd].dest_addrlen);
				
				modify_epoll_event(epollfd,udpfd);
			}
			else if(events[n].events & EPOLLIN)
			{
				int *p_len = &usrs[connfd].r_length;
				int connfd = events[n].data.fd;
				bzero(usrs[connfd].read_buf, sizeof(usrs[connfd].read_buf));

				if(((-1 == (*p_len = recv(events[n].data.fd, usrs[connfd].read_buf, BUFSIZE, 0))) && (errno != EAGAIN)) || *p_len == 0)
				{
					close(connfd);
					epoll_ctl(epollfd, EPOLL_CTL_DEL, connfd, NULL);
					continue;
				}
				else
				{
					Thread_Add_Task(pool,deal_data,(void*)&usrs[connfd]);
				}				
			}
			else if(events[n].events & EPOLLOUT)
			{
				int connfd = events[n].data.fd;
				send_tcp_data(connfd, usrs[connfd].write_buf, usrs[connfd].w_length);
				modify_epoll_event(epollfd,connfd);

				bzero(usrs[connfd].write_buf,sizeof(usrs[connfd].write_buf));
			}
			else
			{
				exit(EXIT_FAILURE);
			}
		}
		/*处理完成，将epoll传出集合置空*/
		bzero(&events,sizeof(events));

	}
}

