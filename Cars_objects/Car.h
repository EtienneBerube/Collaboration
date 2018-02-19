//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_CAR_H
#define COLLABORATION_CAR_H

#include <string>
#include "../Customer_Objects/Customer.h"

using std::string;

class Car {

protected:

    int idNum;
    string type;
    bool availability;

public:
    Car();

    Car(int, int, bool);

    Car(const Car &);

    //Will be used to denote whether the cars are regular or luxury
    static const int Luxury = 1;
    static const int Standard = 0;

    int getIdNum() const;

    void setIdNum(int idNum);

    virtual const string &getType() const = 0;

    void setType(const string &type);

    bool isAvailable() const;

    void setAvailability(bool availability);

    virtual //The destructor
    ~Car();

    //An object of customer in the class car to be able to better keep track of info
    Customer * aCustomer;

    //making the class Car Abstract
    virtual void f()=0;

};


#endif //COLLABORATION_CAR_H
