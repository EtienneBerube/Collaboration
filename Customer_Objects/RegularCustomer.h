//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_REGULARCUSTOMER_H
#define COLLABORATION_REGULARCUSTOMER_H


#include "Customer.h"

class RegularCustomer: public Customer {
public:

    RegularCustomer();
    RegularCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays);
    RegularCustomer(const RegularCustomer&);
    void addRental(Car *rental) override;

    int getType() const override;

    void printInfo() const override;

    string getTypeString() const override;

};


#endif //COLLABORATION_REGULARCUSTOMER_H
