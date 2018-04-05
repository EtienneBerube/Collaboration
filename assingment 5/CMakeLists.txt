cmake_minimum_required(VERSION 3.8)
project(assingment_5)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE CMAKE_SOURCE_DIR)

#[[include_directories(${PROJECT_SOURCE_DIR})   <------ works as well]]

set(SOURCE_FILES main.cpp sample.json Item.cpp Item.h)
add_executable(assingment_5 ${SOURCE_FILES})

target_include_directories(assingment_5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})