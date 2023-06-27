/********************************************************************************
** Form generated from reading UI file 'QtWidgetsFL.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSFL_H
#define UI_QTWIDGETSFL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsFLClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonLine;
    QTextEdit *textEditLine;
    QTextEdit *textEditStop;
    QPushButton *pushButtonQuit;
    QPushButton *pushButtonDone;
    QPushButton *pushButtonorg;
    QTextEdit *textEditorg;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelStop;
    QLabel *labelLine;
    QLabel *label;
    QLabel *labelHits;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsFLClass)
    {
        if (QtWidgetsFLClass->objectName().isEmpty())
            QtWidgetsFLClass->setObjectName(QString::fromUtf8("QtWidgetsFLClass"));
        QtWidgetsFLClass->resize(868, 405);
        QtWidgetsFLClass->setMouseTracking(true);
        centralWidget = new QWidget(QtWidgetsFLClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonStop = new QPushButton(centralWidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(600, 60, 93, 28));
        pushButtonLine = new QPushButton(centralWidget);
        pushButtonLine->setObjectName(QString::fromUtf8("pushButtonLine"));
        pushButtonLine->setGeometry(QRect(600, 150, 93, 28));
        textEditLine = new QTextEdit(centralWidget);
        textEditLine->setObjectName(QString::fromUtf8("textEditLine"));
        textEditLine->setGeometry(QRect(240, 150, 351, 31));
        textEditStop = new QTextEdit(centralWidget);
        textEditStop->setObjectName(QString::fromUtf8("textEditStop"));
        textEditStop->setGeometry(QRect(240, 60, 351, 31));
        pushButtonQuit = new QPushButton(centralWidget);
        pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(540, 310, 93, 28));
        pushButtonDone = new QPushButton(centralWidget);
        pushButtonDone->setObjectName(QString::fromUtf8("pushButtonDone"));
        pushButtonDone->setGeometry(QRect(210, 310, 93, 28));
        pushButtonorg = new QPushButton(centralWidget);
        pushButtonorg->setObjectName(QString::fromUtf8("pushButtonorg"));
        pushButtonorg->setGeometry(QRect(600, 240, 93, 28));
        textEditorg = new QTextEdit(centralWidget);
        textEditorg->setObjectName(QString::fromUtf8("textEditorg"));
        textEditorg->setGeometry(QRect(240, 240, 351, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 30, 81, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelStop = new QLabel(layoutWidget);
        labelStop->setObjectName(QString::fromUtf8("labelStop"));

        verticalLayout->addWidget(labelStop);

        labelLine = new QLabel(layoutWidget);
        labelLine->setObjectName(QString::fromUtf8("labelLine"));

        verticalLayout->addWidget(labelLine);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        labelHits = new QLabel(centralWidget);
        labelHits->setObjectName(QString::fromUtf8("labelHits"));
        labelHits->setGeometry(QRect(310, 290, 221, 61));
        QtWidgetsFLClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtWidgetsFLClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 868, 26));
        QtWidgetsFLClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsFLClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsFLClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsFLClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsFLClass->setStatusBar(statusBar);

        retranslateUi(QtWidgetsFLClass);
        QObject::connect(pushButtonStop, SIGNAL(clicked()), QtWidgetsFLClass, SLOT(inputStop()));
        QObject::connect(pushButtonLine, SIGNAL(clicked()), QtWidgetsFLClass, SLOT(inputLine()));
        QObject::connect(pushButtonorg, SIGNAL(clicked()), QtWidgetsFLClass, SLOT(inputOrg()));
        QObject::connect(pushButtonQuit, SIGNAL(clicked()), QtWidgetsFLClass, SLOT(close()));
        QObject::connect(pushButtonDone, SIGNAL(clicked()), QtWidgetsFLClass, SLOT(checkFile()));

        QMetaObject::connectSlotsByName(QtWidgetsFLClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsFLClass)
    {
        QtWidgetsFLClass->setWindowTitle(QApplication::translate("QtWidgetsFLClass", "QtWidgetsFL", nullptr));
        pushButtonStop->setText(QApplication::translate("QtWidgetsFLClass", "\346\265\217\350\247\210...", nullptr));
        pushButtonLine->setText(QApplication::translate("QtWidgetsFLClass", "\346\265\217\350\247\210...", nullptr));
        pushButtonQuit->setText(QApplication::translate("QtWidgetsFLClass", "\351\200\200\345\207\272", nullptr));
        pushButtonDone->setText(QApplication::translate("QtWidgetsFLClass", "\347\241\256\345\256\232", nullptr));
        pushButtonorg->setText(QApplication::translate("QtWidgetsFLClass", "\346\265\217\350\247\210...", nullptr));
        labelStop->setText(QApplication::translate("QtWidgetsFLClass", "\347\253\231\347\202\271\346\226\207\344\273\266", nullptr));
        labelLine->setText(QApplication::translate("QtWidgetsFLClass", "\347\272\277\350\267\257\346\226\207\344\273\266", nullptr));
        label->setText(QApplication::translate("QtWidgetsFLClass", "\345\234\260\345\220\215\346\226\207\344\273\266", nullptr));
        labelHits->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsFLClass: public Ui_QtWidgetsFLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSFL_H
