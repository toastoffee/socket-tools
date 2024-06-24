/**
  ******************************************************************************
  * @file           : socket.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/14
  ******************************************************************************
  */


#include <arpa/inet.h>

#include "socket.h"

/*
 * 补充信息
 */
Socket::Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType) :
_addressFamily(addressFamily), _socketType(socketType), _protocolType(protocolType) {

    int addressFamilyId = static_cast<int>(addressFamily);
    int socketTypeid = static_cast<int>(socketType);
    int protocolTypeId = static_cast<int>(protocolType);

    _socketFileDescriptor = socket(addressFamilyId, socketTypeid, protocolTypeId);
}

void Socket::Connect(const char *address, int port) const {

    sockaddr_in serverAddress{};
    serverAddress.sin_family = static_cast<int>(AddressFamily::InterNetwork);
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = inet_addr(address);

    int connectFlag = connect(_socketFileDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
}

void Socket::Bind(IPEndPoint localEndPoint) const {

}

void Socket::Listen(int backlog) const {

}

Socket* Socket::Accept() const {
    return new Socket(AddressFamily::Route, SocketType::Rdm, ProtocolType::Kryptolan);
}

int Socket::Send(const void *buffer, int len, SocketFlags socketFlags) const {
    return 0;
}


int Socket::Receive(const void *buffer, int maxLen, SocketFlags socketFlags) const {
    return 0;
}

void Socket::Close() const {

}
