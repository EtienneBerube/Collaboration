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
#include <iomanip>

using namespace std;


//********************************Function Declarations******************************

void menu();

void addCustomer();

void addCar();

void removeCar();

void removeCustomer();

int searchCustomer(int);

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

vector<Car*> listCar;
vector<Customer*> listCustomer;
int currentMaxRegular = 20;
int currentMaxCorporate = 35;
int currentMaxVIP = 45;

//********************************Functions definition******************************

int main() {

    //Need to fill vectors with already existing accounts

    cout << "***********************************************************" << endl;
    cout << "||                                                       ||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "||                  CAR RENTAL SYSTEM                    ||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "||                         BY                            ||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "||                   VROOM VROOM inc.                    ||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "***********************************************************" << endl;


    menu();


    return 0;
}

void menu() {
    cout << "in" << endl; //Debugging
    //Need exit option options with a way to delete pointers in vector.

}

//Function which adds a new customer
void addCustomer() {
    int choice;
    string name;
    string telephoneNumber;
    string address;
    string companyAddress;
    string companyName;

    cout << "Enter customer type:\n1)Regular\n2)Corporate\n3)VIP" << endl;
    cin >> choice;

    //Making sure the user enters a number between 1 and 3 only
    while (choice < 1 || choice > 3) {
        cout << "Invalid input, try again: ";
        cin >> choice;
    }

    //Getting the data
    cin.ignore();
    cout << "Enter full name: ";
    getline(cin, name);


    cin.ignore();
    cout << "Enter address: ";
    getline(cin, address);


    cin.ignore();
    cout << "Enter telephone number: ";
    getline(cin, telephoneNumber);

    if (choice == 2) {
        cin.ignore();
        cout << "Enter the company's name: ";
        getline(cin, companyName);

        cin.ignore();
        cout << "Enter company's address: ";
        getline(cin, companyAddress);
    }

    //Depending on the type of customer, the right constructor will be called
    switch (choice) {
        case 1:
            listCustomer.push_back(new RegularCustomer(findMaxIDCustomer() + 1, name, address, telephoneNumber, currentMaxRegular));
            break;
        case 2:
            listCustomer.push_back(new CorporateCustomer(findMaxIDCustomer() + 1, name, address, telephoneNumber, currentMaxCorporate, companyName, companyAddress));
            break;
        case 3:
            listCustomer.push_back( new VIPCustomer(findMaxIDCustomer() + 1, name, address, telephoneNumber, currentMaxVIP));
            break;
        default:
            cout << "Error occured" << endl;
            menu();
            break;
    }
    cout << "new customer created" << endl;
    menu();

}

//Function to add a new car
void addCar() {
    int choice = 0;
    string isAvailable;
    bool availability = true;

    //Title of this menu
    cout << "\nAdding new Car" << endl;
    cout << "\nSelect the type of car" << endl;
    cout << "\n1 - Luxury\n2 - Standard" << endl;

    cin.ignore();
    cin >> choice;

    //Making sure that they enter only 1 or 2
    while (choice < 1 || choice > 2) {
        cout << "\nSelect the type of car" << endl;
        cout << "\n1 - Luxury\n2 - Standard" << endl;
        cin.ignore();
        cin >> choice;
    }

    cout << "\nIs the car readily available:\ny\nn" << endl;
    cin.ignore();
    cin >> isAvailable;

    //Making sure that the customer only enters y or Y or n or N to know whether or not a new car is readily available
    while (isAvailable != "y" || isAvailable != "Y" || isAvailable != "n" || isAvailable != "N") {
        cout << "\nIs the car readily available:\ny\nn" << endl;
        cin.ignore();
        cin >> isAvailable;
    }

    if (isAvailable == "n" || isAvailable == "N") {
        availability = false;
    }

    //Depending on the type of car, the right constructor is called
    switch (choice) {
        case 1:
            //so that the ID is generated automatically
            listCar.push_back( new luxuryCar(findMaxIDCar()+1, availability));
            break;
        default:
            listCar.push_back( new regularCar(findMaxIDCar()+1, availability));
            break;
    }
    cout << "\nNew Car Added" << endl;
    cout << "\nReturning back to menu" << endl;
}

//function which removes a car
void removeCar() {
    int theID, theIndex = 0;
    //Title of this menu
    cout << "\nRemoving Car" << endl;
    //Prints the ID of cars so that the user may quickly find out which ID of the car to delete
    printCarList();

    cout << "\nEnter the car's ID:" << endl;
    cin.ignore();
    cin >> theID;

    //Function which will return the index related to the car's ID
    theIndex = searchCar(theID);
    delete(listCar[theIndex]);
    listCar.erase(listCar.begin()+ theIndex);
    cout << "Deleting . . ." << endl;
    cout << "Returning back to menu" << endl;
    menu();

}

//function which removes a customer
void removeCustomer() {
    int delId;
    int delIndex;
    printCustomerList();
    cout << "Enter the id of the customer you want to delete: ";
    cin >> delId;

    delIndex = searchCustomer(delId);
    delete(listCar[delId]);
    listCustomer.erase(listCustomer.begin() + delIndex);
    cout << "Deleting . . . "<< endl;
    cout << "Returning back to menu " << endl;
    menu();
}

