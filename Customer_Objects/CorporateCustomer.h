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
    CorporateCustomer(int _id, string _name, string _address, string _telephoneNumber, string companyName, string companyPhoneNumber);
    CorporateCustomer(const CorporateCustomer&);

    int getMaxDaysRental() override;

    const string &getCompanyName() const;

    void setCompanyName(const string &companyName);

    const string &getCompanyPhoneNumber() const;

    void setCompanyPhoneNumber(const string &companyPhoneNumber);

private:
    string companyName;
    string companyPhoneNumber;
};


#endif //COLLABORATION_CORPORATECUSTOMER_H
