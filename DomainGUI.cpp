#include "DomainGUI.h"
#include "FilterGUI.h"
#include <QDebug>
#include <fstream>
#include <QMessageBox>
#include "Validator.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QFormLayout>
AdminGUI::AdminGUI()
{
	//this->initGUI()
	//this->populateGenesList();
	this->initGUI();
	this->populateGenesList();
	//this->populateGenesList();
	this->connectSignalsAndSlots();
}

void AdminGUI::initGUI()
{

	QHBoxLayout* layout = new QHBoxLayout{ this };

	// left side - just the list
	this->coatsList = new QListWidget{};
	// set the selection model
	this->coatsList->setSelectionMode(QAbstractItemView::SingleSelection);
	

	QLinearGradient listGradient(0, 0, 0, this->coatsList->height());
	QPalette palette = qApp->palette();
	palette.setBrush(QPalette::Base, listGradient);
	//palette.setBrush(QPalette::Highlight, listGradient);
	//palette.setBrush(QPalette::HighlightedText, Qt::white);
	palette.setBrush(QPalette::Text, Qt::white);
	this->coatsList->setPalette(palette);

	layout->addWidget(this->coatsList);
	// right side - coats information + buttons
	QWidget* rightSide = new QWidget{};
	QVBoxLayout* vLayout = new QVBoxLayout{ rightSide };

	// coats information
	QWidget* coatDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ coatDataWidget };
	this->SizeEdit = new QLineEdit{};
	this->ColourEdit = new QLineEdit{};
	this->PriceEdit = new QLineEdit{};
	this->QuantityEdit= new QLineEdit{};
	this->PhotoEdit = new QLineEdit{};
	QFont f{ "Verdana", 15 };
	QLabel* SizemLabel = new QLabel{ "&Size:" };
	SizemLabel->setBuddy(this->SizeEdit);
	QLabel* ColourLabel = new QLabel{ "&Colour : " };
	ColourLabel->setBuddy(this->ColourEdit);
	QLabel* PriceLabel = new QLabel{ "&Price:" };
	PriceLabel->setBuddy(this->PriceEdit);
	QLabel* QauntityLabel = new QLabel{ "&Quantity:" };
	QauntityLabel->setBuddy(this->QuantityEdit);
	QLabel* PhotoLabel = new QLabel{ "&Photograph:" };
	PhotoLabel->setBuddy(this->PhotoEdit);
	SizemLabel->setFont(f);
	ColourLabel->setFont(f);
	PriceLabel->setFont(f);
	QauntityLabel->setFont(f);
	PhotoLabel->setFont(f);
	this->SizeEdit->setFont(f);
	this->ColourEdit->setFont(f);
	this->PriceEdit->setFont(f);
	this->QuantityEdit->setFont(f);
	this->PhotoEdit->setFont(f);
	formLayout->addRow(SizemLabel, this->SizeEdit);
	formLayout->addRow(ColourLabel, this->ColourEdit);
	formLayout->addRow(PriceLabel, this->PriceEdit);
	formLayout->addRow(QauntityLabel, this->QuantityEdit);
	formLayout->addRow(PhotoLabel, this->PhotoEdit);

	vLayout->addWidget(coatDataWidget);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QHBoxLayout* hLayout = new QHBoxLayout{ buttonsWidget };
	this->addCoatButton = new QPushButton("Add");
	this->addCoatButton->setFont(f);
	this->deleteCoatButton = new QPushButton("Delete");
	this->deleteCoatButton->setFont(f);
	this->updateCoatButton= new QPushButton("Update");
	this->updateCoatButton->setFont(f);
	this->filterButton = new QPushButton("Filter");
	this->filterButton->setFont(f);
	this->undoButton = new QPushButton("Undo");
	this->undoButton->setFont(f);
	this->redoButton = new QPushButton("Redo");
	this->redoButton->setFont(f);
	hLayout->addWidget(this->addCoatButton);
	hLayout->addWidget(this->deleteCoatButton);
	hLayout->addWidget(this->updateCoatButton);
	hLayout->addWidget(this->filterButton);
	hLayout->addWidget(this->undoButton);
	hLayout->addWidget(this->redoButton);
	vLayout->addWidget(buttonsWidget);

	// add everything to the big layout
	layout->addWidget(this->coatsList);
	layout->addWidget(rightSide);

	//show window
//	wnd->show();

	//return a.exec();

	
}


void AdminGUI::display()
{
	FilterGUI f{ this->s };
	f.exec();
}

