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

    //Function which adds the car which is to be rented
    virtual void addRental(Car *rental);

    //Function which returns the type as an integer
    virtual int getType() const;

    //function which prints info
    virtual void printInfo() const;

    //Function which returns the type as a string
    virtual string getTypeString() const;


};


#endif //COLLABORATION_REGULARCUSTOMER_H
