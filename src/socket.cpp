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

Socket::Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType, int socketFd) :
    _addressFamily(addressFamily), _socketType(socketType), _protocolType(protocolType), _socketFileDescriptor(socketFd) { }

void Socket::Connect(const char *address, int port) const {

    sockaddr_in serverAddress{};
    serverAddress.sin_family = static_cast<int>(AddressFamily::InterNetwork);
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = inet_addr(address);

    connect(_socketFileDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
}

void Socket::Bind(const char *address, int port) const {

    sockaddr_in localAddress{};
    localAddress.sin_family = static_cast<int>(AddressFamily::InterNetwork);
    localAddress.sin_port = htons(port);
    localAddress.sin_addr.s_addr = inet_addr(address);

    bind(_socketFileDescriptor, (struct sockaddr*)&localAddress, sizeof(localAddress));
}

void Socket::Listen(int backlog) const {
    listen(_socketFileDescriptor, backlog);
}

Socket* Socket::Accept() const {
    int connSocketFileDescriptor = accept(_socketFileDescriptor, nullptr, nullptr);

    return new Socket(_addressFamily, _socketType, _protocolType, connSocketFileDescriptor);
}

int Socket::Send(const void *buffer, int len, SocketFlags socketFlags) const {
    int socketFlagId = static_cast<int>(socketFlags);
    int sendBytesLen = send(_socketFileDescriptor, buffer, len, socketFlagId);
    return sendBytesLen;
}


int Socket::Receive(void *buffer, int maxLen, SocketFlags socketFlags) const {
    int socketFlagId = static_cast<int>(socketFlags);
    int recvBytesLen = recv(_socketFileDescriptor, buffer, maxLen, 0);
    return recvBytesLen;
}

void Socket::Close() const {
    
}

