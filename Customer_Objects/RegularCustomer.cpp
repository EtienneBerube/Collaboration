//
// Created by Etienne on 19/02/2018.
//

#include <iostream>
#include "RegularCustomer.h"

RegularCustomer::RegularCustomer() = default;

RegularCustomer::RegularCustomer(int _id, string _name, string _address, string _telephoneNumber, string _companyName,
                                 string _companyPhoneNumber): Customer(_id, _name, _address, _telephoneNumber, Customer::REGULAR) {}

RegularCustomer::RegularCustomer(const RegularCustomer &regCustomer) {}


void RegularCustomer::addRental(Car *rental) {
    if(rental->getType() == "Luxury"){//TODO check if ok
        std::cout<<"Cannot rent this kind of car"<<std::flush;
    } else{
        Customer::addRental(rental);
    }

}

int RegularCustomer::getType() const {
    return Customer::REGULAR;
}

string RegularCustomer::getTypeString() {
    return "Regular";
}
