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

    int index = 0;

    // bind
    listenSocket.Bind("127.0.0.1", 8888);

    // listen
    serverSocket.Listen(0);

    std::cout << "[server] chatroom start successfully" << std::endl;

    // accept
    serverSocket.AsyncAccept(AcceptCallback);

    // waiting...
    while(true){}
}
