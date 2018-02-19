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
    static const int REGULAR = 0;
    static const int CORPORATE = 1;
    static const int VIP = 2;

    Customer(const Customer &customer);

    Customer();

    Customer(int _id, string _name, string _address, string _telephoneNumber, int _type);

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

    virtual void addRental(Car *rental);

    void removeRental();

    virtual int getType() const = 0;

    void setType(int type);

    virtual int getMaxDaysRental() = 0;

private:
    int id;
    int type;
    Car *rental = nullptr;
    string name;
    string address;
    string telephoneNumber;

};


#endif //COLLABORATION_CUSTOMER_H
