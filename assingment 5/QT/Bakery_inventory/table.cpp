#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
}

Table::~Table()
{
    delete ui;
}

void Table::retreiveVector(std::vector<SingleItem *> &_items)
{
   this->items = _items;
}

