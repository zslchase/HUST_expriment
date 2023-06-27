#pragma once

#include <QMainWindow>
#include <qcompleter.h>
#include "ui_MainWindow.h"
#include <Qlistview>
#include "logic.h"
#include "twnlt.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QStringList qstr, QWidget* parent = Q_NULLPTR);
	void FuzzySearch();
	void checkinput();
	~MainWindow();
private:
	Ui::MainWindowClass ui;
	QStringList qstr;
	QString start;
	QString end;
};
