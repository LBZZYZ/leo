#include "net.h"

int init_udp()
{
	int sockfd;
	/*构造sockaddr_in结构体*/
	struct sockaddr_in serveraddr;
	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(UDPSERVERPORT);
	inet_pton(AF_INET,UDPSERVERIP,&serveraddr.sin_addr.s_addr);
	//serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//char buf[20];
	//printf("%s\n",inet_ntop(AF_INET,&serveraddr.sin_addr.s_addr,buf,16));

	/*创建socket*/
	if(-1 == (sockfd = socket(AF_INET,SOCK_DGRAM,0)))
	{
		perror("udp socket create error");
		return -1;
	}
	/*设置端口可重用*/
	int on = 1;
	if(-1 == setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)))
	{
		perror("setsockopt");
		return -1;
	}
	/*绑定服务器*/
	if(-1 == (bind(sockfd,(const struct sockaddr*)&serveraddr,sizeof(serveraddr))))
	{
		perror("UDP BIND");
		exit(EXIT_FAILURE);
	}
	return sockfd;

}

