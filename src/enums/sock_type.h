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

/*
 * 指定 Socket 类的实例表示的套接字类型
 */
enum class SocketType : int {
    Stream      = SOCK_STREAM,      /* 支持可靠、双向、基于连接的字节流 */
    Dgram       = SOCK_DGRAM,       /* 支持数据报，即最大长度固定（通常很小）的无连接、不可靠消息 */
    Raw         = SOCK_RAW,         /* 支持对基础传输协议的访问 */
    Rdm         = SOCK_RDM,         /* 支持无连接、面向消息、以可靠方式发送的消息，并保留数据中的消息边界 */
    SeqPacket   = SOCK_SEQPACKET,   /* 在网络上提供排序字节流的面向连接且可靠的双向传输 */
};


#endif //SOCKET_TOOLS_SOCK_TYPE_H
