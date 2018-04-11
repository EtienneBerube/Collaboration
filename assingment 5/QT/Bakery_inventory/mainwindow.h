#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Item.h"
#include "SingleItem.h"
#include <fstream>
#include <ostream>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool checkCredentials();

    void printList(std::vector<SingleItem *> items, std::ofstream &output);
    void singleItemCreator(std::vector<Item *> &items, std::vector<SingleItem *> &container);

public slots:
    void compute();

private:
    Ui::MainWindow *ui;
    std::vector<Item *> items;
    std::vector<SingleItem *> container;
};

#endif // MAINWINDOW_H
