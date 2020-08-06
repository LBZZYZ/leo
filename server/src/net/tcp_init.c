#include "net.h"
#include "err_sys.h"

//void err_sys(const char*,int);
static int SOCKET(int,int,int);
static int BIND(int,const struct sockaddr*,socklen_t);
static int LISTEN(int,int);
//static int ACCEPT(int,struct sockaddr*,socklen_t*);

int tcp_init()
{
	int listenfd;
	struct sockaddr_in serveraddr,clientaddr;
	bzero(&serveraddr,sizeof(serveraddr));
	bzero(&clientaddr,sizeof(clientaddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(TCPSERVERPORT);
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	listenfd = SOCKET(AF_INET,SOCK_STREAM,0);
	BIND(listenfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	LISTEN(listenfd,LISTENSIZE);


	return listenfd;
}








int SOCKET(int domain, int type, int protocol)
{
	int sockfd;
	sockfd = socket(domain,type,protocol);
	if(sockfd == -1)
		err_sys("SOCKET ERROR",-1);
	return sockfd;
}
int BIND(int sockfd,const struct sockaddr *addr,socklen_t addrlen) 
{
	if(-1 == (bind(sockfd,addr,addrlen)))
		err_sys("BIND ERROR",-1);
	return 0;
}


int LISTEN(int sockfd,int backlog)
{
	if(-1 == (listen(sockfd,backlog)))
		err_sys("LISTEN ERROR",-1);

	return 0;
}

/*int ACCEPT(int sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
	int connfd;
	if(-1 == (connfd = accept(sockfd,addr,addrlen)))
		err_sys("ACCEPT ERROR",-1);

	return connfd;

}*/
