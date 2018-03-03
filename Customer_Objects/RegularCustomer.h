//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_REGULARCUSTOMER_H
#define COLLABORATION_REGULARCUSTOMER_H

class Car;

#include "Customer.h"

class RegularCustomer: public Customer {

public:
//Default constructor
    RegularCustomer();

    //Regular constructor
    RegularCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays);

    //Copy constructor
    RegularCustomer(const RegularCustomer&);

    virtual void addRental(Car *rental);

    virtual int getType() const;

    virtual void printInfo() const;

    virtual string getTypeString() const;


};


#endif //COLLABORATION_REGULARCUSTOMER_H
