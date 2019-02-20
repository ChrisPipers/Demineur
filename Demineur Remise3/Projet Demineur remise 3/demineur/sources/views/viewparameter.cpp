#include "headers/views/viewparameter.h"
#include <iostream>
using namespace views;

viewParameter::viewParameter()
{
    vBox = new QVBoxLayout();

    labInitBombs = new QLabel("Choice initialize bombs");
    vBox->addWidget(labInitBombs);

    choiceInit = new QComboBox();
    choiceInit->addItem("Default");
    choiceInit->addItem("Pourcent of bombs select");
    choiceInit->addItem("Number of bombs select");
    connect(choiceInit, &QComboBox::currentTextChanged,this,(&viewParameter::update));
    vBox->addWidget(choiceInit);

    labHeight = new QLabel("Height of board [5 to 13]");
    editHeight = new QLineEdit;
    editHeight->setValidator(new QIntValidator(0,100,this));
    editHeight->setText("9");
    vBox->addWidget(labHeight);
    vBox->addWidget(editHeight);

    labWidth = new QLabel("Width of board [5 to 18]");
    editWidth = new QLineEdit;
    editWidth->setValidator(new QIntValidator(0,100,this));
    editWidth->setText("9");
    vBox->addWidget(labWidth);
    vBox->addWidget(editWidth);

    labNbBombs = new QLabel("Number of bombs selected [1 to ((height*width)-5)]");
    labNbBombs->setVisible(false);
    editNumberBombs = new QLineEdit;
    editNumberBombs->setValidator(new QIntValidator(0,100,this));
    editNumberBombs->setVisible(false);
    vBox->addWidget(labNbBombs);
    vBox->addWidget(editNumberBombs);

    labPerBombs= new QLabel("Percent of bombs selected [5 to 95]");
    labPerBombs->setVisible(false);
    editPourcentBombs = new QLineEdit;
    editPourcentBombs->setValidator(new QIntValidator(0,100,this));
    editPourcentBombs->setVisible(false);
    vBox->addWidget(labPerBombs);
    vBox->addWidget(editPourcentBombs);

    labNamePlayer = new QLabel("Enter your name");
    editNamePlayer = new QLineEdit();
    editNamePlayer->setMaxLength(10);
    vBox->addWidget(labNamePlayer);
    vBox->addWidget(editNamePlayer);

    play = new QPushButton("Play", this);
    play->setMaximumHeight(30);
    play->setMaximumWidth(60);
    connect(play, &QPushButton::clicked, this, (&viewParameter::launch) );
    vBox->addWidget(play);

    resize(350, 350);
    this->setFixedSize(350,350);
    setWindowTitle("Minesweeper parameter part");

    setLayout(vBox);
}

viewParameter::~viewParameter()
{
    delete vBox;

    delete labInitBombs;
    delete labHeight;
    delete labWidth;
    delete labNbBombs;
    delete labPerBombs;
    delete labNamePlayer;

    delete choiceInit;

    delete editHeight;
    delete editWidth;
    delete editNumberBombs;
    delete editPourcentBombs;
    delete editNamePlayer;

    delete mainWin;
    delete play;
}

void viewParameter::launch()
{

    QString temp;
    bool ok;
    temp = editNamePlayer->text();
    string namePlayer = temp.toStdString();

    temp = editHeight->text();
    int height = QString::fromStdString(temp.toStdString()).toInt(&ok);

    temp = editWidth->text();
    int width= QString::fromStdString(temp.toStdString()).toInt(&ok);

    int choice = choiceInit->currentIndex();

    temp = editNumberBombs->text();
    int nbBombs = QString::fromStdString(temp.toStdString()).toInt(&ok);

    temp = editPourcentBombs->text();
    int percentBombs = QString::fromStdString(temp.toStdString()).toInt(&ok);

    if( ((namePlayer.size()>=2) && (( (choice==2) && (nbBombs <= ((height*width)-5)) && (nbBombs > 0) )
                || ((choice==1) && (percentBombs >=5) && (percentBombs <=95))
                || (choice==0)) ) )
           // && (width > 5 && width <= 18) && (height > 5 && height <= 18))
    {
    mainWin = new ViewMainWindow(namePlayer, height, width, choice, nbBombs, percentBombs);
    mainWin->show();
    this->close();

    }
}

void viewParameter::update()
{
    if (choiceInit->currentIndex()==1)
    {
        labPerBombs->setVisible(true);
        editPourcentBombs->setVisible(true);
        labNbBombs->setVisible(false);
        editNumberBombs->setVisible(false);
    }
    if (choiceInit->currentIndex()==2)
    {
        labPerBombs->setVisible(false);
        editPourcentBombs->setVisible(false);
        labNbBombs->setVisible(true);
        editNumberBombs->setVisible(true);
    }
    if (choiceInit->currentIndex()==0)
    {
        labPerBombs->setVisible(false);
        editPourcentBombs->setVisible(false);
        labNbBombs->setVisible(false);
        editNumberBombs->setVisible(false);
    }
}



