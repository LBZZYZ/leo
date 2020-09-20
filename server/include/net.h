#ifndef _NET_H_
#define _NET_H_

#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "protocol.h"
#include "kernel.h"
#include "pool.h"

#define	TCPSERVERIP  	"192.168.0.188"
#define UDPSERVERIP     "192.168.0.188"
#define	TCPSERVERPORT	8000
#define	UDPSERVERPORT	4567
#define	TCPCLIENTPORT	8000
#define	UDPCLIENTPORT	4567
#define	LISTENSIZE      128
#define	IPSIZE	        16
#define MAX_EVENTS      100
#define FDSIZE 		65535

/*网络初始化*/
int tcp_init();
int udp_init();
/*epoll等待tcp/udp读写*/
void net_open(pool_t *pool);
/*发送网络数据*/
void send_udp_data(int sockfd,const char *buf,int len,const struct sockaddr* dest_addr,socklen_t socklen);
void send_tcp_data(int sockfd,const char *buf,int len);
void tcp_destroy();
void udp_destroy();


#endif
