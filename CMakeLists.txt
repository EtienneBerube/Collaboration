cmake_minimum_required(VERSION 3.8)
project(Collaboration)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES Cars_objects/Car.cpp Cars_objects/Car.h Customer_Objects/Customer.cpp Customer_Objects/Customer.h Customer_Objects/VIPCustomer.cpp Customer_Objects/VIPCustomer.h Customer_Objects/CorporateCustomer.cpp Customer_Objects/CorporateCustomer.h Customer_Objects/RegularCustomer.cpp Customer_Objects/RegularCustomer.h Cars_objects/regularCar.cpp Cars_objects/regularCar.h Cars_objects/luxuryCar.cpp Cars_objects/luxuryCar.h)


add_executable(Collaboration ${SOURCE_FILES})