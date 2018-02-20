//
// Created by Etienne on 19/02/2018.
//

#include "VIPCustomer.h"

VIPCustomer::VIPCustomer() = default;

VIPCustomer::VIPCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays)
        : Customer(_id, _name, _address, _telephoneNumber, Customer::VIP, _maxDays) {

}

VIPCustomer::VIPCustomer(const VIPCustomer &) = default;
