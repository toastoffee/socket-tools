/**
  ******************************************************************************
  * @file           : main.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/24
  ******************************************************************************
  */

#include <iostream>

#include "../../../src/socket.h"


int main() {

    Socket serverSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

    // bind
    serverSocket.Bind("127.0.0.1", 8080);

    // listen
    serverSocket.Listen(0);

    std::cout << "[server] echo start successfully" << std::endl;

    // accept
    Socket *connSocket = serverSocket.Accept();

    while(true){

        // receive
        char buffer[1024] = { 0 };
        connSocket->Receive(buffer, sizeof(buffer), SocketFlags::None);

        std::cout << "Message from client: " << buffer << std::endl;

        // send
        connSocket->Send(buffer, strlen(buffer), SocketFlags::None);
    }

    return 0;
}
