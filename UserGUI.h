#pragma once
#include <qwidget.h>
#include "Domain.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "Service.h"

class UserGUI : public QWidget
{
	Q_OBJECT

public:
	//AdminGUI(std::vector<TrenchCoat> genes, QWidget* parent = 0);
	UserGUI();

private:
	int cnt;
	Service serv;
	vector<TrenchCoat> filtered_list;
	QListWidget* coatsList;
	QLineEdit* SearchEdit;
	QPushButton* addCoatButton;
	QPushButton* searchCoatButton;
	QPushButton* nextCoatButton;
	QPushButton* displayHTMLCoatButton;
	QPushButton* displayCSVCoatButton;
	QPushButton* displayCoatButton;


	void initGUI();
	void connectSignalsAndSlots();


	void show_basket();
	void show_html();
	void show_csv();
	void add_basket();
	void show_indiv();

	void search_fct();
	

	

//signals:
	//void genesUpdatedSignal();
	//void addGeneSignal(const std::string& geneName, const std::string& organismName, const std::string& sequence);

public slots:
	//void addGene(const std::string& geneName, const std::string& organismName, const std::string& sequence);
};

