cmake_minimum_required(VERSION 3.27)
project(QG C)

set(CMAKE_C_STANDARD 11)

include_directories(major/Week1/LinkList/duLinkList/Headers)
include_directories(major/Week1/LinkList/linkList/Headers)
include_directories(major/Week1/LinkList/linkList/Sources)

add_executable(QG
        major/Week1/LinkList/duLinkList/Headers/duLinkedList.h
        major/Week1/LinkList/duLinkList/Sources/main.c
        major/Week1/LinkList/linkList/Headers/linkedList.h
        major/Week1/LinkList/linkList/Sources/linkedList.h
        major/Week1/LinkList/linkList/Sources/main.c
        minor/Week1/ddasd.h)
