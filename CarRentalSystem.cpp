//
// Created by Etienne on 19/02/2018.
//


#include "Customer_Objects/Customer.h"
#include "Cars_objects/luxuryCar.h"
#include "Cars_objects/regularCar.h"
#include "Customer_Objects/RegularCustomer.h"
#include "Customer_Objects/VIPCustomer.h"
#include "Customer_Objects/CorporateCustomer.h"
#include <vector>
#include <iostream>
#include "windows.h"

using namespace std;


//********************************Function Declarations******************************

void menu();
void addCustomer();
void addCar();
void removeCar();
void removeCustomer();
int searchCustomer();
int searchCar();
void changeDaysLimitRegular();
void changeDaysLimitVIP();
void changeDaysLimitCorporate();
void updateCarInfo();
void updateUserInfo();
void rentCar();
void returnCar();
void printCarList();
void printCustomerList();
void printCarListForCompany();

//********************************Global Variables*********************************

vector<Car> listCar;
vector<Customer> listCustomer;

//********************************Functions definition******************************

int main(){
    cout<<"***********************************************************"<<endl;
    cout<<"||                                                       ||"<<endl;
    cout<<"||                                                       ||"<<endl;
    cout<<"||                  CAR RENTAL SYSTEM                    ||"<<endl;
    cout<<"||                                                       ||"<<endl;
    cout<<"||                         BY                            ||"<<endl;
    cout<<"||                                                       ||"<<endl;
    cout<<"||                   VROOM VROOM inc.                    ||"<<endl;
    cout<<"||                                                       ||"<<endl;
    cout<<"||                                                       ||"<<endl;
    cout<<"***********************************************************"<<endl;


    Sleep(1500);

    menu();


    return 69;
}

void menu() {

}

void addCustomer() {

}

void addCar() {

}

void removeCar() {

}
//returns index of Customer in array
int searchCustomer() {

}
//returns index of Car in array
int searchCar() {

}

void changeDaysLimitRegular() {

}

void changeDaysLimitVIP() {

}

void changeDaysLimitCorporate() {

}

void updateCarInfo() {}

void updateUserInfo() {}

void rentCar() {

}

void returnCar() {
}

void printCarList() {

}

void printCustomerList() {}

void printCarListForCompany() {

}

void removeCustomer() {

}





