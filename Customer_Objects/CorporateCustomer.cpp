//
// Created by Etienne on 19/02/2018.
//

#include "CorporateCustomer.h"

int CorporateCustomer::getMaxDaysRental() {
    return 35;
}

CorporateCustomer::CorporateCustomer() = default;

CorporateCustomer::CorporateCustomer(int _id, string _name, string _address, string _telephoneNumber,
                                     string _companyName, string _companyPhoneNumber): Customer(_id, _name, _address, _telephoneNumber, Customer::CORPORATE),
                                                                                       companyName(_companyName), companyPhoneNumber(_companyPhoneNumber) {

}

CorporateCustomer::CorporateCustomer(const CorporateCustomer &corporateCustomer) {
    companyName = corporateCustomer.getCompanyName();
    companyPhoneNumber = corporateCustomer.getCompanyPhoneNumber();

}

const string &CorporateCustomer::getCompanyName() const {
    return companyName;
}

void CorporateCustomer::setCompanyName(const string &companyName) {
    CorporateCustomer::companyName = companyName;
}

const string &CorporateCustomer::getCompanyPhoneNumber() const {
    return companyPhoneNumber;
}

void CorporateCustomer::setCompanyPhoneNumber(const string &companyPhoneNumber) {
    CorporateCustomer::companyPhoneNumber = companyPhoneNumber;
}
