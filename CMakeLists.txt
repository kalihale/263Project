cmake_minimum_required(VERSION 3.23)
project(263Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(CPPAlgorithms)

add_executable(263Project
        CPPAlgorithms/DoubleLinkedList.cpp CPPAlgorithms/LLBase.cpp CPPAlgorithms/LLInterface.h CPPAlgorithms/Node.h CPPAlgorithms/Sorts.h CPPAlgorithms/main.cpp)
