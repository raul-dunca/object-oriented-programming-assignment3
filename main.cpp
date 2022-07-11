#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QFormLayout>
#include <iostream>
#include<vector>
#include "Domain.h"
#include<fstream>
#include "OptionGUI.h"
#include "DomainGUI.h"
#include "UserGUI.h"
#include "FilterGUI.h"
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    //FilterGUI f;
    //f.show();
    OptionGUI mainGUI;
    mainGUI.exec();
    std::string userMode = mainGUI.getOption();

    // admin
    AdminGUI ad;
    UserGUI u;


    if (userMode == "admin")
    {
        ad.show();
    }
    else if (userMode == "user")
    {
        u.show();


    }


    return a.exec();
}
