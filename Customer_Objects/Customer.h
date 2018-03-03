//
// Created by Dean Chong San on 2018-02-19.
//

#ifndef COLLABORATION_CUSTOMER_H
#define COLLABORATION_CUSTOMER_H

#include <string>
#include "../Cars_objects/Car.h"

using std::string;

class Car; //forward declaration

class Customer {

public :
    //static int variables to easily distinguish the types of customers
    static const int REGULAR = 0;
    static const int CORPORATE = 1;
    static const int VIP = 2;

    //Copy constructor
    Customer(const Customer &customer);

    //Default constructor
    Customer();

    //Regular constructor
    Customer(int _id, string _name, string _address, string _telephoneNumber, int _type, int _maxDays);

    //Destructor
    ~Customer();

    //Setters and getters
    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getTelephoneNumber() const;

    void setTelephoneNumber(const string &telephoneNumber);

    //Functions which returns the car
    Car *getRental() const;

    //Function which adds the car rented by the customer to the customer
    virtual void addRental(Car *rental);

    //Removes the car rented by the customer
    void removeRental();

    //Pure virtual function to force derived classes to implement it
    virtual int getType() const = 0;

    //Pure virtual function to force derived classes to implement it
    virtual string getTypeString() const = 0;

    //Getter
    int getMaxDaysRental();

    void setMaxDays(int num);

    //Another pure virtual function
    virtual void printInfo() const = 0;

private:

    //The attributes of a customer
    int id;
    int type;
    int maxDays;
    //To keep the car associated to a customer for better management
    Car *rental = nullptr;
    string name;
    string address;
    string telephoneNumber;
};


#endif //COLLABORATION_CUSTOMER_H
