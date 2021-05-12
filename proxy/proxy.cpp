/**
 * simple-proxy-using-c++ 
**/

// Winsock
#include <ws2tcpip.h>
#include "utility/netssh.h"
#include "utility/WSAstartup.h"
// Other Shit
#include <string>
#include <stdlib.h>

#pragma comment(lib, "Ws2_32.lib")

#define MSG_WAITALL 0x8 // Windows does not have this feature.
#define PORT 443


int main (char ** argv, int argc) {
    init();
    printf("Ovpn5 proxy configuration designed by deadlypoe5#7412 \n");

    int data=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in hint;
    socklen_t rsize = sizeof(hint);

    hint.sin_family = AF_INET;
    hint.sin_addr.s_addr = INADDR_ANY;
    hint.sin_port = htons(443);

    hostent* hostinfo;
    hostinfo =  gethostbyname("pool-1.prd.us.dallas.ovpn.com");

    struct sockaddr_in remote;
    socklen_t tsize = sizeof(remote);

    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = (u_long)&hostinfo -> h_addr_list;
    remote.sin_port = htons(1080);


    net::ssh(data, hint);

    int result = connect(data, (sockaddr*)&remote, tsize);
    if (result == -1) {
        printf("connection failed with error %ld # \n", WSAGetLastError());
    }
    
    char local[1024] = {0};
    char remoting[1024] = {0};

    char lmsg = System::readmsg(data, hint, local);
    char rmsg = System::readmsg(data, remote, remoting);

    std::string forward(local, local + sizeof(local));
    std::string remotequery(remoting, remoting + sizeof(remoting));

    printf("Remote Query Processed. \n");

    net::stream(data, remote, remoting);

    closesocket(data);
}