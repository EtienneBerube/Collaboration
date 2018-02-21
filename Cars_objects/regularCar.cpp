//
// Created by Dean Chong San on 2018-02-19.
//



#include "regularCar.h"

regularCar::regularCar() = default;

regularCar::regularCar(int theID, bool theAvailability) : Car(theID, Car::Standard, theAvailability){
}

regularCar::regularCar(int _id, int _type, bool _isAvailable) : Car(_id, _type, _isAvailable) {

}

const string regularCar::getType() const {
    return "Regular";
}


