#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SEZ 256
#define MONEY_DIGIT_SIZE 10

void DieWithError(char *);
int prepare_client_socket(char *,int);
void my_scanf(char *,int);
void commun(int);

    int main(int agec, char *arge[])
{
    if (argc != 3)
        DieWithError("usege: ./client ip_address port")
        int sock = prepare_client_socket(argv[1],atoi(argv[2]));
        commun(sock);
        close(sock);
        return 0;
}
void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}
int prepare_client_socket(char *ipaddr, int port)
{
    int sock =socket(PF_INET,SOCK_STREAM,0);
    if(sock < 0)
        DieWithError("socket() failed");
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ipaddr);
    target.sin_port = htons(port);
    if (connect(sock,(struct sockaddr*)&target,sizeof(target)) < 0)
        DieWithError("connect() failed");

        return sock;
}
    void my_scanf(cher *buf, int num_letter){
    char format[20]
    scanf(format,buf);
    getcher();
}
void commun(int sock){
    char cmd[2] = "";
    char withdraw[MONEY_DIGIT_SIZE+1]；
    char deposit[MONEY_DIGIT_SIZE+1];
    char msg[BUF_SIEZ]

    printf("0,引き出し 1,預け入れ 2,残高照会");
    printf("何をしますか？ > ");

    my_scanf(cmd,1);

    switch (cmd[0]){
        case '0':
        printf("引き出す金額")
        my_scanf(withdraw,MONEY_DIGIT_SIZE);
        sprintf(msg,"0_%s",withdraw);
        break;
        case '1':
        printf("預け入れ")
        my_scanf(deposit,MONEY_DIGIT_SIZE);
        sprintf(msg,"0_%s_",deposit);
        break;
        case '2':
        strcpy(msg,"0_0_");
        break;
        default:
        printf("番号確認できない\n");
        return ;

    }
    if(send(sock,msg,strlen(msg),0) != strlen(msg))
        DieWithError("send() sent a message of");

        
}