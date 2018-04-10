/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *button;
    QLineEdit *input;
    QLineEdit *output;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *image;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(462, 259);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 250, 180, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button = new QPushButton(centralWidget);
        button->setObjectName(QStringLiteral("button"));
        button->setGeometry(QRect(10, 150, 93, 28));
        input = new QLineEdit(centralWidget);
        input->setObjectName(QStringLiteral("input"));
        input->setGeometry(QRect(10, 30, 191, 22));
        output = new QLineEdit(centralWidget);
        output->setObjectName(QStringLiteral("output"));
        output->setGeometry(QRect(10, 70, 191, 22));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 110, 191, 22));
        comboBox->setMaxVisibleItems(6);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 160, 171, 16));
        image = new QLabel(centralWidget);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(230, 40, 211, 171));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bakery inventory", nullptr));
        button->setText(QApplication::translate("MainWindow", "Compute", nullptr));
#ifndef QT_NO_TOOLTIP
        input->setToolTip(QApplication::translate("MainWindow", "Input path", nullptr));
#endif // QT_NO_TOOLTIP
        input->setPlaceholderText(QApplication::translate("MainWindow", "Input path", nullptr));
        output->setPlaceholderText(QApplication::translate("MainWindow", "Output path", nullptr));
        comboBox->setCurrentText(QString());
        label->setText(QString());
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
