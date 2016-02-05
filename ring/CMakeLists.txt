cmake_minimum_required(VERSION 3.0)

ADD_DEFINITIONS(-Wall)

add_executable(main main.cpp)

target_link_libraries(main ring) 

add_library(ring STATIC ring.cpp)

#install(TARGETS bcd bcc DESTINATION bin)
