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
#include <iomanip>

using namespace std;


//********************************Function Declarations******************************

void menu();
void addCustomer();
void addCar();
void removeCar();
void removeCustomer();
int searchCustomer();
int searchCar(int id);
void changeDaysLimitRegular(int newMaxDays);
void changeDaysLimitVIP(int newMaxDays);
void changeDaysLimitCorporate(int newMaxDays);
void updateCarInfo(int id);
void updateUserInfo(int id);
void rentCar();
void returnCar();
void printCarList();
void printCustomerList();
void printCarListForCompany();
int findMaxIDCar();
int findMaxIDCustomer();

//********************************Global Variables*********************************

vector<Car> listCar;
vector<Customer> listCustomer;
int currentMaxRegular = 20;
int currentMaxCorporate = 35;
int currentMaxVIP = 45;

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


    return 0;
}

void menu() {
    cout<<"in"<<endl; //Debugging
    exit(0);
}

void addCustomer() {
    int choice;
    string name;
    string telephoneNumber;
    string address;
    string companyAddress;
    string companyName;

    cout<<"Enter customer type:\n1)Regular\n2)Corporate\n3)VIP"<<endl;
    cin >> choice;

    while(choice <1 || choice > 3){
        cout<< "Invalid input, try again: ";
        cin >> choice;
    }

    cin.ignore();
    cout << "Enter full name: ";
    getline(cin, name);


    cin.ignore();
    cout << "Enter address: ";
    getline(cin, address);


    cin.ignore();
    cout << "Enter telephone number: ";
    getline(cin, telephoneNumber);

    if(choice == 2){
        cin.ignore();
        cout << "Enter the company's name: ";
        getline(cin, companyName);

        cin.ignore();
        cout << "Enter company's address: ";
        getline(cin, companyAddress);
    }

    switch(choice){
        case 1: listCustomer.push_back( RegularCustomer(findMaxIDCustomer()+1, name, address, telephoneNumber, currentMaxRegular)); break;
        case 2: listCustomer.push_back( CorporateCustomer(findMaxIDCustomer()+1, name, address, telephoneNumber, currentMaxCorporate, companyName, companyAddress)); break;
        case 3: listCustomer.push_back( VIPCustomer(findMaxIDCustomer()+1, name, address, telephoneNumber, currentMaxVIP)); break;
        default:cout<<"Error occured"<<endl; menu(); break;
    }
    cout<<"new customer created"<<endl;
    menu();

}

void addCar() {

}

void removeCar() {

}

void removeCustomer(){
    int delId;
    int delIndex;
    printCustomerList();
    cout<<"Enter the id of the customer you want to delete: ";
    cin >> delId;

    delIndex = searchCustomer(delId);

    listCustomer.erase(listCustomer.begin() + delIndex);


}

//returns index of Customer in array
int searchCustomer(int id) {
    int index = -1;
    for(unsigned int i = 0; i < listCustomer.size(); ++i){
        if(listCustomer[i].getId() == id)
            index = i;
    }
    return index;

}
//returns index of Car in array
int searchCar(int id) {
    int index = -1;
    for(unsigned int i = 0; i < listCar.size(); ++i){
        if(listCar[i].getIdNum() == id)
            index = i;
    }
    return index;
}

void changeDaysLimitRegular(int newMaxDays) {
    currentMaxRegular = newMaxDays;
    for(Customer c : listCustomer){
        if(c.getType() == Customer::REGULAR){
            c.setMaxDays(newMaxDays);
        }
    }
}

void changeDaysLimitVIP(int newMaxDays) {
    currentMaxRegular = newMaxDays;
    for(Customer c : listCustomer){
        if(c.getType() == Customer::VIP){
            c.setMaxDays(newMaxDays);
        }
    }
}

void changeDaysLimitCorporate(int newMaxDays) {
    currentMaxRegular = newMaxDays;
    for(Customer c : listCustomer){
        if(c.getType() == Customer::CORPORATE){
            c.setMaxDays(newMaxDays);
        }
    }
}

void updateCarInfo(int id) {}

void updateUserInfo(int id) {
    int result = searchCustomer(id);
    if(result == -1){
        cout << "Customer does not exist"<<endl;
    }else{
        string name;
        string address;
        string phoneNumber;

        cin.ignore();
        cout<< "Enter the new full name: ";
        getline(cin, name);

        cin.ignore();
        cout<< "Enter the new address: ";
        getline(cin, address);

        cin.ignore();
        cout<< "Enter the new phone number: ";
        getline(cin, phoneNumber);

        listCustomer[result].setName(name);
        listCustomer[result].setAddress(address);
        listCustomer[result].setTelephoneNumber(phoneNumber);
    }
}

void rentCar() {

}

void returnCar() {

}

void printCarList() {
    cout<<"Type"<<setw(10)<<"id";
    for(Car c : listCar){
        cout << c.getType() << " (" << c.getIdNum() <<")"<<endl;
    }
}

void printCustomerList(){
    cout<<"Name"<<setw(10)<<"id";
    for(Customer c : listCustomer){
        cout << c.getName() << " (" << c.getId() <<")"<<endl;
    }
}

void printCarListForCompany(const string &name){
    cout<<"Type"<<setw(10)<<"id";
    //TODO double loop into customer then car O(n^2)
}

int findMaxIDCar() {
    int max = 0;
    for(unsigned int i = 0; i < listCustomer.size(); ++i ){
        if(max < listCustomer[i].getId())
            max = listCustomer[i].getId();
    }
    return max;
}

int findMaxIDCustomer() {
    int max = 0;
    for(unsigned int i = 0; i < listCar.size(); ++i ){
        if(max < listCar[i].getIdNum())
            max = listCar[i].getIdNum();
    }
    return max;
}





