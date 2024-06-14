/**
  ******************************************************************************
  * @file           : socket_flags.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/14
  ******************************************************************************
  */



#ifndef SOCKET_TOOLS_SOCKET_FLAGS_H
#define SOCKET_TOOLS_SOCKET_FLAGS_H

#include <sys/socket.h>

#define MSG_NONE    0x0

/*
 * 指定套接字发送和接收行为。
 * 此枚举支持其成员值的按位组合。
 */
enum class SocketFlags : int {
    None                    = MSG_NONE,
    Peek                    = MSG_PEEK,
    DontRoute               = MSG_DONTROUTE,
    DataCompleteRecord      = MSG_EOR,
    DiscardBeforeDelivery   = MSG_TRUNC,
    ControlDataLost         = MSG_CTRUNC,
    WaitForAll              = MSG_WAITALL,
    DontWait                = MSG_DONTWAIT,
    EOF                     = MSG_EOF,
    WaitStream              = MSG_WAITSTREAM,
};


#endif //SOCKET_TOOLS_SOCKET_FLAGS_H
