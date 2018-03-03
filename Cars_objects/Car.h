//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_CAR_H
#define COLLABORATION_CAR_H

#include <string>
/*
#include "../Customer_Objects/Customer.h"
#include "../Customer_Objects/CorporateCustomer.h"
#include "../Customer_Objects/VIPCustomer.h"
#include "../Customer_Objects/RegularCustomer.h"
 */


using std::string;

class Customer; //Forward declaration

class Car {

protected:
    //the attributes
    int idNum;
    string type;
    bool availability;

public:
    //Will be used to denote whether the cars are regular or luxury
    static const int Luxury = 1;
    static const int Standard = 0;

    //Default constructor
    Car();

    //Regular constructor
    Car(int, int, bool);

    //copy constructors
    Car(const Car &);

    //Getter
    int getIdNum() const;

    //Setter
    void setIdNum(int idNum);

    //Pure virtual function which makes the class abstract
    virtual const string getType() const = 0;

    //setter
    void setType(const int &type);

    //getter
    bool isAvailable() const;

    //setter
    void setAvailability(bool availability);

    //Destructor
    virtual ~Car();





};


#endif //COLLABORATION_CAR_H
