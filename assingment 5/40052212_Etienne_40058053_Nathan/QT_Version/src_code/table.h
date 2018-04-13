#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include "SingleItem.h"
#include <QTableWidget>


namespace Ui {
class Table;
}

class Table : public QMainWindow
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);
    ~Table();
    void retreiveVector(std::vector<SingleItem *>& _items);

    void closeEvent(QCloseEvent *event);
private:
    Ui::Table *ui;
    std::vector<SingleItem *> items;
};

#endif // TABLE_H
