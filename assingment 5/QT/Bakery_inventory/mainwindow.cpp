#include "mainwindow.h"
#include "ui_mainwindow.h"


// go see -> https://stackoverflow.com/questions/5027406/how-to-move-to-another-window-in-qt-by-a-pushbutton?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

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
}

void MainWindow::compute()
{
    if(checkCredentials()){
    //TODO fill
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
