cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Tests/testLoad.cpp
        Tests/tests.h
        Tests/test_structure.h
        SmartPointer/SmartPointer.h
        Interface/Interface.cpp
        Interface/Interface.h
        Tests/testView.cpp
        Tests/testFunc.cpp
        Sequences/LinkedList.h)
