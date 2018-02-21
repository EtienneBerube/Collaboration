//
// Created by Dean Chong San on 2018-02-19.
//


#include "luxuryCar.h"

luxuryCar::luxuryCar() {

}

luxuryCar::luxuryCar(int theID, bool theAvailability) : Car( theID, Car::Luxury,theAvailability ){
}

const string luxuryCar::getType() const {
    return "Luxury";
}

luxuryCar::~luxuryCar() = default;
