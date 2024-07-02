/**
  ******************************************************************************
  * @file           : socket_set.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/2
  ******************************************************************************
  */



#ifndef SOCKET_TOOLS_SOCKET_SET_H
#define SOCKET_TOOLS_SOCKET_SET_H

#include <sys/select.h>
#include <map>

#include "socket.h"

enum class SelectMode {
    Read,
    Write,
    Exception
};

class SocketSet {
private:
    std::map<Socket*, int> _socketsDict;
    fd_set _fds;
    int _maxFd;

public:
    SocketSet();
    ~SocketSet();

    int Select(SelectMode mode, struct timeval *timeout = nullptr);

    void Remove(Socket* socket);
    int IsInSet(Socket* socket);
    void Add(Socket* socket);
    void Clear();
};


#endif //SOCKET_TOOLS_SOCKET_SET_H
