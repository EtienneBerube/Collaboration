//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_CORPORATECUSTOMER_H
#define COLLABORATION_CORPORATECUSTOMER_H

#include <string>
#include "Customer.h"

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

    //Setters and Getters
    int getType() const override;

    string getTypeString() const override;

    const string &getCompanyName() const;

    void setCompanyName(const string &companyName);

    const string &getCompanyPhoneNumber() const;

    void setCompanyPhoneNumber(const string &companyPhoneNumber);

    //Function which is overriden from base class
    void printInfo() const override;

private:

    //Attributes to Corporate Customers only
    string companyName;
    string companyAddress;
};


#endif //COLLABORATION_CORPORATECUSTOMER_H
