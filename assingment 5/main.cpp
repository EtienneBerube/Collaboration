#include <iostream>
#include <vector>
#include "item.h"
#include <list>
//https://github.com/nlohmann/json/blob/develop/README.md
#include <nlohmann/json.hpp>
#include <fstream>

// for convenience

using json = nlohmann::json;
//using basic = nlohmann::basic_json<>::object_t ;
using object_t =  json::object_t;

using namespace std;



//*****************************COMPARATORS******************************

//https://stackoverflow.com/questions/26444216/is-it-possible-to-use-stdsort-with-a-sort-function-that-takes-extra-arguments?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

struct CompareEdges {
    bool operator()(const Item *i1, const Item *i2, char checker) const {
        //TODO finish
    }
};
//*****************************COMPARATORS******************************

void printList(std::vector<Item *> items);

int main(int argc, char *argv[]) {
    vector<Item *> items;

    string field;
    string inputFile;
    string outputFile;


    if (argc < 4 || argc > 4) {
        cout << "Bad number of arguments. Expected 3, got " << argc << endl;
        return 1;
    }

    field = argv[1];
    inputFile = argv[2];
    outputFile = argv[3];

    cout << "1: " << field << " 2: " << inputFile << " 3: " << outputFile << endl;


    //input.open(R"(C:\Users\Etienne\Documents\GitHub\Collaboration\assingment 5\test.txt)");
    //string path = ;
    //path.c_str();
    //input.open(inputFile);
    //input.open("..\\sample.json");
/*
    if (input.is_open()) {
        string temp;
        cout << "worked: " << endl;
        while ( getline (input,temp) )
        {
            cout << temp << '\n';
        }
    }
*/

    cout << "test" << endl;

    ifstream input;
    input.open(R"(C:\Users\Etienne\Documents\GitHub\Collaboration\assingment 5\sample.json)");

    json json1;

    input >> json1;

    cout<<"after parse";

    json json2 = json1["items"]["item"];


    for (const auto &item : json1["items"]["item"]) {
        Item *temp = new Item();

        temp->setId(item["id"]);
        temp->setName(item["name"]);
        temp->setPpu(item["ppu"]);
        temp->setType(item["type"]);

        // check if item["batters"]["batter"] exists
        if (item.find("batters") != item.end() &&
            item["batters"].find("batter") != item["batters"].end()) {
            for (const auto &batter : item["batters"]["batter"]) {
                temp->addBatter(batter["id"], batter["type"]);
                //std::cout << batter["id"] << ", " << batter["type"] << std::endl; <--- debugging
            }
        }

        // check if item["topping"] exists
        if (item.find("topping") != item.end()) {
            for (const auto &topping : item["topping"]) {
                temp->addTopping(topping["id"], topping["type"]);
                //std::cout << topping["id"] << ", " << topping["type"] << std::endl;
            }
        }
        items.push_back(temp);
    }

    printList(items);

    for (Item *i : items) {
        delete i;
    }

    return 0;
}

void printList(std::vector<Item *> items) {
    for (Item *i: items) {
        std::cout << i->getName() << ":\nBatters:" << std::endl;
        for (map<int, string>::iterator it = i->getBatters().begin(); it != i->getBatters().end(); i++) {
            cout << it->second;
        }
        std::cout << "Toppings: " << std::endl;
        for (map<int, string>::iterator it = i->getToppings().begin(); it != i->getToppings().end(); i++) {
            cout << it->second;
        }
    }
}