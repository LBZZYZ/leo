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

#define	TCPSERVERIP  	"172.30.225.204"
#define UDPSERVERIP     "172.30.225.204"
#define	TCPLISTENPORT	9817
#define	TCPCLIENTPORT	8000
#define	BACKLOGSIZE      128
#define	IPSIZE	        16
#define MAX_EVENTS      100
#define FDSIZE 		    65535


int init_tcp_listener(); //return listen fd if success
int start_tcp_listen(int listenfd);
int init_udp();
void receive_client_connection(pool_t *pool);

void send_udp_data(int sockfd,const char *buf,int len,const struct sockaddr* dest_addr,socklen_t socklen);
void send_tcp_data(int sockfd,const char *buf,int len);
void tcp_destroy();
void udp_destroy();

#endif
