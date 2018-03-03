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



};



void CarRentalSystem::start() {

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

}

void CarRentalSystem::menu() {
    cout << "*************************Menu******************************"<<endl;
    cout << "1)Print Customer list"<<endl;
    cout << "2)Print Car list"<<endl;
    cout << "3)Add Customer"<<endl;
    cout << "4)Add Car"<<endl;
    cout << "5)Rent car"<<endl;
    cout << "6)Return car"<<endl;
    cout << "7)Print permissions per customer type"<<endl;
    cout << "8)Change maximum days a customer can rent" <<endl;
    cout << "9)Search Car"<<endl;
    cout << "10)Search Customer"<<endl;
    cout << "11)Print cars per company"<<endl;
    int choice = 0;
    cin >> choice;

    while(choice < 1 || choice > 11){
        cout<<"Invalid input, try again!"<<endl;
        cin >> choice;
    }
    switch (choice){
        case 1: printCustomerList();
            break;
        case 2: printCarList();
            break;
        case 3: addCustomer();
            break;
        case 4: addCar();
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        default: endProgram();
    }


}

//Function which adds a new customer
void CarRentalSystem::addCustomer() {
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
            listCustomer.push_back(
                    new RegularCustomer(findMaxIDCustomer() + 1, name, address, telephoneNumber, currentMaxRegular));
            break;
        case 2:
            listCustomer.push_back(
                    new CorporateCustomer(findMaxIDCustomer() + 1, name, address, telephoneNumber, currentMaxCorporate,
                                          companyName, companyAddress));
            break;
        case 3:
            listCustomer.push_back(
                    new VIPCustomer(findMaxIDCustomer() + 1, name, address, telephoneNumber, currentMaxVIP));
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
void CarRentalSystem::addCar() {
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
            listCar.push_back(new luxuryCar(findMaxIDCar() + 1, availability));
            break;
        default:
            listCar.push_back(new regularCar(findMaxIDCar() + 1, availability));
            break;
    }
    cout << "\nNew Car Added" << endl;
    cout << "\nReturning back to menu" << endl;
}

//function which removes a car
void CarRentalSystem::removeCar(int theID) {
    /*int theID, theIndex = 0;
    //Title of this menu
    cout << "\nRemoving Car" << endl;
    //Prints the ID of cars so that the user may quickly find out which ID of the car to delete
    printCarList();

    cout << "\nEnter the car's ID:" << endl;
    cin.ignore();
    cin >> theID;
    */

    //TODO to be put in actual menu
    //Function which will return the index related to the car's ID
    int theIndex = searchCar(theID);
    delete (listCar[theIndex]);
    listCar.erase(listCar.begin() + theIndex);
    cout << "Deleting . . ." << endl;
    cout << "Returning back to menu" << endl;
    menu();

}

//function which removes a customer
void CarRentalSystem::removeCustomer(int delId) {
    /*
    int delIndex;
    printCustomerList();
    cout << "Enter the id of the customer you want to delete: ";
    cin >> delId;
    */
    //TODO to be put in menu
    int delIndex = searchCustomer(delId);
    delete (listCar[delId]);
    listCustomer.erase(listCustomer.begin() + delIndex);
    cout << "Deleting . . . " << endl;
    cout << "Returning back to menu " << endl;
    menu();
}

//returns index of Customer in array
int CarRentalSystem::searchCustomer(int id) {
    int index = -1;

    //For loop to go through the list of customer
    for (unsigned int i = 0; i < listCustomer.size(); ++i) {
        //Checks if the ID are the same and if so,
        if (listCustomer[i]->getId() == id)
            //takes note of the index
            index = i;
    }
    //and returns the index
    return index;

}

//returns index of Car in array
int CarRentalSystem::searchCar(int id) {
    int index = -1;

    //Using a for loop to go through the vector of customers and looking for the ID
    for (unsigned int i = 0; i < listCar.size(); ++i) {
        if (listCar[i]->getIdNum() == id)
            //checking if the ID matches
            index = i;
    }
    //Then returns the index where the ID is located in the vector
    return index;
}

//Function which changes the limit for regular customers
void CarRentalSystem::changeDaysLimitRegular(int newMaxDays) {
    currentMaxRegular = newMaxDays;
    //Checks through the list of customer, if it is a regular customer then the limit is changed
    for (Customer *c : listCustomer) {
        if (c->getType() == Customer::REGULAR) {
            c->setMaxDays(newMaxDays);
        }
    }
}

//Function which changes the limit for VIP
void CarRentalSystem::changeDaysLimitVIP(int newMaxDays) {
    currentMaxRegular = newMaxDays;

    //Goes through the vector of customers using a for loop
    for (Customer *c : listCustomer) {

        //Checks if the customer is VIP, if so then changes the limit
        if (c->getType() == Customer::VIP) {
            c->setMaxDays(newMaxDays);
        }
    }
}

