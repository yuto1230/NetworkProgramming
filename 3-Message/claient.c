#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SEZ 256
#define MONEY_DIGIT_SIZE 10

void

    int
    main(int agec, char *arge[])
{
    if (argc != 3)
        DieWithError("usege: ./client ip_address port")
}
void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}
int prepare_client_socket(char *ipaddr, int port)
{
    int sock =
}