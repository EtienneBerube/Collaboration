//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_CORPORATECUSTOMER_H
#define COLLABORATION_CORPORATECUSTOMER_H

#include <string>
#include "Customer.h"

using std::string;

class CorporateCustomer: public Customer {
public:
    CorporateCustomer();
    CorporateCustomer(int _id, string _name, string _address, string _telephoneNumber,int _maxDays, string companyName,
                      string companyAddress);
    CorporateCustomer(const CorporateCustomer&);

    int getType() const override;

    string getTypeString() const override;

    const string &getCompanyName() const;

    void setCompanyName(const string &companyName);

    const string &getCompanyPhoneNumber() const;

    void setCompanyPhoneNumber(const string &companyPhoneNumber);

    void printInfo() const override;

private:
    string companyName;
    string companyAddress;
};


#endif //COLLABORATION_CORPORATECUSTOMER_H
