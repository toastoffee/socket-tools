/**
  ******************************************************************************
  * @file           : socket_set.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/2
  ******************************************************************************
  */



#include "socket_set.h"

SocketSet::SocketSet() : _maxFd(-1), _socketsDict(), _fds()
{ }

SocketSet::~SocketSet() = default;

int SocketSet::Select(SelectMode mode, struct timeval *timeout) {
    switch (mode) {
        case SelectMode::Read:
            return select(_maxFd+1, &_fds, nullptr, nullptr, timeout);

        case SelectMode::Write:
            return select(_maxFd+1, nullptr, &_fds, nullptr, timeout);

        case SelectMode::Exception:
            return select(_maxFd+1, nullptr, nullptr, &_fds, timeout);
    }
}

void SocketSet::Remove(Socket *socket) {

    // remove from the _socketDict
    _socketsDict.erase(socket);

    // remove from the _fds
    FD_CLR(socket->GetFd(), &_fds);
}

int SocketSet::IsInSet(Socket *socket) {

    // check if the socket is in the set
    return FD_ISSET(socket->GetFd(), &_fds);
}

void SocketSet::Add(Socket *socket) {
    // add a new socket to the dict
    _socketsDict.insert(std::pair<Socket*, int>(socket, socket->GetFd()));

    // add a new socket to the _fds
    FD_SET(socket->GetFd(), &_fds);

    // update the maxFd
    _maxFd = _maxFd > socket->GetFd() ? _maxFd : socket->GetFd();
}

void SocketSet::Clear() {
    // clear the socket dict
    _socketsDict.clear();

    // clear the _fds
    FD_ZERO(&_fds);

    // reset the maxFd
    _maxFd = -1;
}
