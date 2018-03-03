//
// Created by Dean Chong San on 2018-02-19.
//

#ifndef COLLABORATION_LUXURYCAR_H
#define COLLABORATION_LUXURYCAR_H

#include "Car.h"

//Class derived from base class car
class luxuryCar : public Car {

public:

    //constructors
    luxuryCar();
    luxuryCar(int, bool);

    //Destructors
    ~luxuryCar();

    //Getter which has to be overriden from the base class since it is pure virtual there
    const string getType() const override;

};


#endif //COLLABORATION_LUXURYCAR_H
