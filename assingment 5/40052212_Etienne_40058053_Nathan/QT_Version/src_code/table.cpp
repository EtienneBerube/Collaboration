#include "table.h"
#include "ui_table.h"
#include <QStringList>
#include <string>
#include <iostream>
#include <QString>
#include <QTableWidget>

Table::Table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);

    ui->tableWidget->verticalHeader()->setVisible(false);


}

Table::~Table()
{
    delete ui;
}

void Table::retreiveVector(std::vector<SingleItem *> &_items)
{
   this->items = _items;
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(items.size());

    QStringList m_TableHeader;
    /*m_TableHeader.append("ID");
    m_TableHeader.append("Type");
    m_TableHeader.append("Name");
    m_TableHeader.append("Batter");
    m_TableHeader.append("Topping");
    m_TableHeader.append("PPu");*/

    m_TableHeader<<"ID"<<"Type"<<"Name"<<"Batter"<<"Topping"<<"PPU";
    ui->tableWidget->setHorizontalHeaderLabels(m_TableHeader);
    std::cout<<"After header";

    for(unsigned int i = 0 ; i < items.size(); i++){
        std::cout<<"in loop";
        std::string id = items[i]->getId();
        QString temp;
        temp = QString::fromStdString(id);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(items[i]->getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(items[i]->getType())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(items[i]->getName())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(items[i]->getBatters().second)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(items[i]->getToppings().second)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(items[i]->getPpu())));
    }

    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->centralwidget->adjustSize();


}


void Table::closeEvent (QCloseEvent *event)
{
    this->parentWidget()->close();
}

