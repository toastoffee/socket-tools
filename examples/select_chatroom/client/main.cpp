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
#include <sys/select.h>

#include "../../../src/socket.h"


Socket clientSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

int main() {

    clientSocket.Connect("127.0.0.1", 8888);


    while(true){
        if(startSend){
            std::string msg;
            std::cin >> msg;

            // send
            clientSocket.Send(msg.c_str(), strlen(msg.c_str()), SocketFlags::None);
        }
    }

    return 0;
}