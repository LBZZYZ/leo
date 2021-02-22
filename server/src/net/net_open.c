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
static void epoll_add_event(int epollfd,int fd)
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
static void epoll_mod_event(int epollfd,int fd)
{
	struct epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = fd;
	if(-1 == (epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&event)))
	{
		err_sys("EPOLL_CTL_IN",EXIT_FAILURE);
	}

}
void connect_client(pool_t *pool)
{
	int listenfd,udpfd,connfd,epollfd,nfds;
	/*epoll传出监听集合*/
	struct epoll_event events[MAX_EVENTS];    
	bzero(&events,sizeof(events));

	struct sockaddr_in clientaddr;
	bzero(&clientaddr,sizeof(clientaddr));
	socklen_t socklen = sizeof(clientaddr);

	listenfd = tcp_init();
	assert(listenfd > 0);

	udpfd = udp_init();
	assert(udpfd > 0);

	epollfd = epoll_create1(0)))
	assert(epollfd != -1);

	epoll_add_event(epollfd,listenfd);
	epoll_add_event(epollfd,udpfd);

	client_data *usrs = (client_data*)malloc(sizeof(client_data)*FDSIZE);
	memset(usrs,0,sizeof(client_data)*FDSIZE);

	for(int i=0;i<FDSIZE;i++)
	{
		usrs[i].epollfd = epollfd;
		usrs[i].src_addrlen = sizeof(struct sockaddr_in);
		usrs[i].dest_addrlen = sizeof(struct sockaddr_in);
	}
	printf("[3]网络初始化成功\n");

	for (;;) 
	{
		nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
		assert(nfds != -1);

		for (int n = 0; n < nfds; ++n) 
		{
			/*TCP连接*/
			if (events[n].data.fd == listenfd)
			{
				connfd = accept(listenfd,(struct sockaddr *) &clientaddr, &socklen);
				assert(connfd != -1);
				setnonblocking(connfd);
				epoll_add_event(epollfd,connfd);
				usrs[connfd].src_addr = clientaddr;
				usrs[connfd].src_addrlen = socklen;
			}
			/*UDP读*/
			else if(events[n].data.fd == udpfd && events[n].events == EPOLLIN)
			{
				bzero(usrs[udpfd].read_buf,sizeof(usrs[udpfd].read_buf));
				bzero(usrs[udpfd].write_buf,sizeof(usrs[udpfd].write_buf));
				usrs[udpfd].r_length = 0;
				usrs[udpfd].w_length = 0;
				
				/*接收UDP数据*/
				usrs[udpfd].r_length = recvfrom(udpfd,usrs[udpfd].read_buf,BUFSIZE,0,(struct sockaddr*)&usrs[udpfd].src_addr,&usrs[udpfd].src_addrlen);
				assert(usrs[udpfd].r_length != -1);
				
				/*发送UDP服务器应答(只注册用、待改)*/
				registe_rs_t *rq = (registe_rs_t*)usrs[udpfd].read_buf;
				server_rs_t rs;
				rs.packtype = PROTOCOL_SERVER_RS;
				rs.num = rq->packnum;
				send_udp_data(udpfd,(const char*)&rs,sizeof(rs),(struct sockaddr*)&usrs[udpfd].src_addr,sizeof(struct sockaddr_in));

				/*向任务队列中添加任务*/
				usrs[udpfd].fd = udpfd;
				Thread_Add_Task(pool,deal_data,(void*)&usrs[udpfd]);

			}
			/*UDP写*/
			else if(events[n].data.fd == udpfd && events[n].events == EPOLLOUT)
			{
				printf("UDP写\n");
				if(!usrs[udpfd].write_buf)continue;
				send_udp_data(udpfd,usrs[udpfd].write_buf,usrs[udpfd].w_length,(struct sockaddr*)&usrs[udpfd].dest_addr,usrs[udpfd].dest_addrlen);
				
				epoll_mod_event(epollfd,udpfd);
			}
			/*TCP读*/
			else if(events[n].events & EPOLLIN)
			{
				printf("TCP读\n");

				int *p_len = &usrs[connfd].r_length;
				int connfd = events[n].data.fd;
				usrs[connfd].fd = connfd;
				bzero(usrs[connfd].read_buf, sizeof(usrs[connfd].read_buf));

				if(((-1 == (*p_len = recv(connfd, usrs[connfd].read_buf, BUFSIZE, 0))) && (errno != EAGAIN)) || *p_len == 0)
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

			/*TCP写*/
			else if(events[n].events & EPOLLOUT)
			{
				printf("TCP写\n");

				int connfd = events[n].data.fd;
				if(usrs[connfd].write_buf[0] == 0)
				{
					continue;
				}

				send_tcp_data(connfd,(const char*)(&(usrs[connfd].w_length)),4);
				send_tcp_data(connfd,usrs[connfd].write_buf,usrs[connfd].w_length);
		
				epoll_mod_event(epollfd,connfd);
				packtype_t packtype = *(usrs[connfd].write_buf);

				bzero(usrs[connfd].write_buf,sizeof(usrs[connfd].write_buf));
			}
			/*未知事件*/
			else
			{
				exit(EXIT_FAILURE);
			}
		}
		/*处理完成，将epoll传出集合置空*/
		bzero(&events,sizeof(events));

	}
}

