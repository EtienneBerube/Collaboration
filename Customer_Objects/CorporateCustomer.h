//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_CORPORATECUSTOMER_H
#define COLLABORATION_CORPORATECUSTOMER_H

#include <string>
#include "Customer.h"
//#include "../Cars_objects/Car.h"

class Car;

using std::string;

//Class derived from customer
class CorporateCustomer: public Customer {
public:
    //Default constructor
    CorporateCustomer();

    //Regular constructor
    CorporateCustomer(int _id, string _name, string _address, string _telephoneNumber,int _maxDays, string companyName, string companyAddress);

    //Copy constructor
    CorporateCustomer(const CorporateCustomer&);

<<<<<<< HEAD
    //Getter
    int getType() const override;

    //Getter
    string getTypeString() const override;
=======
    //Setters and Getters
    virtual int getType() const;

    virtual string getTypeString() const;
>>>>>>> 2ac025a2e5222a72dba6041ea2eb32ece05160f3

    //Getter
    const string &getCompanyName() const;

    //Setter
    void setCompanyName(const string &companyName);

    //Getter
    const string &getCompanyPhoneNumber() const;

    //Setter
    void setCompanyPhoneNumber(const string &companyPhoneNumber);

    //Function which is overriden from base class
    virtual void printInfo() const;

private:

    //Attributes to Corporate Customers only
    string companyName;
    string companyAddress;
};


#endif //COLLABORATION_CORPORATECUSTOMER_H
