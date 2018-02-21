//
// Created by Dean Chong San on 2018-02-19.
//

#ifndef COLLABORATION_REGULARCAR_H
#define COLLABORATION_REGULARCAR_H

#include "Car.h"

class regularCar : public  Car{

public:
    regularCar();

    regularCar(int _id, int _type, bool _isAvailable);

    regularCar(int theID, bool theAvailability);

    ~regularCar() override = default;

    const string getType() const override;

};


#endif //COLLABORATION_REGULARCAR_H
