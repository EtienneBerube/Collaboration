//
// Created by Dean Chong San on 2018-02-19.
//


#include "regularCar.h"

regularCar::regularCar() {
Car();
}

regularCar::regularCar(int theID, bool theAvailability) : Car(theID, Car::Standard, theAvailability){
}
