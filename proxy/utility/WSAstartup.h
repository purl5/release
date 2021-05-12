#include   <stdio.h>
#include   <string.h>
#include   <stdlib.h>
#include   <winsock2.h>
#include   <winsock.h>
#include   <WS2tcpip.h>

int init() {
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {                             
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }
}