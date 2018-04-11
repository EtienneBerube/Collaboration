#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.h"
#include "ui_table.h"
#include <iostream>
#include <vector>
#include "Item.h"
#include "SingleItem.h"
#include <list>
#include <fstream>
#include <ostream>
#include <nlohmann/json.hpp>

// go see -> https://stackoverflow.com/questions/5027406/how-to-move-to-another-window-in-qt-by-a-pushbutton?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

//*************************************************COMPARATORS*****************************************

using namespace std;
using json = nlohmann::json;

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

//*************************************************COMPARATORS*****************************************


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap(":/images/images/bread.png");

    ui->comboBox->addItem("ID");
    ui->comboBox->addItem("Type");
    ui->comboBox->addItem("Name");
    ui->comboBox->addItem("Price per unit");
    ui->comboBox->addItem("Batter");
    ui->comboBox->addItem("Topping");

    ui->image->setPixmap(
        pixmap.scaled(200, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation));

    connect(ui->button,SIGNAL(clicked()),this,SLOT(compute()));

    ui->label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    setMinimumWidth(400);
    setMinimumHeight(150);
}

MainWindow::~MainWindow()
{
    delete ui;

    for (Item *i : items) {
        delete i;
    }

    for (SingleItem *i : container) {
        delete i;
    }

}

void MainWindow::compute()
{
    if(checkCredentials()){
        ifstream input;
            input.open(R"(C:\Users\Etienne\Documents\GitHub\Collaboration\assingment 5\QT\Bakery_inventory\sample.json)");
            //input.open(R"(C:\Users\Natha\OneDrive\Documents\GitHub\Collaboration\assingment 5\sample.json)");
            json json1;

            input >> json1;

            //cout<<"after parse";

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

            //printList(items);
            //std::vector<SingleItem*> container;
            //std::cout<<"****************************************"<<endl;
            singleItemCreator(items,container);

            string field = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString().toUtf8().constData();;

            if(field == "-id"){
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
                //cout<<"Wrong sorting argument"<<endl;
                exit(3);
            }

            input.close();

            ofstream output;
            output.open(R"(C:\Users\Etienne\Documents\GitHub\Collaboration\assingment 5\QT\Bakery_inventory\output.txt)");
            printList(container,output);
            output.close();

            Table tab;
            tab.retreiveVector(container);
            tab.show();
            hide();


    }else{
        ui->label->setText("Missing arguments");
    }



}

bool MainWindow::checkCredentials()
{
    if(ui->input->text().isEmpty() && ui->output->text().isEmpty())
        return false;
    else
        return true;
}


void MainWindow::printList(std::vector<SingleItem *> items, ofstream &output) {

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

void MainWindow::singleItemCreator(std::vector<Item *> &items, std::vector<SingleItem *> &container) {
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

