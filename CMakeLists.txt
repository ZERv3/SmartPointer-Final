cmake_minimum_required(VERSION 3.29)
project(SmartPointer)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        SmartPointerExperiment
        SmartPointer/SmartPointer.h
        Tests/Tests.h
        Tests/Tests.cpp
        Interface/Interface.h
        Interface/Interface.cpp
        main.cpp
)
