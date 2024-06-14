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

/*
 * 实现 Berkeley 套接字接口
 */
class Socket{

public:
    Socket(AddressFamily addressFamily, SocketType socketType, ProtocolType protocolType);

    Socket(SocketType socketType, ProtocolType protocolType);


private:
    int socketFileDescriptor;
};


#endif //SOCKET_TOOLS_SOCKET_H
