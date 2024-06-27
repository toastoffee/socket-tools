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

#include "../../../src/socket.h"


void ConnectionCallback();
void ReceiveCallback(void *buffer);

bool startSend = false;

Socket clientSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

int main() {

    clientSocket.AsyncConnect("127.0.0.1", 8888, ConnectionCallback);


    while(true){
        if(startSend){
            std::string msg;
            std::cout << "[client] input a msg to sent:";
            std::cin >> msg;

            // send
            clientSocket.Send(msg.c_str(), strlen(msg.c_str()), SocketFlags::None);
        }
    }

    return 0;
}

void ConnectionCallback(){
    std::cout << "[client] connect to server successfully" << std::endl;

    startSend = true;

    // start receive
    char buffer[1024] = {0};
    clientSocket.AsyncReceive(buffer, sizeof(buffer), ReceiveCallback);

}

void ReceiveCallback(void *buffer){
    std::cout << "[client] msg from server:" << (char*)buffer << std::endl;

    // continue receive
    memset(buffer, 0, sizeof(buffer));
    clientSocket.AsyncReceive(buffer, 1024, ReceiveCallback);
}