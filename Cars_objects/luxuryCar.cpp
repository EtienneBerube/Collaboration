//
// Created by Dean Chong San on 2018-02-19.
//

#include <altivec.h>
#include "luxuryCar.h"

luxuryCar::luxuryCar() {
    Car();
}

luxuryCar::luxuryCar(int theID, int theType, bool theAvailability) : Car( theID,theType,theAvailability ){
}
