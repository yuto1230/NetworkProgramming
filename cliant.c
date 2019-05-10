#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define BUF_SEZ 256
void DieWithError(char*errorMessage){
	perror(errorMessage);
	exit(1);
}
void commun(int sock){
	char buf[BUF_SEZ];
	int len_r;
	char*message =  "殺したかっただけで死んでほしくはなかった\n";//"これから毎日単位を焼こうぜ\n"; //"圧倒的留年生！！徹底的留年生！！ 留年生のための留年卓！！\n";
	if (send(sock,message,strlen(message),0) != strlen(message))
		DieWithError("send()sent a message of unexpected bytes");
	if ((len_r = recv(sock,buf,BUF_SEZ,0)) <= 0)
		DieWithError("recv()failed");
	buf[len_r] = '\0';
	printf("%s\n",buf);
}
int main(int argc,char**argv){
	if(argc != 3)
	DieWithError("arguments is not available");
	char*senver_ipaddr = argv[1]; //"10.13.64.20"
	int server_port = atoi (argv[2]);//10001;
	int sock = socket(PF_INET,SOCK_STREAM,0);
	if(sock < 0)
		DieWithError("socket()failed");
	printf("%d\n",sock);
	struct sockaddr_in target;
	target.sin_family = AF_INET;
	target.sin_addr.s_addr = inet_addr(senver_ipaddr);
	target.sin_port = htons(server_port);
	if (connect(sock,(struct sockaddr*)&target,sizeof(target))<0)
		DieWithError("connect()failed");
	
	commun(sock);
	close(sock);
	return 0;
}