cmake_minimum_required(VERSION 3.27)
project(socket_tools)

set(CMAKE_CXX_STANDARD 11)

add_executable(socket_tools
        main.cpp
        src/socket.cpp
        src/socket_set.cpp
)

#add_executable(echo_client
#        examples/echo_msgs/client/main.cpp
#        src/socket.cpp
#)
#
#add_executable(echo_server
#        examples/echo_msgs/server/main.cpp
#        src/socket.cpp
#)

#add_executable(chatroom_server
#        examples/async_chatroom/server/main.cpp
#        src/socket.cpp
#)

#add_executable(chatroom_client
#        examples/async_chatroom/client/main.cpp
#        src/socket.cpp
#)

add_executable(chatroom_server
        examples/select_chatroom/server/main.cpp
        src/socket_set.cpp
        src/socket.cpp
)

add_executable(chatroom_client
        examples/select_chatroom/client/main.cpp
        src/socket.cpp
        src/socket_set.cpp
)
