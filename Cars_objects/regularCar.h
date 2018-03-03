//
// Created by Dean Chong San on 2018-02-19.
//

#ifndef COLLABORATION_REGULARCAR_H
#define COLLABORATION_REGULARCAR_H

#include "Car.h"

//Class derived from base class of car
class regularCar : public  Car{

public:

    //Defaut constructor
    regularCar();

    //Regular constructor
    regularCar(int theID, bool theAvailability);

    //Destructors
    ~regularCar() override = default;

    //Getter for the type of car
    const string getType() const override;

};


#endif //COLLABORATION_REGULARCAR_H
