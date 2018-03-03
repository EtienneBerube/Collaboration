//
// Created by Etienne on 19/02/2018.
//

#include "Car.h"

//Setters and getters
int Car::getIdNum() const {
    return idNum;
}

void Car::setIdNum(int idNum) {
    Car::idNum = idNum;
}

void Car::setType(const string &type) {
    Car::type = type;
}

const string Car::getType() const {
    return type;
}

bool Car::isAvailable() const {
    return availability;
}

void Car::setAvailability(bool availability) {
    Car::availability = availability;
}

//Default constructor
Car::Car() {
    idNum = 0;
    type = "";
    availability = true;
}

//Main constructor
Car::Car(int theID, int theType, bool theAvailability) {

    idNum = theID;
    availability = theAvailability;
    //Depending on the number, the car might be regular or luxurious
    switch (theType) {
        case 1:
            type = "Luxury";
            break;
        default:
            type = "Standard";
            break;
    }

}

//Copy constructor
Car::Car(const Car &theCar) {

    idNum = theCar.getIdNum();
    availability = theCar.isAvailable();
    type = theCar.getType();

}

//Destructor
Car::~Car() = default;


