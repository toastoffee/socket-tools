/**
  ******************************************************************************
  * @file           : server.cpp
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
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying the address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;     // autofill with my IP

    // binding socket.
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // listening to the assigned socket
    listen(serverSocket, 0);

    printf("server fd: %d!  IP:%s Port:%d\n",serverSocket,inet_ntoa(serverAddress.sin_addr),ntohs(serverAddress.sin_port));
    cout << "[server] echo start successfully" << endl;

    while(true){

        // accepting connection request
        int clientSocket = accept(serverSocket, nullptr, nullptr);

        // receiving data
        char buffer[1024] = { 0 };
        recv(clientSocket, buffer, sizeof(buffer), 0);

        cout << "Message from client: " << buffer << endl;

        // echo the msg
        send(serverSocket, buffer, strlen(buffer), 0);

    }

    return 0;

}