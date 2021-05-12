
// Winsock
#include   <winsock2.h>
#include   <WS2tcpip.h>
#include "receive.h"
// Other shit
#include   <stdio.h>
#include   <string.h>
#include   <stdlib.h>

#define cli 30

struct argDNS {
    char *request;
    char *sshconn;
};
#define MSG_WAITALL 0x8

namespace net {
    int ssh(int socket, struct sockaddr_in hint) {
        int  bindResult;
        socklen_t sile = sizeof(hint);

        bindResult = bind(socket, (sockaddr*)&hint, sizeof(hint));
        if (bindResult < 0) {
            printf("Binding socket failed with error # %ld\n", WSAGetLastError());
        }
    }
    int stream(int socket, struct sockaddr_in hint, char * msgBuffer) {
        fd_set dup, cdup;
        int fd, query, qsorting;
        char * querystring;
        qsorting = System::readmsg(socket, hint, msgBuffer);

        socklen_t size = sizeof(hint);

        FD_ZERO(&dup);
	    FD_SET(socket, &dup);
	    FD_SET(0, &dup);

        while (1) {
            cdup = dup;
            select(FD_SETSIZE, (fd_set*)&cdup, NULL, NULL, NULL);
            for (fd = 0; fd < FD_SETSIZE; fd++) {
                if (FD_ISSET(socket, (fd_set*)&cdup))  {
                    if (fd < FD_SETSIZE) {
                            FD_SET(socket, (fd_set*)&cdup);
   
                                if (qsorting == 1) {
                                     query = sendto(socket, msgBuffer, MSG_WAITALL, 0, (SOCKADDR*)&hint, size);
                                    if (query < 0 ) {
                                    printf("Sending message failed with error # %ld \n", WSAGetLastError());
                                    exit (1);
                            }
                            querystring[fd] = query;
                                }
                            }

                            }
                    }
                }
            }
        }