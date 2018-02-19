//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_CAR_H
#define COLLABORATION_CAR_H

#include <string>
#include "Customer.h"

using std::string;

class Car {

protected:
    int idNum;
    string type;
    bool availability;

public:
    Car();

    Car(int, int, bool);

    //Will be used to denote whether the cars are regular or luxury
    static const int Luxury = 1;
    static const int Standard = 0;

    int getIdNum() const;

    void setIdNum(int idNum);

    const string &getType() const;

    void setType(const string &type);

    bool isAvailability() const;

    void setAvailability(bool availability);

    //The destructor
    ~Car();

};


#endif //COLLABORATION_CAR_H
