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
#include <arpa/inet.h>
#include <vector>


#include "../../../src/socket.h"
#include "../../../src/socket_set.h"


#define MAX_SIZE 1024

//int main() {
//
//    // listen Socket
//    Socket listenSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
//
//    int maxFd = -1;
//    fd_set readFds;
//    char msg[MAX_SIZE];
//
//    int allfds[MAX_SIZE];
//    memset(allfds, -1, sizeof(allfds));
//    Socket* conn;
//
//    int index = 0;
//
//    // bind
//    listenSocket.Bind("127.0.0.1", 8888);
//
//    // listen
//    listenSocket.Listen(0);
//
//    allfds[index] = maxFd = listenSocket.GetFd();
//
//    std::cout << "[server] chatroom start successfully" << std::endl;
//
//    // waiting...
//    while(true){
//        FD_ZERO(&readFds);
//
//        for(int i = 0; i <= index; i++){
//            FD_SET(allfds[i], &readFds);
//        }
//
//        int nCount = select(maxFd+1, &readFds, NULL, NULL, NULL);
//
//        for(int i = 0; i < MAX_SIZE; i++){
//            if(nCount == 0){
//                break;
//            }
//            if(!FD_ISSET(allfds[i], &readFds)){
//                continue;
//            }
//
//            // listen that client has connected
//            if(allfds[i] == listenSocket.GetFd()) {
//                nCount--;
//                conn = listenSocket.Accept();
//
//                for (int n = 0; n < MAX_SIZE; n++) {
//                    if (allfds[n] == -1) {
//                        allfds[n] = conn->GetFd();
//                        maxFd = maxFd > conn->GetFd() ? maxFd : conn->GetFd();
//                        index = index > n ? index : n;
//                        break;
//                    }
//                }
//            }
//            else{   // listen that client has sent msg
//                memset(msg, 0, sizeof(msg));
//                recv(allfds[i], msg, MAX_SIZE, 0);
//
//                std::cout << msg << std::endl;
//
//                send(allfds[i], msg, MAX_SIZE, 0);
//            }
//        }
//
//    }
//
//    listenSocket.Close();
//
//    return 0;
//}

int main() {

    // initial variables
    std::vector<Socket *> sockets;
    char msg[MAX_SIZE];
    SocketSet socketSet;

    // listen Socket
    Socket listenSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

    // bind
    listenSocket.Bind("127.0.0.1", 8888);

    // listen
    listenSocket.Listen(0);

    std::cout << "[server] chatroom start successfully" << std::endl;

    // waiting...
    while(true){
        socketSet.Clear();

        for (auto socket : sockets){
            socketSet.Add(socket);
        }

        int nCount = socketSet.Select(SelectMode::Read);


        for(auto socket : sockets){

            if(nCount == 0){
                break;
            }

            if(!socketSet.IsInSet(socket)){
                continue;
            }

            // listen the client has connected
            if(socket->GetFd() == listenSocket.GetFd()){
                nCount--;
                Socket* conn = listenSocket.Accept();
                sockets.push_back(conn);
            }else{
                // listen the client has sent msg
                nCount--;

                memset(msg, 0, sizeof(msg));
                socket->Receive(msg, MAX_SIZE);
                std::cout <<"[server] msg from client:" << msg << std::endl;
                socket->Send(msg, MAX_SIZE);
            }
        }
    }

    listenSocket.Close();

    return 0;
}
