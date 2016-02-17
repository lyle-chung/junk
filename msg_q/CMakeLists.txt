cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

ADD_DEFINITIONS(-std=c11)

add_executable(www www_server.c)

target_link_libraries(www msg_queue pthread) 

add_library(msg_queue STATIC message_queue.c)

