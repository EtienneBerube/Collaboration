//
// Created by Dean Chong San on 2018-02-19.
//

#include "Customer.h"

//The default constructor
Customer::Customer() = default;

//Regular constructor
Customer::Customer(int _id, string _name, string _address, string _telephoneNumber, int _type, int _maxDays) {
    id = _id;
    name = _name;
    address = _address;
    telephoneNumber = _telephoneNumber;
    type = _type;
    maxDays = _maxDays;
}

//Copy constructor
Customer::Customer(const Customer &customer){
    id = customer.getId();
    name = customer.getName();
    address = customer.getAddress();
    telephoneNumber = customer.getTelephoneNumber();
    rental = customer.getRental();
    type = customer.getType();
}

//Destructor
Customer::~Customer() = default;

//Setters and getters
int Customer::getId() const {
    return id;
}

void Customer::setId(int id) {
    Customer::id = id;
}

const string &Customer::getName() const {
    return name;
}

void Customer::setName(const string &name) {
    Customer::name = name;
}

const string &Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const string &address) {
    Customer::address = address;
}

const string &Customer::getTelephoneNumber() const {
    return telephoneNumber;
}

void Customer::setTelephoneNumber(const string &telephoneNumber) {
    Customer::telephoneNumber = telephoneNumber;
}

//Function which returns the car which was rented by the customer
Car *Customer::getRental() const {
    return rental;
}

//Function which adds a car rented to a customer
void Customer::addRental(Car *rental) {
    Customer::rental = rental;
    rental -> setAvailability(false);
}

//Function which removes a car rented by a customer because it was returned?
void Customer::removeRental() {
    rental->setAvailability(true);
    //Sets the pointed to nullptr as the car is no more
    rental = nullptr;
}

//Getter
int Customer::getMaxDaysRental() {
    return maxDays;
}

//Setter
void Customer::setMaxDays(int num){
    maxDays = num;
}


