#include <QGridLayout>
#include <QBoxLayout>
#include <QApplication>
#include <QMainWindow>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QLCDNumber>
#include <QMessageBox>

#include <iostream>
#include <string>

#include <iostream>
#include "headers/views/viewmainwindow.h"
#include "headers/model/game.h"

using namespace model;
using namespace views;
using namespace std;

ViewMainWindow::ViewMainWindow(string namePlayer, int height, int width, int choice, int intNbBombs, int percentBombs)
{
    game_ = Game(namePlayer, height, width, choice, intNbBombs, percentBombs);
    // tout les new sont delete dans le destructeur qui suit,
    // indirectement lier au boardgui les cases le composant
    // sont detruite dans la classe case.cpp par le destructeur
    vbox_ = new QVBoxLayout ;
    viewBoard_ = new ViewBoard(game_);
    hbox_ = new QHBoxLayout ;

    //** time
    hboxTime_ = new QHBoxLayout;

    textTime_ = new QLabel("Time : ");
    textTime_->setMaximumSize(100,60);
    hboxTime_->addWidget(textTime_);

    time_ = new QLCDNumber();
    time_->setMaximumSize(80,60);
    hboxTime_->addWidget(time_);

    vbox_->addLayout(hboxTime_);

    vbox_->addLayout(viewBoard_);

    //** name player
    vboxNamePlayer_ = new QVBoxLayout;

    string tempS = game_.getPlayer().getName();
    QString tempQS = QString::fromStdString(tempS);
    nomPlayer_ = new QLabel(tempQS);
    nomPlayer_->setMaximumSize(100,60);
    vboxNamePlayer_->addWidget(nomPlayer_);

    hbox_->addLayout(vboxNamePlayer_);

    //** nb bombs
    hboxNbBombs_ = new QHBoxLayout;

    textNbBombs_ = new QLabel("number bombs : ");
    textNbBombs_->setMaximumSize(80,60);
    hboxNbBombs_->addWidget(textNbBombs_);

    nbBombs_ = new QLCDNumber();
    nbBombs_->setMaximumSize(100,60);
    hboxNbBombs_->addWidget(nbBombs_);
    hbox_->addLayout(hboxNbBombs_);

    vbox_->addLayout(hbox_);
    setLayout(vbox_);
    game_.addObserver(this);
    setWindowTitle("Minesweeper");
    resize(400,400);
    this->show();
}

ViewMainWindow::~ViewMainWindow()
{
    delete vbox_;
    delete hbox_;
    delete hboxTime_;
    delete vboxNamePlayer_;
    delete hboxNbBombs_;

    delete viewBoard_;

    delete textNbBombs_;
    delete textTime_;

    delete nomPlayer_;
    delete nbBombs_;
    delete time_;
    delete viewendgame;

    game_.delObserver(this);
}

void ViewMainWindow::update(){
    viewBoard_->updateViewBoard();
    time_->display((int)game_.getTimeT().getTimePassed());
    nbBombs_->display((int)game_.getBoard().getNbBombs());
    if(this->game_.getIsEnd())
    {
        QMessageBox sMessBoxPalmares;
        sMessBoxPalmares.setText("Game is end");
        sMessBoxPalmares.setWindowTitle("Info");
        sMessBoxPalmares.exec();

        if(game_.getResultGame())
        {
            game_.savePart();
        }
        viewendgame = new viewEndGame(this->game_);
        viewendgame->show();
        this->close();
    }
}


