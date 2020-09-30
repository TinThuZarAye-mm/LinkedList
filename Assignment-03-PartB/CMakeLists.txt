cmake_minimum_required(VERSION 3.16)
project(Assignment_03_PartB)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_03_PartB
        BagInterface.h
        Include.h
        LinkedBag.cpp
        LinkedBag.h
        LinkedBag340.cpp
        LinkedBagClient340.cpp
        Node.cpp
        Node.h)
