//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_VIPCUSTOMER_H
#define COLLABORATION_VIPCUSTOMER_H


#include "Customer.h"
#include <string>

using std::string;


class VIPCustomer: public Customer {

public:
    VIPCustomer();
    VIPCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays);
    VIPCustomer(const VIPCustomer&);

    virtual void printInfo() const;

    virtual int getType() const;

    virtual string getTypeString() const;
};


#endif //COLLABORATION_VIPCUSTOMER_H
