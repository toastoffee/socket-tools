#include <iostream>

#include "../../../src/socket.h"


int main() {

    Socket clientSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

    // connect
    clientSocket.Connect("127.0.0.1", 8080);

    std::cout << "[client] connect to server successfully" << std::endl;

    while(true){
        std::string msg;
        std::cin >> msg;

        // send
        clientSocket.Send(msg.c_str(), strlen(msg.c_str()), SocketFlags::None);

        // receive
        char buffer[1024] = {0};
        clientSocket.Receive(buffer, sizeof(buffer), SocketFlags::None);

        std::cout << "[client] Message from client: " << buffer << std::endl;
    }

    return 0;
}
