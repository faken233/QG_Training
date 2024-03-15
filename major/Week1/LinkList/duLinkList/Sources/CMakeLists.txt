cmake_minimum_required(VERSION 3.27)
project(linkList C)

set(CMAKE_C_STANDARD 11)

include_directories(major/Week1/LinkList/dulinkList/Headers)
include_directories(major/Week1/LinkList/dulinkList/Sources)

add_executable(1 main.c
        ../Headers/duLinkedList.h)