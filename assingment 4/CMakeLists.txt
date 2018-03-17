cmake_minimum_required(VERSION 3.8)
project(assingment_4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.cpp Graph.h Edge.cpp Edge.h Node.cpp Node.h Adirectional_Graph.cpp Adirectional_Graph.h)
add_executable(assingment_4 ${SOURCE_FILES})