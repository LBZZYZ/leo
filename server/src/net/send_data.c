#include "net.h"

void send_udp_data(int sockfd,const char *buf,int len,const struct sockaddr* dest_addr,socklen_t socklen)
{
	int lpv_Length;
	if(-1 == (lpv_Length = sendto(sockfd,buf,len,0,dest_addr,socklen)))
	{
		perror("SNDUDPDATA");
		exit(EXIT_FAILURE);
	}
	printf("SNDLEN:%d\n",lpv_Length);
}

void send_tcp_data(int sockfd,const char *buf,int len)
{
	if(-1 == (send(sockfd,buf,len,0)))
	{
		perror("SNDTCPDATA");
		exit(EXIT_FAILURE);

	}
}
