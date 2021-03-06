#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 256
#define MONEY_DIGIT_SIZE

void DieWithError(char *);
int prepare_server_socket(int);
void my_scanf(char *,int);
void commun(int);
void read_until_delim(int,char*,char,int);

int main(int argc, char *argv[])
{
    struct sockaddr_in clientAddress;
    unsigned int szClientAddr;
    int cliSock;

    int servSock = prepare_server_socket(10001);

    listen(servSock, 5);

    while (1)
    {
        szClientAddr = sizeof(clientAddress);
        cliSock = accept(servSock, (struct sockaddr *)&clientAddress, &szClientAddr);
        commun(cliSock);
        close(cliSock)
    }
    close(servSock);
    return 0;
}
void DieWithError(char *errorMessage)
    perror(errorMessage);
    exit(1);
}
int prepare_server_socket(int port)
{
    int servSock = socket(PF_INET, SOCK_STREAM, 0);
    if (servSock < 0)
    DieWithError("socket() failed")

    struct sockaddr_in servAddress;
    servAddress.sin_family = AF_INET;
    servAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddress.sin_port = htons(port);

    bind(servSock,(struct sockaddr*)&servAddress,sizeof(servAddress));
    return servSock;
}
