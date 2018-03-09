//
// Created by Dean Chong San on 2018-02-19.
//



#include "regularCar.h"

//The default constructor
regularCar::regularCar() = default;

//The regular constructor
regularCar::regularCar(int theID, bool theAvailability) : Car(theID, Car::Standard, theAvailability){
}

//Getter
const string regularCar::getType() const {
    return "Regular";
}


