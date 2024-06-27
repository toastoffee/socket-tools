/**
  ******************************************************************************
  * @file           : socket.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/14
  ******************************************************************************
  */

#define DEFAULT_TIME_OUT 5

#include <arpa/inet.h>
#include <thread>
#include <iostream>

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
    SetTimeOut(DEFAULT_TIME_OUT);
}

Socket::Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType, int socketFd) :
    _addressFamily(addressFamily), _socketType(socketType), _protocolType(protocolType), _socketFileDescriptor(socketFd) {
    SetTimeOut(DEFAULT_TIME_OUT);
}

void Socket::Connect(const char *address, int port) const {

    sockaddr_in serverAddress{};
    serverAddress.sin_family = static_cast<int>(AddressFamily::InterNetwork);
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = inet_addr(address);

    int status = connect(_socketFileDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
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


void Socket::SetTimeOut(int seconds) const{
    struct timeval tv{};
    tv.tv_sec = seconds;
    tv.tv_usec = 0;

    setsockopt(_socketFileDescriptor, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv));
    setsockopt(_socketFileDescriptor, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv));
}

void Socket::Close() const {
    shutdown(_socketFileDescriptor, SHUT_RDWR);
}

void Socket::AsyncConnect(const char *address, int port, const std::function<void()>& onConnected) const {

    sockaddr_in serverAddress{};
    serverAddress.sin_family = static_cast<int>(AddressFamily::InterNetwork);
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = inet_addr(address);

    std::thread connectThread = std::thread([this, serverAddress, onConnected](){

        int status = connect(_socketFileDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

        if(status == -1){
            std::cout << "connect to host failed" << std::endl;
            return 0;
        }

        onConnected();

        return 0;
    });

    connectThread.detach();

}

void Socket::AsyncSend(const void *buffer, int len, const std::function<void()> &onSent, SocketFlags socketFlags) const {
    int socketFlagId = static_cast<int>(socketFlags);

    std::thread sendThread = std::thread([this, buffer, len, socketFlagId, onSent](){
        int sendBytesLen = send(_socketFileDescriptor, buffer, len, socketFlagId);

        if(sendBytesLen == -1){
            std::cout << "msg sent to host failed" << std::endl;
            return 0;
        }

        onSent();

        return 0;
    });

    sendThread.detach();
}

void Socket::AsyncReceive(void *buffer, int maxLen, const std::function<void(void *)> &onReceived,
                          SocketFlags socketFlags) const {

    int socketFlagId = static_cast<int>(socketFlags);

    std::thread recvThread = std::thread([this, buffer, maxLen, socketFlagId, onReceived](){
        int recvBytesLen = recv(_socketFileDescriptor, buffer, maxLen, socketFlagId);

        if(recvBytesLen == -1){
            std::cout << "msg receive from host failed" << std::endl;
            return 0;
        }

        onReceived(buffer);
        return 0;
    });

    recvThread.detach();
}