//Function which changes the limit for Corporate customers
void CarRentalSystem::changeDaysLimitCorporate(int newMaxDays) {
    currentMaxRegular = newMaxDays;

    //Goes through the list of customers, and looks
    for (Customer *c : listCustomer) {

        if (c->getType() == Customer::CORPORATE) {
            c->setMaxDays(newMaxDays);

            for (Customer *c : listCustomer) {
                if (c->getType() == Customer::CORPORATE) {
                    c->setMaxDays(newMaxDays);
                }
            }
        }
    }
}

//Function which will update info about a car
void CarRentalSystem::updateCarInfo(int id) {
    cout << "\nUpdating Car Info" << endl;
    int index = searchCar(id);
    if (index == -1) {
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
void CarRentalSystem::updateUserInfo(int id) {
    int result = searchCustomer(id);
    if (result == -1) {
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



//Function which will enable one to rent a car

void CarRentalSystem::rentCar(Customer *customer, Car *car) {
    if (!(car->isAvailable())) {
        cout << "Car is not available for the moment" << endl;
    } else if (customer->getRental() != nullptr) {
        cout << "This customer is currently renting a car" << endl;
    } else {
        car->setAvailability(false);
        customer->addRental(car);
    }

}

void CarRentalSystem::returnCar(Customer *customer) {
    if (customer->getRental() == nullptr)
        cout << "This customer doesn't have a car to return" << endl;
    else {
        customer->getRental()->setAvailability(true);
        customer->removeRental();
    }
}

//Function which prints all the cars
void CarRentalSystem::printCarList() {
    cout << "Type" << setw(10) << "id" << "availability"<<endl;
    //Use a for loop to print the car types and their ID
    int i=0;
    for (Car* c : listCar) {
        cout << i << ")" << c->getType() << " (" << c->getIdNum() << ")" << ": " << ((c->isAvailable()) ? " " : " not ")
             << "available" << endl;
        i++;
    }
}

//Function which prints the name of all customers
void CarRentalSystem::printCustomerList() {
    cout << "Name" << setw(10) << "id" <<"Type";
    //Uses a for loop to go through the vector of customers and prints them
    int i = 0;
    for (Customer* c : listCustomer) {
        cout << i << ")" << c->getName() << " (" << c->getId() << ")" <<": " <<c->getTypeString() <<endl;
        i++;
    }
}

void CarRentalSystem::printCarListForCompany(const string &name) {
    cout << "For company: " << name << endl;
    for (Customer *c: listCustomer) {
        if (c->getType() == 1) {
            auto *corporateCustomer = dynamic_cast<CorporateCustomer *>(c);
            if (corporateCustomer->getCompanyName() == name) {
                if (corporateCustomer->getRental() != nullptr)
                    cout << corporateCustomer->getName() << ": " << corporateCustomer->getRental()->getType();
            }
        }
    }
}


//Find the current maximum ID for Car
int CarRentalSystem::findMaxIDCar() {
    int max = 0;
    for (unsigned int i = 0; i < listCustomer.size(); ++i) {
        if (max < listCustomer[i]->getId())
            max = listCustomer[i]->getId();
    }
    return max;
}


//Finding the latest, biggest ID for a customer
int CarRentalSystem::findMaxIDCustomer() {
    int max = 0;
    for (unsigned int i = 0; i < listCar.size(); ++i) {
        if (max < listCar[i]->getIdNum())
            max = listCar[i]->getIdNum();
    }
    return max;
}

//Used to end the program
void CarRentalSystem::endProgram() {
    for (Customer *c : listCustomer) {
        delete (c);
    }
    listCustomer.clear();

    for (Car *c: listCar) {
        delete (c);
    }
    listCar.clear();

    exit(0);
}

void CarRentalSystem::printPriviledges() {
    cout<<"Types of customers:"
            "\n1)Regular: "<<currentMaxRegular<<" days. Restrictions: Only regular cars"
            "\2)Corporate: "<<currentMaxCorporate<<" days. Restrictions: No"
            "\n3)VIP: "<<currentMaxVIP<<" days. Restrictions: NO";
}


/* unnessecary
//Prints out all the car from the inventory and shows if they are available or not
void CarRentalSystem::determineGivenCarRented() {

    cout << "\nCars in Inventory" << endl;
    for (Car *c : listCar) {
        cout << c->getType() << " (" << c->getIdNum() << ") ";
        (c->isAvailable()) ? cout << "is available" : cout << "is not available" << endl;
    }
}
 */


/* unnessecary
void CarRentalSystem::showPriviledgesCust() {
    int theID, theIndex = 0;
    cout << "\nList of customers" <<endl;
    printCustomerList();
    cout << "\nEnter the ID of a customer" << endl;
    cin.ignore();
    cin >> theID;
    theIndex = searchCustomer(theID);
    listCustomer[theIndex].
}
 */



