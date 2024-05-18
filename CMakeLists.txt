cmake_minimum_required(VERSION 3.27)
project(untitled6)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled6 main.cpp
        Person.h
        PersonDatabase.cpp
        PersonDatabase.h
        PersonSerializer.cpp
        PersonSerializer.h)
