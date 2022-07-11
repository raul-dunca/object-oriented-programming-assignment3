#pragma once

#include <QWidget>
#include "ui_DisplayBasket_2.h"
#include "Repo.h"
#include "MyModel.h"
class DisplayBasket_2 : public QWidget
{
	Q_OBJECT

public:
	DisplayBasket_2(Repo& r,QWidget *parent = Q_NULLPTR);
	~DisplayBasket_2();

private:
	Repo& repo;
	GenesTableModel* tableModel;
	Ui::DisplayBasket_2 ui;
	//void setupTableView();
};
