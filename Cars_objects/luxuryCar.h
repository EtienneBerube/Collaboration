//
// Created by Dean Chong San on 2018-02-19.
//

#ifndef COLLABORATION_LUXURYCAR_H
#define COLLABORATION_LUXURYCAR_H

#include "Car.h"

class luxuryCar : public Car {

public:
    luxuryCar();
    luxuryCar(int, bool);
    ~luxuryCar();

    const string getType() const override;

};


#endif //COLLABORATION_LUXURYCAR_H
