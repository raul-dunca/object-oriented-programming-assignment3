#include "DisplayBasket_2.h"

DisplayBasket_2::DisplayBasket_2(Repo& r,QWidget *parent)
	: QWidget(parent), repo{r}
{
	ui.setupUi(this);
	this->tableModel = new GenesTableModel{ this->repo };
	
	// set the model for the table view
	//this->setupTableView();
	ui.basketList->setModel(this->tableModel);
}

DisplayBasket_2::~DisplayBasket_2()
{
}
