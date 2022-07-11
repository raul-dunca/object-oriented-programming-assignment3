#pragma once
#include <qwidget.h>
#include "Domain.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include<QtWidgets/QDialog>
#include"Repo.h"
#include<string.h>
#include "Service.h"
using namespace std;
class FilterGUI : public QDialog
{
	Q_OBJECT

public:
	//AdminGUI(std::vector<TrenchCoat> genes, QWidget* parent = 0);
	FilterGUI(Service& s);

private:
	Service& serv;
	//Service s;

	QListWidget* coatsList;
	QLineEdit* SearchEdit;
	

	void initGUI();
	void connectSignalsAndSlots();

	void populateGenesList();

	//void handlePopulate();

public:
	//FilterGUI();

signals: void populateFilterSignal(std::string text);

};

