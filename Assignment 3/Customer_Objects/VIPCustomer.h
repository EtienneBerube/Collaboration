//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_VIPCUSTOMER_H
#define COLLABORATION_VIPCUSTOMER_H


#include "Customer.h"
#include <string>

using std::string;

//Derived class from customer
class VIPCustomer: public Customer {

public:
    //Defaut constructor
    VIPCustomer();
    //Regular constructor
    VIPCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays);
    //Copy constructor
    VIPCustomer(const VIPCustomer&);

    //virtual function which prints info
    virtual void printInfo() const;

    //virtual function which returns the type of customer
    virtual int getType() const;

    //Virtual function which returns type in string
    virtual string getTypeString() const;

};


#endif //COLLABORATION_VIPCUSTOMER_H
