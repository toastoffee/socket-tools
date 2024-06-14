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
#include "ip_end_point.hpp"

#include <string>

/*
 * 实现 Berkeley 套接字接口
 */
class Socket{

public:

    Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType);

    void Connect(std::string const &address, int port) const;

    void Bind(IPEndPoint localEndPoint) const;

    void Listen(int backlog) const;

    Socket* Accept() const;

    int Send(const void* buffer, int len, SocketFlags socketFlags) const;

    int Receive(const void* buffer, int maxLen, SocketFlags socketFlags) const;

    void Close() const;

private:
    int _socketFileDescriptor;

    AddressFamily _addressFamily;
    SocketType _socketType;
    ProtocolType _protocolType;

};


#endif //SOCKET_TOOLS_SOCKET_H
