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
class CorporateCustomer : public Customer {
public:
    //Default constructor
    CorporateCustomer();

    //Regular constructor
    CorporateCustomer(int _id, string _name, string _address, string _telephoneNumber, int _maxDays, string companyName,
                      string companyAddress);

    //Copy constructor
    CorporateCustomer(const CorporateCustomer &);

    //Getter
//int getType() const override;

    //Getter

    //Setters and Getters
    virtual int getType() const;

    //Function which returns type as a string
    virtual string getTypeString() const;

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
