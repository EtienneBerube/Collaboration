cmake_minimum_required(VERSION 3.8)
project(Collaboration)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Cars_objects/Car.cpp Cars_objects/Car.h Customer_Objects/Customer.cpp Customer_Objects/Customer.h regularCar.cpp regularCar.h luxuryCar.cpp luxuryCar.h)
add_executable(Collaboration ${SOURCE_FILES})