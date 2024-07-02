/**
  ******************************************************************************
  * @file           : main.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/2
  ******************************************************************************
  */

#include <iostream>
#include <map>
#include <sys/select.h>

#include "../../../src/socket.h"

#define MAX_SIZE 1024

struct ClientState{
public:
    Socket *socket;
    char *readBuf;
};


int main() {

    // listen Socket
    Socket listenSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

    int maxFd = -1;
    fd_set readFds;

    int allfds[MAX_SIZE];
    memset(allfds, -1, sizeof(allfds));
    Socket* conn;

    int index = 0;

    // bind
    listenSocket.Bind("127.0.0.1", 8888);

    // listen
    listenSocket.Listen(0);

    allfds[index] = maxFd = listenSocket.GetFd();

    std::cout << "[server] chatroom start successfully" << std::endl;

    // waiting...
    while(true){
        FD_ZERO(&readFds);

        for(int i = 0; i <= index; i++){
            FD_SET(allfds[i], &readFds);
        }

        int nCount = select(maxFd+1, &readFds, NULL, NULL, NULL);

        for(int i = 0; i < MAX_SIZE; i++){
            if(nCount == 0){
                break;
            }
            if(!FD_ISSET(allfds[i], &readFds)){
                continue;
            }

            // listen that client has connected
            if(allfds[i] == listenSocket.GetFd()) {
                nCount--;
                conn = listenSocket.Accept();

                for (int n = 0; n < MAX_SIZE; n++) {
                    if (allfds[n] == -1) {
                        allfds[n] = conn->GetFd();
                        maxFd = maxFd > conn->GetFd() ? maxFd : conn->GetFd();
                        index = index > n ? index : n;
                        break;
                    }
                }
            }
            else{   // listen that client has sent msg


            }
        }

    }
}
