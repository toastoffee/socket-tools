# socket-tools
a C++11 socket tools library

this lib uses **.Net Socket Classes** as reference, and the function signatures are similar

## Example 1: synchronized echo program

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

## Example 2: asynchronized chatroom

#### server

```c++
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
```

#### client

```c++
void ConnectionCallback();
void ReceiveCallback(void *buffer);

bool startSend = false;

Socket clientSocket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

int main() {

    clientSocket.AsyncConnect("127.0.0.1", 8888, ConnectionCallback);


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

void ConnectionCallback(){
    std::cout << "[client] connect to server successfully" << std::endl;

    startSend = true;

    // start receive
    char *buffer = new char[1024];
    clientSocket.AsyncReceive(buffer, sizeof(buffer), ReceiveCallback);

}

void ReceiveCallback(void *buffer){
    std::cout << "\n[client] msg from server:" << (char*)buffer << std::endl;

    // continue receive
    clientSocket.AsyncReceive(buffer, sizeof(buffer),ReceiveCallback);
}
```