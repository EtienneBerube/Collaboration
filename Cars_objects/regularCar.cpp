//
// Created by Dean Chong San on 2018-02-19.
//

#include <altivec.h>
#include "regularCar.h"

regularCar::regularCar() {
Car();
}

regularCar::regularCar(int theID, int theType, bool theAvailability) : Car(theID, theType, theAvailability){
}
