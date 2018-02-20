//
// Created by Etienne on 19/02/2018.
//

#include "VIPCustomer.h"
#include <iostream>

VIPCustomer::VIPCustomer() = default;

VIPCustomer::VIPCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays)
        : Customer(_id, _name, _address, _telephoneNumber, Customer::VIP, _maxDays) {

}

void VIPCustomer::printInfo() const {
    std::cout <<"ID: "<< getId() << "\nType: " << getTypeString() <<"\nName: " << getName() <<"\nAddress: " << getAddress() <<"\nPhone number: " << getTelephoneNumber()<<std::flush;
}

string VIPCustomer::getTypeString() const {
    return "VIP";
}

VIPCustomer::VIPCustomer(const VIPCustomer &) = default;
