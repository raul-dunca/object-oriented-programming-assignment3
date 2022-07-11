#include "FilterGUI.h"
#include <QDebug>
#include <fstream>
FilterGUI::FilterGUI(Service& s):  serv{ s }
{
	//this->initGUI()
	//this->populateGenesList();
	this->initGUI();
	this->populateGenesList();
	this->connectSignalsAndSlots();
	//this->populateGenesList();
}

void FilterGUI::initGUI()
{

	QVBoxLayout* layout = new QVBoxLayout{ this };

	QWidget* coatDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ coatDataWidget };
	this->SearchEdit = new QLineEdit{};
	QFont f{ "Verdana", 15 };
	this->SearchEdit->setFont(f);
	formLayout->addRow(this->SearchEdit);

	layout->addWidget(coatDataWidget);

	// left side - just the list
	this->coatsList = new QListWidget{};
	// set the selection model
	this->coatsList->setSelectionMode(QAbstractItemView::SingleSelection);
	layout->addWidget(this->coatsList);

	// right side - coats information + buttons
	

	//show window
//	wnd->show();

	//return a.exec();


}
void FilterGUI::connectSignalsAndSlots()
{
	QObject::connect(this->SearchEdit, &QLineEdit::textChanged, this, &FilterGUI::populateGenesList);

	//QObject::connect(this, &FilterGUI::populateFilterSignal, this, &FilterGUI::populateGenesList);
}



void FilterGUI::populateGenesList()
{
	string text;
	text = this->SearchEdit->text().toStdString();
	// clear the list, if there are elements in it

	if (this->coatsList->count() > 0)
	{
		this->coatsList->clear();
	}

	for (auto g : this->serv.get_vector())
	{
		QString itemInList = QString::fromStdString("Coat with size: " + g.getSize() + ", colour: " + g.getColour() + ", price: " + to_string(g.getPrice()) + ", quantity: " + to_string(g.getQuantity()) + " and photo: " + g.getPhoto());
		QFont f{ "Verdana", 15 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		if (itemInList.toStdString().find(text) != std::string::npos || text == "")					//if filter
		{
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			item->setFont(f);
			this->coatsList->addItem(item);
		}
		//this->coatsList->addItem(item);


	}


}
