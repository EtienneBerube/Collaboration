cmake_minimum_required(VERSION 3.8)
project(Collaboration)

set(CMAKE_CXX_STANDARD 11)

<<<<<<< HEAD
set(SOURCE_FILES main.cpp Cars_objects/Car.cpp Cars_objects/Car.h Customer_Objects/Customer.cpp Customer_Objects/Customer.h regularCar.cpp regularCar.h luxuryCar.cpp luxuryCar.h)
=======
set(SOURCE_FILES main.cpp Cars_objects/Car.cpp Cars_objects/Car.h Customer_Objects/Customer.cpp Customer_Objects/Customer.h Customer_Objects/VIPCustomer.cpp Customer_Objects/VIPCustomer.h Customer_Objects/CorporateCustomer.cpp Customer_Objects/CorporateCustomer.h Customer_Objects/RegularCustomer.cpp Customer_Objects/RegularCustomer.h)
>>>>>>> 632c9f8348671813adac356fce3ffe527f2dac85
add_executable(Collaboration ${SOURCE_FILES})