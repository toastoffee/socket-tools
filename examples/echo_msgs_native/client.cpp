/**
  ******************************************************************************
  * @file           : client.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/13
  ******************************************************************************
  */

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

int main(){

    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    printf("set server fd: %d!  IP:%s Port:%d\n", clientSocket, inet_ntoa(serverAddress.sin_addr), ntohs(serverAddress.sin_port));

    // sending connection request
    connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress));

    while(true){

        string msg;
        cin >> msg;

        // sending data

        send(clientSocket, msg.c_str(), strlen(msg.c_str()), 0);

        // receiving data
        char buffer[1024] = { 0 };
        recv(clientSocket, buffer, sizeof(buffer), 0);

        cout << "[msg receive from server] " << buffer << endl;
    }

}