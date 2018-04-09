#include <iostream>
#include <vector>
#include "item.h"
#include "SingleItem.h"
#include <list>
//https://github.com/nlohmann/json/blob/develop/README.md
#include <nlohmann/json.hpp>
#include <fstream>
#include<ostream>

// for convenience

using json = nlohmann::json;
//using basic = nlohmann::basic_json<>::object_t ;
using object_t =  json::object_t;

using namespace std;



//*****************************COMPARATORS******************************

//https://stackoverflow.com/questions/26444216/is-it-possible-to-use-stdsort-with-a-sort-function-that-takes-extra-arguments?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

struct CompareID {
    bool operator()(const SingleItem *i1, const SingleItem *i2) const {
        return i1->getId()<i2->getId();
    }
};

struct CompareName {
    bool operator()(const SingleItem *i1, const SingleItem *i2) const {
        return i1->getName().compare(i2->getName())<0;
    }
};

struct CompareTopping {
    bool operator()( SingleItem *i1,  SingleItem *i2) const {
        return i1->getToppings().second.compare(i2->getToppings().second)<0;
    }
};

struct CompareBatter {
    bool operator()( SingleItem *i1,  SingleItem *i2) const {
        return i1->getBatters().second.compare(i2->getBatters().second)<0;
    }
};

struct CompareType {
    bool operator()(const SingleItem *i1, const SingleItem *i2) const {
        return i1->getType().compare(i2->getType())<0;
    }
};

struct ComparePPu {
    bool operator()(const SingleItem *i1, const SingleItem *i2) const {
        return i1->getPpu()<i2->getPpu();
    }
};

//*****************************COMPARATORS******************************
void printList(std::vector<Item *> items);
void printList(std::vector<SingleItem *> items,ofstream &output);


void singleItemCreator(std::vector<Item*> &items, std::vector<SingleItem*> &container);

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

    ifstream input;
    //input.open(R"(C:\Users\Etienne\Documents\GitHub\Collaboration\assingment 5\sample.json)");
    input.open(R"(C:\Users\Natha\OneDrive\Documents\GitHub\Collaboration\assingment 5\sample.json)");
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
        if (item.find("batters") != item.end() && item["batters"].find("batter") != item["batters"].end()) {
            for (const auto &batter : item["batters"]["batter"]) {
                string temp_int = batter["id"];
                temp->addBatter(stoi(temp_int), batter["type"]);
            }
        }

        // check if item["topping"] exists
        if (item.find("topping") != item.end()) {
            for (const auto &topping : item["topping"]) {
                string temp_int =topping["id"];
                temp->addTopping(stoi(temp_int), topping["type"]);
            }
        }
        items.push_back(temp);
    }
    printList(items);
    std::vector<SingleItem*> container;
    std::cout<<"****************************************"<<endl;
    singleItemCreator(items,container);

    if(field=="-id"){
        std::sort(container.begin(),container.end(),CompareID());
    }else
        if(field=="-name"){
            std::sort(container.begin(),container.end(),CompareName());
    }else
        if(field=="-type"){
            std::sort(container.begin(),container.end(),CompareType());
    }else
        if(field=="-batter"){
            std::sort(container.begin(),container.end(),CompareBatter());
    }else
        if(field=="-topping"){
            std::sort(container.begin(),container.end(),CompareTopping());
    }else
        if(field=="-ppu"){
            std::sort(container.begin(),container.end(),ComparePPu());
    }else{
        cout<<"Wrong sorting argument"<<endl;
        exit(3);
    }

    input.close();

    ofstream output;
    output.open(R"(C:\Users\Natha\OneDrive\Documents\GitHub\Collaboration\assingment 5\output.txt)");
    printList(container,output);
    output.close();
    for (Item *i : items) {
        delete i;
    }

    for (SingleItem *i : container) {
        delete i;
    }
    return 0;
}


void printList(std::vector<Item *> items) {
    for (Item *i: items) {
        std::cout<<"\n*******************************"<<endl;
        std::cout<< i->getName() <<endl;
        std::cout <<"\nBatters:" << std::endl;
        for (auto &it : i->getBatters()) {
            cout << it.second<<endl;
        }
        std::cout << "\nToppings: " << std::endl;
        for (auto &it : i->getToppings()) {
            cout << it.second<<endl;
        }
    }
}

void singleItemCreator(std::vector<Item *> &items, std::vector<SingleItem *> &container) {
    for(Item* i:items){
        for (auto it = i->getBatters().begin(); it != i->getBatters().end(); it++) {
            cout<<i->getName()<<"->Batter:"<<it->second<<endl;

            for (auto ita = i->getToppings().begin(); ita != i->getToppings().end(); ita++) {
                cout<<i->getName()<<"->Topping:"<<ita->second<<endl;
                container.push_back(new SingleItem(i->getId(),i->getType(),i->getName(),i->getPpu(),*it,*ita ));
            }
        }
    }
}

void printList(std::vector<SingleItem *> items,ofstream &output) {

    output<<"Id";
    output<<"\t\t";
    output<<"Name";
    output<<"\t";
    output<<"Batters";
    output<<"\t\t\t";
    output<<"Toppings";
    output<<"\n";

    for (SingleItem *i: items) {
        output<<left;
        output<<setw(8);
        output<<(i->getId());
        output<<setw(8);
        output<<(i->getName());
        output<<setw(15);
        output<<(i->getBatters().second);
        output<<setw(8);
        output<<(i->getToppings().second);
        output<<endl;

    }
}