#include "OptionGUI.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QFormLayout>
OptionGUI::OptionGUI()
{
    this->option = "";
    this->initGUI();
    this->connectSignalsAndSlots();
}

std::string OptionGUI::getOption()
{
    return this->option;
}

void OptionGUI::initGUI()
{
    QVBoxLayout* layout = new QVBoxLayout{ this };
    QFont f{ "Verdana", 15 };
    QFormLayout* formLayout = new QFormLayout{};
    QLabel* labelInfo = new QLabel{ "Selec the mode you want to enter: " };
    labelInfo->setFont(f);
    formLayout->addRow(labelInfo);

   // QLinearGradient* q = new QLinearGradient{};

    QWidget* options = new QWidget{};
    QHBoxLayout* buttonLayout = new QHBoxLayout{};

    this->userButton = new QPushButton{ "&User" };
    this->adminButton = new QPushButton{ "&Admin" };
    //this->adminButton->setFixedWidth(180);
   
    this->userButton->setFont(f);
    this->adminButton->setFont(f);


    
    

    buttonLayout->addWidget(userButton);
    buttonLayout->addWidget(adminButton);
    options->setLayout(buttonLayout);

    layout->addLayout(formLayout);
    layout->addWidget(options);
}

void OptionGUI::connectSignalsAndSlots()
{
    QObject::connect(this, &OptionGUI::buttonPressedSignal, this, &OptionGUI::handleOption);

    QObject::connect(this->adminButton, &QPushButton::clicked, this, &OptionGUI::setOptionToAdmin);
    QObject::connect(this->userButton, &QPushButton::clicked, this, &OptionGUI::setOptionToUser);


}

void OptionGUI::setOptionToAdmin()
{
    std::string option = "admin";
    emit buttonPressedSignal(option);
}

void OptionGUI::setOptionToUser()
{
    std::string option = "user";
    emit buttonPressedSignal(option);
}

void OptionGUI::handleOption(std::string option)
{
    this->option = option;
    this->close();

}