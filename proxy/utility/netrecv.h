
// Winsock
#include   <winsock2.h>
#include   <WS2tcpip.h>
// Other shit
#include   <stdio.h>
#include   <string.h>
#include   <stdlib.h>


#define MSG_WAITALL 0x8

namespace System {
    char readmsg(int socket, sockaddr_in hint, char * read_buffer) { // Read message and make forwarded message.
        socklen_t rsize = sizeof(hint);
        int read = recvfrom(socket, read_buffer, sizeof(read_buffer), MSG_WAITALL, (SOCKADDR*)&hint, (int*)&rsize);
        if (read == -1) {
                printf("recv failed with error # %ld\n", WSAGetLastError());
                exit(1);
        }
        //std::string forward(read_buffer, read_buffer + sizeof(read_buffer));
        return 1;
    }
}