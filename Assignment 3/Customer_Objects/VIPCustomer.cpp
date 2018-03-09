//
// Created by Etienne on 19/02/2018.
//

#include "VIPCustomer.h"
#include <iostream>

//Default constructor
VIPCustomer::VIPCustomer() = default;

//Regular constructor
VIPCustomer::VIPCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays)
        : Customer(_id, _name, _address, _telephoneNumber, Customer::VIP, _maxDays) {
}

//Function which prints info about a consumer
void VIPCustomer::printInfo() const {
    std::cout <<"ID: "<< getId() << "\nType: " << getTypeString() <<"\nName: " << getName() <<"\nAddress: " << getAddress() <<"\nPhone number: " << getTelephoneNumber()<<std::flush;
}

//Function which returns the type of customer
string VIPCustomer::getTypeString() const {
    return "VIP";
}

//Function which returns the type as an integer
int VIPCustomer::getType() const {
    return Customer::VIP;
}

//Copy constructor
VIPCustomer::VIPCustomer(const VIPCustomer &) = default;
