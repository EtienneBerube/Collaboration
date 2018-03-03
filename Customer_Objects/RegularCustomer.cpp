//
// Created by Etienne on 19/02/2018.
//

#include <iostream>
#include "RegularCustomer.h"

//The default constructor
RegularCustomer::RegularCustomer() = default;

//Regular constructor
RegularCustomer::RegularCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays)
        : Customer(_id, _name, _address, _telephoneNumber, Customer::REGULAR, _maxDays) {}

//Copy constructor
RegularCustomer::RegularCustomer(const RegularCustomer &regCustomer) {}

//Function which adds a new rented car to a regular customer
void RegularCustomer::addRental(Car *rental) {
    //Checks if a luxury car is to be added
    if (rental->getType() == "Luxury") {//TODO check if ok
        //Regular customer cannot rent luxury cars
        std::cout << "Cannot rent this kind of car" << std::flush;
    }
        //If the car is not a luxury car, then it is added to the regular customer
    else {
        Customer::addRental(rental);
    }
}

//Getter
int RegularCustomer::getType() const {
    return Customer::REGULAR;
}

//Getter
string RegularCustomer::getTypeString() const {
    return "Regular";
}

//Function which is pure virtual in base class is now being implemented
void RegularCustomer::printInfo() const {
    std::cout << "ID: " << getId() << "\nType: " << getTypeString() << "\nName: " << getName() << "\nAddress: "
              << getAddress() << "\nPhone number: " << getTelephoneNumber() << std::flush;
}
