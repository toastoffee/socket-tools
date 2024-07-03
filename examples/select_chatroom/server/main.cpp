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

    sockets.push_back(&listenSocket);

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
                int recvSize = socket->Receive(msg, MAX_SIZE);

                if(recvSize == 0){
                    // the client has disconnected
                    std::cout <<"[server] client-"<< socket->GetFd() << " has disconnected:" << msg << std::endl;
                    for(auto it = sockets.begin(); it != sockets.end(); ++it){
                        if(*it == socket){
                            sockets.erase(it);
                            break;
                        }
                    }
                    socket->Close();
                }else{
                    std::cout <<"[server] msg from client:" << msg << std::endl;

                    for (auto client : sockets) {
                        if(client->GetFd() != listenSocket.GetFd()){
                            std::cout <<"[server] msg sent to client-" << client->GetFd();
                            client->Send(msg, MAX_SIZE);
                        }
                    }
                }
            }
        }
    }

    listenSocket.Close();

    return 0;
}
