
#include <QApplication>
#include "headers/views/viewstart.h"
#include "headers/views/viewparameter.h"

//#ifndef RUNTEST   //décomenter pour lancer les tests
//#define CATCH_CONFIG_MAIN

using namespace views;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    viewStart vS;
    vS.show();
    return a.exec();
}

//#endif    //décomenter pour lancer les tests
