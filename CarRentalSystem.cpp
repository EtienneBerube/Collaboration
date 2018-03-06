//
// Created by Etienne on 02/03/2018.
//

#include "CarRentalSystem.h"


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
    //Shows the options available to the user
    cout << "\n\n*************************Menu******************************" << endl;
    cout << "1)Print Customer list" << endl;
    cout << "2)Print Car list" << endl;
    cout << "3)Add Customer" << endl;
    cout << "4)Add Car" << endl;
    cout << "5)Rent car" << endl;
    cout << "6)Return car" << endl;
    cout << "7)Print permissions per customer type" << endl;
    cout << "8)Change maximum days a customer can rent" << endl;
    cout << "9)Search Car" << endl;
    cout << "10)Search Customer" << endl;
    cout << "11)Print cars per company" << endl;
    cout << "12)Delete a customer" << endl;
    cout << "13)Remove a car from inventory" << endl;
    cout << "14)Update Car information" << endl;
    cout << "15)Check if a customer rented a car" << endl;
    cout << "16)End program" << endl;

    int choice = 0;
    cin >> choice;

    //makes sure that the user enters only a number between 1 and 16
    while (choice < 1 || choice > 16) {
        cout << "Invalid input, try again!" << endl;
        cin >> choice;
    }

    //Based on what they chose, the right menu will be ran
    switch (choice) {
        case 1:
            //Calls in the function which prints the list of customers
        {
            printCustomerList();
            //Goes back to the menu

        }
            break;

        case 2: { //Calls the function which prints the list of cars
            printCarList();
            //Goes back to the menu

        }
            break;

        case 3: {//The title
            cout << "\nAdding a new Customer" << endl;
            //calls function which will add a new customer
            addCustomer();
            //Goes back to the menu

        }
            break;

        case 4: {//Calls the function which will add a new car to the inventory
            addCar();
            //Goes back to the menu

        }
            break;

        case 5: {
            //The title
            cout << "\nRenting a Car" << endl;
            printCustomerList();
            cout << "Enter the index number of the customer (not the ID): " << endl;
            int customerIndex;
            cin >> customerIndex;
            //Gets the correct index of the customer
            customerIndex--;

            //Prints car list
            printCarList();
            cout << "\nEnter the index number of the car (not the ID): " << endl;
            int carIndex;
            cin >> carIndex;
            //gets the correct index of the car
            carIndex--;

            //Function which will rent the car and the customer
            rentCar(listCustomer[customerIndex], listCar[carIndex]);

            cout << "\nCar has been rented" << endl;

            //Goes back to the menu

        }
            break;

        case 6: {
            //The title of the menu
            cout << "\nReturning a Car" << endl;

            //Prints the list of all customers so as to know who is returning the car
            printCustomerList();
            cout << "\nChoose the customer (the index)" << endl;
            int theID = 0;
            cin.ignore();
            cin >> theID;
            //Getting the right customer index
            theID--;

            //Function which will return the car
            returnCar(listCustomer[theID]);
            cout << "\nCar has been returned" << endl;

            //Goes back to the menu

        }
            break;

        case 7: {   //Calls in the function which will print the priviledges for the types of customers
            printPriviledges();
            //goes back to the menu then

        }
            break;

        case 8: {//Title of Current "Menu"
            cout << "\nChanging the number of days" << endl;

            //pointers to save data and then delete the memory
            int theChoice, theNumDays = 0;

            cout << "\nEnter the new day limit" << endl;
            cin >> theNumDays;

            cout << "Choose the type of customer:\n1) Regular\n2) Corporate\n3) VIP" << endl;
            cin >> theChoice;

            //Making sure its only between one and 3
            while (theChoice < 1 || theChoice > 3) {
                cout << "Choose the type of customer:\n1) Regular\n2) Corporate\n3) VIP" << endl;
                cin >> theChoice;
            }
            //switch case to know for which type of customer to change the limit
            switch (theChoice) {
                case 1:
                    changeDaysLimitRegular(theNumDays);
                    break;
                case 2:
                    changeDaysLimitCorporate(theNumDays);
                    break;
                case 3:
                    changeDaysLimitVIP(theNumDays);
                    break;
            }
            //Goes back to the menu

        }
            break;


        case 9: {
            //The title of the "menu"
            cout << "Searching a Car" << endl;
            cout << "Enter the id to validate: ";
            int id = 0;
            cin >> id;
            //Gets the index of where the car with that ID is located in the vector
            int result = searchCar(id);
            /*Will display the right message because if the ID of the car provided by the user doesnt exist in the vector, the function searchCar returns a -1 */
            cout << "The car with id: " << id << " does" << ((result == -1) ? " not" : "") << " exist";
            if (result != -1) {
                cout << ". It's index is " << result;
            }
            //Goes back to the menu
        }
            break;

        case 10: {
            //Title of the "Menu"
            cout << "\nSearching Customer" << endl;
            cout << "Enter the id to validate: ";
            int theId = 0;
            cin >> theId;

            //Gets index in the vector where that customer is located in the vector
            int result1 = searchCustomer(theId);
            //Displays the right message depending if the customer with that ID exist or not
            cout << "The customer with id: " << theId << " does" << ((result1 == -1) ? "not" : "") << "exist";
            if (result1 != -1) {
                cout << ". It's index is" << result1;
                //Printing the type of customer, Question k)
                cout << "The customer is " << listCustomer[result1]->getType();
            }
            //Goes back to menu

            }
            break;

        case 11: {
            //The title
            cout << "\nCars rented to a company" << endl;
            cout << "\nEnter the name of the company" << endl;
            string theCompanyName;
            cin.ignore();
            //Use getline, so as to take the full line of the stream, companies may have space in their names
            getline(cin, theCompanyName);

            //Calls in the function which will prints the cars rented to a particular company
            printCarListForCompany(theCompanyName);

            //goes back to menu
            }
            break;

        case 12: {
            //Title of this "menu"
            cout << "\nDeleting a customer" << endl;

            //Prints the list of customers so as to know which customer to delete
            printCustomerList();
            cout << "Enter the id of the customer to be deleted" << endl;
            int idCustomer = 0;
            cin >> idCustomer;

            //calls the function which will remove a customer by accepting the ID of the customer
            removeCustomer(idCustomer);
            cout << "\nCustomer has been deleted" << endl;
            //Goes back to menu

            break;
        }
        case 13: {
            //The title of the "menu"
            cout << "\nRemoving a car from the inventory" << endl;

            //Prints the ID of cars so that the user may quickly find out which ID of the car to delete
            printCarList();
            cout << "Enter the ID of the car to be removed" << endl;
            int idCAR = 0;
            cin >> idCAR;

            //Calls the function which takes a car ID and removes that car from the inventory
            removeCar(idCAR);
            cout << "\nCar was removed" << endl;
            //goes back to menu

        }
            break;

        case 14: {
            //The Title of the "menu"
            cout << "\nUpdating car info" << endl;

            //Prints car list so as to know which car id to update info
            printCarList();
            cout << "Enter the ID of the car to be updated" << endl;
            int theCarID;
            cin >> theCarID;
            //Calls function which will update the info of a car using its ID
            updateCarInfo(theCarID);
            //goes back to menu
        }
            break;

        case 15: {
            //The title of the "menu"
            cout << "\nCustomer Checking" << endl;
            cout << "Enter the customer's ID" << endl;
            int idCus;
            cin >> idCus;
            //Calls function which takes a customer ID and shows whether they rented a car or not
            didCustomerRentCar(idCus);
            //goes back to menu

        }
            break;

        default:
            //Calls function which ends the program
            endProgram();
            break;
    }
    menu();

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
    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Enter telephone number: ";
    cin.ignore();
    getline(cin, telephoneNumber);

    if (choice == 2) {

        cout << "Enter the company's name: ";
        cin.ignore();
        getline(cin, companyName);


        cout << "Enter company's address: ";
        cin.ignore();
        getline(cin, companyAddress);
    }

    //Depending on the type of customer, the right constructor will be called
    switch (choice) {
        case 1:
            listCustomer.push_back(
                    new RegularCustomer((findMaxIDCustomer() + 1), name, address, telephoneNumber, currentMaxRegular));
            break;
        case 2:
            listCustomer.push_back(
                    new CorporateCustomer((findMaxIDCustomer() + 1), name, address, telephoneNumber,
                                          currentMaxCorporate, companyName, companyAddress));
            break;
        case 3:
            listCustomer.push_back(
                    new VIPCustomer((findMaxIDCustomer() + 1), name, address, telephoneNumber, currentMaxVIP));
            break;
        default:
            cout << "Error occured" << endl;
            break;
    }
    cout << "\nNew customer created" << endl;
}