void AdminGUI::populateGenesList()
{
	// clear the list, if there are elements in it

	
	

	for (auto g : this->s.get_vector())
	{
		QString itemInList = QString::fromStdString("Coat with size: " + g.getSize() + ", colour: " + g.getColour() + ", price: " + to_string(g.getPrice()) + ", quantity: " + to_string(g.getQuantity()) + " and photo: " + g.getPhoto());
		QFont f{ "Verdana", 15 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		this->coatsList->addItem(item);


	}

}
void AdminGUI::remove_coat()
{

	if (this->ColourEdit->text().toStdString() == "" or this->PriceEdit->text().toStdString() == "")
	{
		QMessageBox m;
		m.critical(0, "Error", "Please fill in the Colour field and Price field!");
		m.setFixedSize(500, 200);
		return;
	}
	else
	{
		try {
			string col;
			double pr;
			int pos=0;
			col = this->ColourEdit->text().toStdString();
			pr = stod(this->PriceEdit->text().toStdString());
			for (auto i : this->s.get_vector())
			{
				if (i.getColour() == col and i.getPrice() == pr)
				{
					break;
				}	
				else
				{
					pos++;
				}
			}
			this->s.deleteCoat(stod(this->PriceEdit->text().toStdString()), this->ColourEdit->text().toStdString());

			this->coatsList->takeItem(pos);
			/*QString itemInList = QString::fromStdString("Coat with size: " + size + ", colour: " + col + ", price: " + to_string(pr) + ", quantity: " + to_string(quant) + " and photo: " + photo);
			QFont f{ "Verdana", 15 };
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			item->setFont(f);
			this->coatsList->removeItemWidget(item);*/
		}
		catch (MyException& me)
		{
			QMessageBox m;
			m.critical(0, "Error", me.what());
			m.setFixedSize(500, 200);
			return;

		}
		
			
			
	}
}
void AdminGUI::update_coat()
{
	if (this->SizeEdit->text().toStdString() == "" or this->ColourEdit->text().toStdString() == "" or this->PriceEdit->text().toStdString() == "" or this->QuantityEdit->text().toStdString() == "" or this->PhotoEdit->text().toStdString() == "")
	{
		QMessageBox m;
		m.critical(0, "Error", "Please fill in all the field");
		m.setFixedSize(500, 200);
		return;
	}
	else
	{
		try {
			this->s.updateCoar(stod(this->PriceEdit->text().toStdString()),this->ColourEdit->text().toStdString(), this->SizeEdit->text().toStdString(), stoi(this->QuantityEdit->text().toStdString()), this->PhotoEdit->text().toStdString());
			this->coatsList->clear();
			for (auto g : this->s.get_vector())
			{
				QString itemInList = QString::fromStdString("Coat with size: " + g.getSize() + ", colour: " + g.getColour() + ", price: " + to_string(g.getPrice()) + ", quantity: " + to_string(g.getQuantity()) + " and photo: " + g.getPhoto());
				QFont f{ "Verdana", 15 };
				QListWidgetItem* item = new QListWidgetItem{ itemInList };
				item->setFont(f);
				this->coatsList->addItem(item);


			}
		}
		catch (ValidationException& e)
		{
			QMessageBox m;
			m.critical(0, "Error", e.getMessage().c_str());
			m.setFixedSize(500, 200);
			return;
		}
		catch (MyException& me)
		{
			QMessageBox m;
			m.critical(0, "Error", me.what());
			m.setFixedSize(500, 200);
			return;

		}
		
		/*QString itemInList = QString::fromStdString("Coat with size: " + this->SizeEdit->text().toStdString() + ", colour: " + this->ColourEdit->text().toStdString() + ", price: " + this->PriceEdit->text().toStdString() + ", quantity: " + this->QuantityEdit->text().toStdString() + " and photo: " + this->PhotoEdit->text().toStdString());
		QFont f{ "Verdana", 15 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		this->coatsList->addItem(item);*/
	}
}
void AdminGUI::undo_coat()
{
	try
	{
		if (this->s.undo() == 0)
		{
			QMessageBox m;
			m.critical(0, "Error", "No more undos");
			m.setFixedSize(500, 200);
			return;
		}
		else
		{
			this->coatsList->clear();
			for (auto g : this->s.get_vector())
			{
				QString itemInList = QString::fromStdString("Coat with size: " + g.getSize() + ", colour: " + g.getColour() + ", price: " + to_string(g.getPrice()) + ", quantity: " + to_string(g.getQuantity()) + " and photo: " + g.getPhoto());
				QFont f{ "Verdana", 15 };
				QListWidgetItem* item = new QListWidgetItem{ itemInList };
				item->setFont(f);
				this->coatsList->addItem(item);


			}
		}
	}
	catch (MyException& me)
	{
		QMessageBox m;
		m.critical(0, "Error", me.what());
		m.setFixedSize(500, 200);
		return;

	}

}

void AdminGUI::redo_coat()
{
	int k;
	try
	{
		k = this->s.redo();
		if (k == 0)
		{
			QMessageBox m;
			m.critical(0, "Error", "No more redos");
			m.setFixedSize(500, 200);
			return;

		}
		else
		{
			this->coatsList->clear();
			for (auto g : this->s.get_vector())
			{
				QString itemInList = QString::fromStdString("Coat with size: " + g.getSize() + ", colour: " + g.getColour() + ", price: " + to_string(g.getPrice()) + ", quantity: " + to_string(g.getQuantity()) + " and photo: " + g.getPhoto());
				QFont f{ "Verdana", 15 };
				QListWidgetItem* item = new QListWidgetItem{ itemInList };
				item->setFont(f);
				this->coatsList->addItem(item);


			}
		}
	}
	catch (MyException& me)
	{
		QMessageBox m;
		m.critical(0, "Error", me.what());
		m.setFixedSize(500, 200);
		return;

	}
	
}
void AdminGUI::add_coat()
{


	if (this->SizeEdit->text().toStdString() == "" or this->ColourEdit->text().toStdString()=="" or this->PriceEdit->text().toStdString()=="" or this->QuantityEdit->text().toStdString()=="" or this->PhotoEdit->text().toStdString()=="")
	{
		QMessageBox m;
		m.critical(0, "Error", "Please fill in all the field");
		m.setFixedSize(500, 200);
		return;

	}
	else
	{
		try {
			this->s.addCoat(this->SizeEdit->text().toStdString(), this->ColourEdit->text().toStdString(), stod(this->PriceEdit->text().toStdString()), stoi(this->QuantityEdit->text().toStdString()), this->PhotoEdit->text().toStdString());

			QString itemInList = QString::fromStdString("Coat with size: " + this->SizeEdit->text().toStdString() + ", colour: " + this->ColourEdit->text().toStdString() + ", price: " + this->PriceEdit->text().toStdString() + ", quantity: " + this->QuantityEdit->text().toStdString() + " and photo: " + this->PhotoEdit->text().toStdString());
			QFont f{ "Verdana", 15 };
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			item->setFont(f);
			this->coatsList->addItem(item);
		}
		catch(ValidationException& e)
		{
			QMessageBox m;
			m.critical(0, "Error",e.getMessage().c_str());
			m.setFixedSize(500, 200);
			return;
		}
		catch (MyException& me)
		{
			QMessageBox m;
			m.critical(0, "Error", me.what());
			m.setFixedSize(500, 200);
			return;

		}
	}
}

void AdminGUI::connectSignalsAndSlots()
{
	//QObject::connect(this, &AdminGUI::buttonPressedSignal, this, &AdminGUI::open);

	QObject::connect(this->filterButton, &QPushButton::clicked, this, &AdminGUI::display);


	QObject::connect(this->addCoatButton, &QPushButton::clicked, this, &AdminGUI::add_coat);

	QObject::connect(this->deleteCoatButton, &QPushButton::clicked, this, &AdminGUI::remove_coat);

	QObject::connect(this->updateCoatButton, &QPushButton::clicked, this, &AdminGUI::update_coat);

	QObject::connect(this->undoButton, &QPushButton::clicked, this, &AdminGUI::undo_coat);

	QObject::connect(this->redoButton, &QPushButton::clicked, this, &AdminGUI::redo_coat);

	QObject::connect(this, &AdminGUI::ZisPressed, this, &AdminGUI::undo_coat);
	
	QObject::connect(this, &AdminGUI::YisPressed, this, &AdminGUI::redo_coat);
	//QObject::connect(this->adminButton, &QPushButton::clicked, this, &OptionGUI::setOptionToAdmin);
	//QObject::connect(this->userButton, &QPushButton::clicked, this, &OptionGUI::setOptionToUser);
}
void AdminGUI::keyPressEvent(QKeyEvent* e)
{
	
	if ((e->key() == Qt::Key_Z) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
	{
		emit ZisPressed();
	}
	else
	{
		if ((e->key() == Qt::Key_Y) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
		{
			emit YisPressed();
		}
	}
}