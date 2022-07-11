#include "UserGUI.h"
#include <QDebug>
#include <fstream>
#include <QMessageBox>
#include "DisplayBasket_2.h"
UserGUI::UserGUI()
{
	this->cnt = -1;
	//this->initGUI()
	//this->populateGenesList();
	this->initGUI();
	this->connectSignalsAndSlots();
	this->serv.htmlrepo.coats.clear();
	this->serv.csvrepo.coats.clear();
	//this->populateGenesList();
}

void UserGUI::initGUI()
{

	QVBoxLayout* layout = new QVBoxLayout{ this };

	// search bar + Qlist
	this->coatsList = new QListWidget{};
	this->coatsList->setSelectionMode(QAbstractItemView::SingleSelection);
	QFont f{ "Verdana", 15 };
	this->SearchEdit = new QLineEdit{};
	QLabel* SearchLabel = new QLabel{ "&Search:" };
	SearchLabel->setBuddy(this->SearchEdit);
	
	SearchLabel->setFont(f); 
	this->SearchEdit->setFont(f);


	layout->addWidget(SearchLabel);
	layout->addWidget(this->SearchEdit);
	
	layout->addWidget(this->coatsList);

	

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QHBoxLayout* hLayout = new QHBoxLayout{ buttonsWidget };
	this->searchCoatButton = new QPushButton("Search");
	this->searchCoatButton->setFont(f);
	this->addCoatButton = new QPushButton("Add");
	this->addCoatButton->setFont(f);
	this->nextCoatButton = new QPushButton("Next");
	this->nextCoatButton->setFont(f);
	this->displayHTMLCoatButton = new QPushButton("Display Basket HTML");
	this->displayHTMLCoatButton->setFont(f);
	this->displayCSVCoatButton = new QPushButton("Display Basket CSV");
	this->displayCSVCoatButton->setFont(f);
	this->displayCoatButton = new QPushButton("Display Basket");
	this->displayCoatButton->setFont(f);
	hLayout->addWidget(this->searchCoatButton);
	hLayout->addWidget(this->addCoatButton);
	hLayout->addWidget(this->nextCoatButton);
	hLayout->addWidget(this->displayHTMLCoatButton);
	hLayout->addWidget(this->displayCSVCoatButton);
	hLayout->addWidget(this->displayCoatButton);
	layout->addWidget(buttonsWidget);

	


}

void UserGUI::search_fct()
{
	this->cnt = 0;
	this->filtered_list.clear();
	this->coatsList->clear();
	if (this->SearchEdit->text().toStdString() == "")
	{
		
		for (auto g : this->serv.get_vector())
		{
			this->filtered_list.push_back(g);

		}
	}
	else
	{
		for (auto g : this->serv.get_vector())
		{
			if (g.getSize() == this->SearchEdit->text().toStdString())
			{
				this->filtered_list.push_back(g);
			}


		}
	}

	QString itemInList = QString::fromStdString("Coat with size: " + this->filtered_list[cnt].getSize() + ", colour: " + this->filtered_list[cnt].getColour() + ", price: " + to_string(this->filtered_list[cnt].getPrice()) + ", quantity: " + to_string(this->filtered_list[cnt].getQuantity()) + " and photo: " + this->filtered_list[cnt].getPhoto());
	QFont f{ "Verdana", 15 };
	QListWidgetItem* item = new QListWidgetItem{ itemInList };
	item->setFont(f);
	system(string("start " + this->filtered_list[this->cnt].getPhoto()).c_str());
	this->coatsList->addItem(item);
}
void UserGUI::add_basket()
{
	if (this->cnt == -1)
	{
		QMessageBox m;
		m.critical(0, "Error", "Please Search before pressing Add!");
		m.setFixedSize(500, 200);
		return;
	
	}
	else
	{
		try {
			this->serv.csvrepo.add_repo(this->filtered_list[this->cnt]);
			this->serv.csvrepo.save_CSV("b.csv");


			this->serv.htmlrepo.add_repo(this->filtered_list[this->cnt]);
			this->serv.htmlrepo.save_html("h.html");
		}
		catch (MyException& e)
		{
			QMessageBox m;
			m.critical(0, "Error", e.what());
			m.setFixedSize(500, 200);
			return;
		}
	}
}
void UserGUI::show_html()
{
	if (this->serv.htmlrepo.coats.size() == 0)
	{
		QMessageBox m;
		m.critical(0, "Error", "Please Add something to the basket before pressing Display!");
		m.setFixedSize(500, 200);
		return;
	}
	else
	this->serv.htmlrepo.display_html("h.html");
}
void UserGUI::show_csv()
{
	if (this->serv.csvrepo.coats.size() == 0)
	{
		QMessageBox m;
		m.critical(0, "Error", "Please Add something to the basket before pressing Display!");
		m.setFixedSize(500, 200);
		return;
	}
	else
	this->serv.csvrepo.display_csv("b.csv");
}
void UserGUI::show_indiv()
{
	if (this->cnt == -1)
	{
		QMessageBox m;
		m.critical(0, "Error", "Please Search before pressing Next!");
		m.setFixedSize(500, 200);
		return;
	}
	else
	{	
		if (this->cnt == this->filtered_list.size() - 1)
			this->cnt = 0;
		else
			this->cnt++;

		this->coatsList->clear();
		QString itemInList = QString::fromStdString("Coat with size: " + this->filtered_list[cnt].getSize() + ", colour: " + this->filtered_list[cnt].getColour() + ", price: " + to_string(this->filtered_list[cnt].getPrice()) + ", quantity: " + to_string(this->filtered_list[cnt].getQuantity()) + " and photo: " + this->filtered_list[cnt].getPhoto());
		QFont f{ "Verdana", 15 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		system(string("start " + this->filtered_list[this->cnt].getPhoto()).c_str());
		this->coatsList->addItem(item);
		
	}
}
void UserGUI::show_basket()
{
	DisplayBasket_2* d=new DisplayBasket_2 {this->serv.htmlrepo};
	d->show();
}
void UserGUI::connectSignalsAndSlots()
{
	QObject::connect(this->searchCoatButton, &QPushButton::clicked, this, &UserGUI::search_fct);

	QObject::connect(this->nextCoatButton, &QPushButton::clicked, this, &UserGUI::show_indiv);

	QObject::connect(this->addCoatButton, &QPushButton::clicked, this, &UserGUI::add_basket);

	QObject::connect(this->displayCSVCoatButton, &QPushButton::clicked, this, &UserGUI::show_csv);

	QObject::connect(this->displayHTMLCoatButton, &QPushButton::clicked, this, &UserGUI::show_html);

	QObject::connect(this->displayCoatButton, &QPushButton::clicked, this, &UserGUI::show_basket);

}