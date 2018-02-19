cmake_minimum_required(VERSION 3.8)
project(Collaboration)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Car.cpp Car.h Customer.cpp Customer.h)
add_executable(Collaboration ${SOURCE_FILES})