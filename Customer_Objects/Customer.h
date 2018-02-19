//
// Created by Dean Chong San on 2018-02-19.
//

#ifndef COLLABORATION_CUSTOMER_H
#define COLLABORATION_CUSTOMER_H

#include <string>
#include "../Cars_objects/Car.h"

using std::string;

class Customer {

public :

    Customer(const Customer &customer);

    Customer();

    Customer(int _id, string _name, string _address, string _telephoneNumber);

    ~Customer();

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getTelephoneNumber() const;

    void setTelephoneNumber(const string &telephoneNumber);

    Car *getRental() const;

    virtual void setRental(Car *rental);

    virtual int getMaxDaysRental() = 0;

private:
    int id;
    Car *rental = nullptr;
    string name;
    string address;
    string telephoneNumber;

};


#endif //COLLABORATION_CUSTOMER_H