//returns index of Customer in array
int searchCustomer(int id) {
    int index = - 1;

    //For loop to go through the list of customer
    for (unsigned int i = 0; i < listCustomer.size(); ++ i) {
        //Checks if the ID are the same and if so,
        if (listCustomer[i]->getId() == id)
            //takes note of the index
            index = i;
    }
    //and returns the index
    return index;

}

//returns index of Car in array
int searchCar(int id) {
    int index = - 1;

    //Using a for loop to go through the vector of customers and looking for the ID
    for (unsigned int i = 0; i < listCar.size(); ++ i) {
        if (listCar[i]->getIdNum() == id)
            //checking if the ID matches
            index = i;
    }
    //Then returns the index where the ID is located in the vector
    return index;
}

//Function which changes the limit for regular customers
void changeDaysLimitRegular(int newMaxDays) {
    currentMaxRegular = newMaxDays;
    //Checks through the list of customer, if it is a regular customer then the limit is changed
    for (Customer *c : listCustomer) {
        if (c->getType() == Customer::REGULAR) {
            c->setMaxDays(newMaxDays);
        }
    }
}

//Function which changes the limit for VIP
void changeDaysLimitVIP(int newMaxDays) {
    currentMaxRegular = newMaxDays;
    //Goes through the vector of customers using a for loop
    for (Customer* c : listCustomer) {
        //Checks if the customer is VIP, if so then changes the limit
        if (c->getType() == Customer::VIP) {
            c->setMaxDays(newMaxDays);
        }
    }
}

//Function which changes the limit for Corporate customers
void changeDaysLimitCorporate(int newMaxDays) {
    currentMaxRegular = newMaxDays;
    //Goes through the list of customers, and looks
    for (Customer c : listCustomer) {
        if (c.getType() == Customer::CORPORATE) {
            c.setMaxDays(newMaxDays);

            for (Customer *c : listCustomer) {
                if (c->getType() == Customer::CORPORATE) {
                    c->setMaxDays(newMaxDays);
                }
            }
        }
    }
}

//Function which will update info about a car
void updateCarInfo(int id) {
    cout << "\nUpdating Car Info" << endl;
    int index = searchCar(id);
    if (index == - 1) {
        cout << "\nCar does not exist" << endl;
    } else {
        string yesOrNo;
        bool isItAvailable = true;
        cout << "Changing the availability" << endl;
        cout << "Is the car available: yes or no?" << endl;
        cin.ignore();
        cin >> yesOrNo;

        //Making sure that the customer only enters y or Y or n or N to know whether or not a new car is readily available
        while (yesOrNo != "y" || yesOrNo != "Y" || yesOrNo != "n" || yesOrNo != "N") {
            cout << "\nIs the car readily available:\ny\nn" << endl;
            cin.ignore();
            cin >> yesOrNo;
        }

        if (yesOrNo == "n" || yesOrNo == "N") {
            isItAvailable = false;
            int type;

        }
    }
}


//Function which updates the info of a customer
void updateUserInfo(int id) {
    int result = searchCustomer(id);
    if (result == - 1) {
        cout << "\nCustomer does not exist" << endl;
    } else {
        string name;
        string address;
        string phoneNumber;

        //Gather info
        cin.ignore();
        cout << "Enter the new full name: ";
        getline(cin, name);

        cin.ignore();
        cout << "Enter the new address: ";
        getline(cin, address);

        cin.ignore();
        cout << "Enter the new phone number: ";
        getline(cin, phoneNumber);

        //Updating the info
        listCustomer[result]->setName(name);
        listCustomer[result]->setAddress(address);
        listCustomer[result]->setTelephoneNumber(phoneNumber);
    }
}

void rentCar() {

}

void returnCar() {

}

//Function which prints all the cars
void printCarList() {
    cout << "Type" << setw(10) << "id";
    //Use a for loop to print the car types and their ID
    for (Car* c : listCar) {
        cout << c->getType() << " (" << c->getIdNum() << ")" << endl;
    }
}

//Function which prints the name of all customers
void printCustomerList() {
    cout << "Name" << setw(10) << "id";
    //Uses a for loop to go through the vector of customers and prints them
    for (Customer* c : listCustomer) {
        cout << c->getName() << " (" << c->getId() << ")" << endl;
    }
}

void printCarListForCompany(const string &name) {
    cout << "Type" << setw(10) << "id";
    //TODO double loop into customer then car O(n^2)
}

// so as to get the latest ID for a car
int findMaxIDCar() {
    int max = 0;
    for (unsigned int i = 0; i < listCustomer.size(); ++ i) {
        if (max < listCustomer[i]->getId())
            max = listCustomer[i]->getId();
    }
    return max;
}

//Finding the latest, bigggest ID for a customer
int findMaxIDCustomer() {
    int max = 0;
    for (unsigned int i = 0; i < listCar.size(); ++ i) {
        if (max < listCar[i]->getIdNum())
            max = listCar[i]->getIdNum();
    }
    return max;
}





