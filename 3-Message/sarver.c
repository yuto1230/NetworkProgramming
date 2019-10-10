#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 256
#define MONEY_DIGIT_SIZE

int main(int argc, char **argv)
{
    int servSock = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servAddress;
    int cliSock;
    int
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
{
    perror(errorMessage)
        exit(1);
}
int prepare_server_socket(int port)
{
    int sernSock = socket(PF_INET, SOCK_STREAM, 0);
    if (sernSock)
}