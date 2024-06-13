/**
  ******************************************************************************
  * @file           : sock_type.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/13
  ******************************************************************************
  */



#ifndef SOCKET_TOOLS_SOCK_TYPE_H
#define SOCKET_TOOLS_SOCK_TYPE_H

#include <sys/socket.h>

enum SocketType{
    Stream      = SOCK_STREAM,
    Dgram       = SOCK_DGRAM,
    Raw         = SOCK_RAW,
    Rdm         = SOCK_RDM,
    SeqPacket   = SOCK_SEQPACKET,
};


#endif //SOCKET_TOOLS_SOCK_TYPE_H
