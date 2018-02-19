//
// Created by Etienne on 19/02/2018.
//

#ifndef COLLABORATION_VIPCUSTOMER_H
#define COLLABORATION_VIPCUSTOMER_H


#include "Customer.h"

class VIPCustomer: public Customer {
public:
    VIPCustomer() {}

    int getMaxDaysRental() override;

};


#endif //COLLABORATION_VIPCUSTOMER_H
