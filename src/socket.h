/**
  ******************************************************************************
  * @file           : socket.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/13
  ******************************************************************************
  */



#ifndef SOCKET_TOOLS_SOCKET_H
#define SOCKET_TOOLS_SOCKET_H

#include "socket_enum.h"

#include <functional>

/*
 * 实现 Berkeley 套接字接口
 */
class Socket{

public:

    Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType);

    Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType, int socketFd);

    Socket(const Socket &) = delete;
    Socket &operator=(const Socket &) = delete;
    Socket(Socket &&) = delete;
    Socket &&operator=(Socket &&) = delete;

    void Connect(const char *address, int port) const;
    void AsyncConnect(const char *address, int port, const std::function<void()>& onConnected = [](){}) const;

    void Bind(const char *address, int port) const;

    void Listen(int backlog) const;

    Socket* Accept() const;
    void AsyncAccept(const std::function<void(Socket*)>& onAccepted) const;

    int Send(const void* buffer, int len, SocketFlags socketFlags = SocketFlags::None) const;
    void AsyncSend(const void* buffer, int len, const std::function<void()>& onSent = [](){}, SocketFlags socketFlags = SocketFlags::None) const;

    int Receive(void* buffer, int maxLen, SocketFlags socketFlags = SocketFlags::None) const;
    void AsyncReceive(void* buffer, int maxLen, const std::function<void(void *)>& onReceived, SocketFlags socketFlags = SocketFlags::None) const;

    void SetTimeOut(int seconds) const;

    void Close() const;

    int GetFd() const;

private:
    int _socketFileDescriptor;

    AddressFamily _addressFamily;
    SocketType _socketType;
    ProtocolType _protocolType;
};


#endif //SOCKET_TOOLS_SOCKET_H
