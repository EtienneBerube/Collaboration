//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_REGULARCUSTOMER_H
#define COLLABORATION_REGULARCUSTOMER_H


#include "Customer.h"

class RegularCustomer: public Customer {

public:
//Default constructor
    RegularCustomer();

    //Regular constructor
    RegularCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays);

    //Copy constructor
    RegularCustomer(const RegularCustomer&);

    //Function which adds a car to a regular consumer
    void addRental(Car *rental) override;

    //getter
    int getType() const override;

    //Function which is pure virtual in base class
    void printInfo() const override;

    //Function which is pure virtual in base class
    string getTypeString() const override;

};


#endif //COLLABORATION_REGULARCUSTOMER_H