//Function to add a new car
void CarRentalSystem::addCar() {
    int choice = 0;
    int isAvailable = 0;
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

    cout << "\nIs the car readily available:\n1 - yes\n2 - no" << endl;
    cin.ignore();
    cin >> isAvailable;

    //Making sure that the customer only enters y or Y or n or N to know whether or not a new car is readily available
    while (isAvailable < 1 || isAvailable > 2) {
        cout << "\nIs the car readily available:\n1 - yes\n2 - no" << endl;
        cin >> isAvailable;
    }

    if (isAvailable == 2) {
        availability = false;
    }

    //Depending on the type of car, the right constructor is called
    switch (choice) {
        case 1:
            //so that the ID is generated automatically
            listCar.push_back(new luxuryCar((findMaxIDCar() + 1), availability));
            break;
        default:
            listCar.push_back(new regularCar((findMaxIDCar() + 1), availability));
            break;
    }
    cout << "\nNew Car Added" << endl;
    cout << "\nReturning back to menu" << endl;
}

//function which removes a car
void CarRentalSystem::removeCar(int theID) {

    //Function which will return the index related to the car's ID
    int theIndex = searchCar(theID);
    delete (listCar[theIndex]);
    listCar.erase(listCar.begin() + theIndex);
    cout << "Deleting . . ." << endl;

}

