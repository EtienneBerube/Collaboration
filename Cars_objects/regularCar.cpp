//
// Created by Dean Chong San on 2018-02-19.
//



#include "regularCar.h"

//The default constructor
regularCar::regularCar() = default;

//The regular constructor
regularCar::regularCar(int theID, bool theAvailability) : Car(theID, Car::Standard, theAvailability){
}

//Another regular constructor
regularCar::regularCar(int _id, int _type, bool _isAvailable) : Car(_id, _type, _isAvailable) {

}

//Getter
const string regularCar::getType() const {
    return "Regular";
}


