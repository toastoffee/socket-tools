# socket-tools
a C++11 socket tools library

this lib uses **.Net Socket Classes** as reference, and the function signatures are similar

## Example: synchronized echo program

#### server

```c++
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

        std::cout << "[server] Message from client: " << buffer << std::endl;

        // send
        connSocket->Send(buffer, strlen(buffer), SocketFlags::None);
    }
}
```

#### client

```c++
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
}
```