//function which removes a customer
void CarRentalSystem::removeCustomer(int delId) {
    int delIndex = searchCustomer(delId);
    delete (listCar[delId]);
    listCustomer.erase(listCustomer.begin() + delIndex);
    cout << "Deleting . . . " << endl;
    cout << "Returning back to menu " << endl;
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
    int index = searchCar(id);
    if (index == -1) {
        cout << "\nCar does not exist" << endl;
    } else {
        int yesOrNo;
        cout << "Changing the availability" << endl;
        cout << "Car Availability: \n1 - yes\n2 - no" << endl;
        cin.ignore();
        cin >> yesOrNo;

        //Making sure that the customer only enters 1 or 2 to know whether or not a car is readily available
        while (yesOrNo < 1 || yesOrNo > 2) {
            cout << "\nIs the car available: \n1 - yes\n2 - no" << endl;
            cin.ignore();
            cin >> yesOrNo;
        }

        if (yesOrNo == 2)
            listCar[index]->setAvailability(false);
        else
            listCar[index]->setAvailability(true);
        //Change the type of the car
        cout << "Car Type:\n1 - Luxury\n2 - Regular" << endl;
        cin >> yesOrNo;
        //Making sure that the customer only enters 1 or 2 to change the type of the a car
        while (yesOrNo < 1 || yesOrNo > 2) {
            cout << "\nCar Type:\n1 - Luxury\n2 - Regular" << endl;
            cin >> yesOrNo;
        }
        switch (yesOrNo) {
            case 1:
                listCar[index]->setType(1);
                break;
            default:
                listCar[index]->setType(0);
                break;
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


//Function which allows a customer to return a car
void CarRentalSystem::returnCar(Customer *customer) {
    //Checks if the customer has no car rented to his name
    if (customer->getRental() == nullptr)
        cout << "This customer doesn't have a car to return" << endl;
        //If he does have a car then it returns the car
    else {
        customer->getRental()->setAvailability(true);
        customer->removeRental();
    }
}

//Function which prints all the cars
void CarRentalSystem::printCarList() {
    cout << setw(14) << left << "\nType " << setw(3) << "id    " << "availability" << endl;
    //Use a for loop to print the car types and their ID
    int i = 1;
    for (Car *c : listCar) {
        //Prints the info in a good format
        cout << i << ")" << setw(5) << left << setw(10) << left << c->getType() << " (" << c->getIdNum() << ")" << "  "
             << ((c->isAvailable()) ? " " : " not ")
             << "available" << endl;
        i++;
    }
}

//Function which prints the name of all customers
void CarRentalSystem::printCustomerList() {
    //Nice Column header layout
    cout << setw(4) << left << "\nName" << setw(22) << right << " id" << setw(20) << "Type" << endl;
    //Uses a for loop to go through the vector of customers and prints them
    int i = 1;
    for (Customer *c : listCustomer) {
        //Prints the stuffs in a nice layout
        cout << i << ")" << setw(5) << left << setw(22) << left << c->getName() << "(" << c->getId() << ")" << setw(15)
             << " " << c->getTypeString() << endl;
        i++;
    }
}

//Function which prints the list of cars for a certain company
void CarRentalSystem::printCarListForCompany(const string &name) {
    //From the company name obtained from the user
    cout << "For company: " << name << endl;
    //Goes through the list of customers, finds if the customer is corporate
    for (Customer *c: listCustomer) {
        if (c->getType() == 1) {
            auto *corporateCustomer = dynamic_cast<CorporateCustomer *>(c);
            //If the customer is corporate it then checks for the company name
            if (corporateCustomer->getCompanyName() == name) {
                //Checks if a car was rented by that corporate customer
                if (corporateCustomer->getRental() != nullptr)
                    //If all of this is true, then the car type is printed
                    cout << corporateCustomer->getName() << ": " << corporateCustomer->getRental()->getType();
            }
        }
    }
}


//Find the current maximum ID for Car
int CarRentalSystem::findMaxIDCustomer() {
    int max = 0;
    //Goes through the list of
    for (unsigned int i = 0; i < listCustomer.size(); ++i) {
        if (max < listCustomer[i]->getId())
            max = listCustomer[i]->getId();
    }
    return max;
}

//Finding the latest, biggest ID for a customer
int CarRentalSystem::findMaxIDCar() {
    int max = 0;
    //Goes through the list of customers, find the biggest ID there and returns it
    for (unsigned int i = 0; i < listCar.size(); ++i) {
        if (max < listCar[i]->getIdNum())
            max = listCar[i]->getIdNum();
    }
    return max;
}

//Used to end the program
void CarRentalSystem::endProgram() {

    //All the customers are deleted
    for (Customer *c : listCustomer) {
        delete (c);
    }
    listCustomer.clear();

    //Delete all the cars
    for (Car *c: listCar) {
        delete (c);
    }
    listCar.clear();

    exit(0);
}

//Function which prints the priviledges of the types of customers
void CarRentalSystem::printPriviledges() {
    //The title
    cout << "\nThe Priviledges" << endl;
    cout << "Types of customers:"
            "\n1)Regular: " << currentMaxRegular << " days. Restrictions: Only regular cars"
                 "\n2)Corporate: " << currentMaxCorporate << " days. Restrictions: No"
                 "\n3)VIP: " << currentMaxVIP << " days. Restrictions: NO";
}

CarRentalSystem::CarRentalSystem() {
    initialize();
}

//Function which initializes the system
void CarRentalSystem::initialize() {
    //Creates a few car and customers so the system looks like it has some stuffs from the beginning
    listCustomer.push_back(new RegularCustomer(1, "Etienne", "123 test", "7327626832", currentMaxRegular));
    listCustomer.push_back(new RegularCustomer(2, "Dean", "124 test", "188888", currentMaxRegular));
    listCustomer.push_back(new VIPCustomer(3, "BigBenji", "999 im rich road", "99999999", currentMaxVIP));
    listCustomer.push_back(new CorporateCustomer(4, "Mr Ron", "127 kk lol", "1234567", currentMaxCorporate, "Bell", "1800 service de marde"));
    listCustomer.push_back(new CorporateCustomer(5, "Dr miller", "39 MDR", "19090", currentMaxCorporate, "Bell", "1800 service de marde"));

    listCar.push_back(new regularCar(1, true));
    listCar.push_back(new regularCar(2, true));
    listCar.push_back(new luxuryCar(3, true));
}


//Function which tells if a particular customer rented a car
void CarRentalSystem::didCustomerRentCar(int id) {
    int Index = searchCustomer(id);
    //Checks whether this id does exist
    if (Index == -1) {
        cout << "\nCustomer does not exist" << endl;
    } else {
        //Checks if the pointer is pointed to nowhere, if so that means that the customer did not rent any car presently
        if (listCustomer[Index]->getRental() == nullptr)
            cout << "This customer did not rent a car" << endl;
        else
            cout << "This customer did rent a car" << endl;
    }
}

/* unnessecary
//Prints out all the car from the inventory and shows if they are available or not
void Coen244CarRentingBusiness::determineGivenCarRented() {

    cout << "\nCars in Inventory" << endl;
    for (Car *c : listCar) {
        cout << c->getType() << " (" << c->getIdNum() << ") ";
        (c->isAvailable()) ? cout << "is available" : cout << "is not available" << endl;
    }
}
 */


/* unnessecary
void Coen244CarRentingBusiness::showPriviledgesCust() {
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
