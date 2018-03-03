//
// Created by Etienne on 02/03/2018.
//

#ifndef COLLABORATION_CARRENTALSYSTEM_H
#define COLLABORATION_CARRENTALSYSTEM_H



#include "Customer_Objects/Customer.h"
#include "Cars_objects/luxuryCar.h"
#include "Cars_objects/regularCar.h"
#include "Customer_Objects/RegularCustomer.h"
#include "Customer_Objects/VIPCustomer.h"
#include "Customer_Objects/CorporateCustomer.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Assumptions:
 * - A Customer can only rent ONE car at the time
 * - To compare customers of the same company, the user will enter the name of a com
 * pany first
 *
 */


class CarRentalSystem {
public:
    void start();
    CarRentalSystem();

private:
    vector<Car *> listCar;
    vector<Customer *> listCustomer;
    int currentMaxRegular = 20;
    int currentMaxCorporate = 35;
    int currentMaxVIP = 45;

    //**********************************Function declaration***********************************
    void endProgram();

    void menu();

    void addCustomer();

    void addCar();

    void removeCar(int theID);

    void removeCustomer(int delId);

    int searchCustomer(int);

    int searchCar(int id);

    void changeDaysLimitRegular(int newMaxDays);

    void changeDaysLimitVIP(int newMaxDays);

    void changeDaysLimitCorporate(int newMaxDays);

    void updateCarInfo(int id);

    void updateUserInfo(int id);

    void rentCar(Customer *customer, Car *car);

    void returnCar(Customer *index);

    void printCarList();

    void printCustomerList();

    void printCarListForCompany(const string &);

    int findMaxIDCar();

    int findMaxIDCustomer();

    void printPriviledges();

    void initialize();
};

#endif //COLLABORATION_CARRENTALSYSTEM_H
