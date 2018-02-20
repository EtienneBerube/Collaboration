//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_VIPCUSTOMER_H
#define COLLABORATION_VIPCUSTOMER_H


#include "Customer.h"

//TODO finish class
class VIPCustomer: public Customer {
public:
    VIPCustomer();
    VIPCustomer(int _id, string _name, string _address, string _telephoneNumber, int _type, int _maxDays);
    VIPCustomer(const VIPCustomer&);
};


#endif //COLLABORATION_VIPCUSTOMER_H
