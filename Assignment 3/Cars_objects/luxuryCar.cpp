//
// Created by Dean Chong San on 2018-02-19.
//


#include "luxuryCar.h"

//Default constructor
luxuryCar::luxuryCar()= default;

//Regular constructor
luxuryCar::luxuryCar(int theID, bool theAvailability) : Car( theID, Car::Luxury,theAvailability ){
}

//Getter
const string luxuryCar::getType() const {
    return "Luxury";
}

//Destructor
luxuryCar::~luxuryCar() = default;
