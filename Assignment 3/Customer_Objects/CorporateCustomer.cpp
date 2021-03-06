//
// Created by Etienne on 19/02/2018.
//

#include "CorporateCustomer.h"
#include <iostream>

//Default constructor
CorporateCustomer::CorporateCustomer() = default;

//Regular constructor
CorporateCustomer::CorporateCustomer(int _id, string _name, string _address, string _telephoneNumber,int _maxDays,string _companyName, string _companyPhoneNumber): Customer(_id, _name, _address, _telephoneNumber, Customer::CORPORATE, _maxDays), companyName(_companyName), companyAddress(_companyPhoneNumber) {
}

//Copy constructor
CorporateCustomer::CorporateCustomer(const CorporateCustomer &corporateCustomer) {
    companyName = corporateCustomer.getCompanyName();
    companyAddress = corporateCustomer.getCompanyPhoneNumber();

}

//Getter
const string &CorporateCustomer::getCompanyName() const {
    return companyName;
}

//Setter
void CorporateCustomer::setCompanyName(const string &companyName) {
    CorporateCustomer::companyName = companyName;
}

//Getter
const string &CorporateCustomer::getCompanyPhoneNumber() const {
    return companyAddress;
}

//Setter
void CorporateCustomer::setCompanyPhoneNumber(const string &companyPhoneNumber) {
    CorporateCustomer::companyAddress = companyPhoneNumber;
}

//Getter
int CorporateCustomer::getType() const {
    return Customer::CORPORATE;
}

//Getter
string CorporateCustomer::getTypeString() const{
    return "Corporate";
}

//Function which was pure virtual is now implemented here
void CorporateCustomer::printInfo() const {
    std::cout <<"ID: "<< getId() << "\nType: " << getTypeString() <<"\nName: " << getName() <<"\nAddress: " << getAddress() <<"\nPhone number: " << getTelephoneNumber()
              << "\nCompany Name: " << companyName << "\nCompany address: " << companyAddress <<std::flush;
}





