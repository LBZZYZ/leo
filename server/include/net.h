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

#define	TCPSERVERIP  	"123.221.213.3"
//#define	TCPSERVERIP  	"47.94.161.78"
#define UDPSERVERIP     "172.24.17.182"
#define	TCPSERVERPORT	22222
#define	UDPSERVERPORT	33333
#define	TCPCLIENTPORT	22222
#define	UDPCLIENTPORT	33333
#define	LISTENSIZE	    128
#define	IPSIZE	        16
#define MAX_EVENTS      100
#define FDSIZE 			65535

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
