//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_REGULARCUSTOMER_H
#define COLLABORATION_REGULARCUSTOMER_H


#include "Customer.h"

class RegularCustomer: public Customer {
public:

    RegularCustomer();
    RegularCustomer(int _id, string _name, string _address, string _telephoneNumber, string companyName, string companyPhoneNumber);
    RegularCustomer(const RegularCustomer&);
    void addRental(Car *rental) override;

    int getType() const override;

    string getTypeString() override;

};


#endif //COLLABORATION_REGULARCUSTOMER_H
