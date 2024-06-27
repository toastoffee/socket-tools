/**
  ******************************************************************************
  * @file           : main.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/27
  ******************************************************************************
  */

#include <iostream>
#include <map>

#include "../../../src/socket.h"

struct ClientState{
public:
    Socket *socket;
    char *readBuf;
};

std::map<Socket*, ClientState> clients;

void AcceptCallback(Socket* connSocket);
void ReceiveCallback(void* buffer, ClientState state);

// listen Socket
Socket serverSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

int main() {

    // bind
    serverSocket.Bind("127.0.0.1", 8888);

    // listen
    serverSocket.Listen(0);

    std::cout << "[server] chatroom start successfully" << std::endl;

    // accept
    serverSocket.AsyncAccept(AcceptCallback);

    // waiting...
    while(true){}
}

void AcceptCallback(Socket* connSocket){
    std::cout << "[server] accept" << std::endl;

    ClientState state{connSocket};
    state.readBuf = new char[1024];

    clients.insert(std::pair<Socket*, ClientState>(connSocket, state));

    // receive Data from client
    connSocket->AsyncReceive(state.readBuf, sizeof(state.readBuf), [state](void* buf){
        ReceiveCallback(buf, state);
    });

    // continue accept
    serverSocket.AsyncAccept(AcceptCallback);
}

void ReceiveCallback(void* buffer, ClientState state){
    Socket* clientSocket = state.socket;

    // send bytes to all clients
    for (const auto& pair : clients){
        char *str = static_cast<char *>(buffer);
        pair.first->Send(str, strlen(str));
    }

    clientSocket->AsyncReceive(state.readBuf, sizeof(state.readBuf), [state](void* buf){
        ReceiveCallback(buf, state);
    });
}