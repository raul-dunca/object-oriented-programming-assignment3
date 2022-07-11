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
#include <QKeyEvent>

class AdminGUI : public QWidget
{
	Q_OBJECT


signals:
	void ZisPressed();
	void YisPressed();

public:
	//AdminGUI(std::vector<TrenchCoat> genes, QWidget* parent = 0);
	AdminGUI();
	Service s;

private:
	//Service s;
	//std::vector<TrenchCoat> coats;

	

	QListWidget* coatsList;
	QLineEdit* SizeEdit;
	QLineEdit* ColourEdit;
	QLineEdit* PriceEdit;
	QLineEdit* QuantityEdit;
	QLineEdit* PhotoEdit;
	QPushButton* addCoatButton;
	QPushButton* deleteCoatButton;
	QPushButton* updateCoatButton;
	QPushButton* filterButton;
	QPushButton* undoButton;
	QPushButton* redoButton;


	void initGUI();
	//void connectSignalsAndSlots();

	void populateGenesList();
	void connectSignalsAndSlots();

	void display();
	void add_coat();
	void remove_coat();
	void update_coat();
	void undo_coat();
	void redo_coat();
	//void addGeneButtonHandler();
	//void deleteGeneButtonHandler();

	void keyPressEvent(QKeyEvent* event);
public slots:

};
 
