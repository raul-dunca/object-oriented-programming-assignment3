#pragma once
#include <QDialog>
#include <QLinearGradient>
//#include "everything.h"

class OptionGUI : public QDialog
{
    Q_OBJECT

public:
    OptionGUI();

    std::string getOption();


private:

    QPushButton* adminButton;
    QPushButton* userButton;
    std::string option;

    void initGUI();
    void connectSignalsAndSlots();


    void setOptionToAdmin();
    void setOptionToUser();

    void handleOption(std::string option);

signals:
    void buttonPressedSignal(std::string option);

};

//#pragma once
//#include <QDialog>
////#include "everything.h"
//
//class DisplayGUI : public QDialog
//{
//    Q_OBJECT
//
//public:
//    DisplayGUI();
//
//    std::string getOption();
//
//
//private:
//
//    QPushButton* adminButton;
//    QPushButton* userButton;
//    std::string option;
//
//    void initGUI();
//    void connectSignalsAndSlots();
//
//
//    void setOptionToAdmin();
//    void setOptionToUser();
//
//    void handleOption(std::string option);
//
//signals:
//    void buttonPressedSignal(std::string option);
//
//};