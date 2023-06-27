/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QLabel *labelStart;
    QComboBox *comboBox_2;
    QLabel *labelEnd;
    QLabel *labelHits;
    QPushButton *pushButtonOk;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButtonQuit;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(620, 409);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelStart = new QLabel(centralWidget);
        labelStart->setObjectName(QString::fromUtf8("labelStart"));
        labelStart->setGeometry(QRect(110, 70, 61, 21));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(170, 120, 300, 30));
        labelEnd = new QLabel(centralWidget);
        labelEnd->setObjectName(QString::fromUtf8("labelEnd"));
        labelEnd->setGeometry(QRect(110, 130, 61, 20));
        labelHits = new QLabel(centralWidget);
        labelHits->setObjectName(QString::fromUtf8("labelHits"));
        labelHits->setGeometry(QRect(230, 170, 151, 41));
        pushButtonOk = new QPushButton(centralWidget);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(180, 250, 80, 30));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(173, 70, 300, 30));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 70, 150, 30));
        pushButtonQuit = new QPushButton(centralWidget);
        pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(340, 250, 80, 30));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 120, 150, 30));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 620, 23));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);
        QObject::connect(pushButtonQuit, SIGNAL(clicked()), MainWindowClass, SLOT(close()));
        QObject::connect(pushButtonOk, SIGNAL(clicked()), MainWindowClass, SLOT(checkinput()));

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        labelStart->setText(QApplication::translate("MainWindowClass", "\345\207\272\345\217\221\345\234\260", nullptr));
        labelEnd->setText(QApplication::translate("MainWindowClass", "\347\233\256\347\232\204\345\234\260", nullptr));
        labelHits->setText(QString());
        pushButtonOk->setText(QApplication::translate("MainWindowClass", "\347\241\256\345\256\232", nullptr));
        pushButtonQuit->setText(QApplication::translate("MainWindowClass", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
