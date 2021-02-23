#include "net.h"
#include <assert.h>

void send_udp_data(int sockfd,const char *buf,int len,const struct sockaddr* dest_addr,socklen_t socklen)
{
	int length_of_actual_transmission;
	length_of_actual_transmission = sendto(sockfd,buf,len,0,dest_addr,socklen);
	assert(length_of_actual_transmission != -1);
}

void send_tcp_data(int sockfd,const char *buf,int len)
{
	assert(send(sockfd,buf,len,0) != -1);
}
