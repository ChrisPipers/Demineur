#include "headers/views/viewendgame.h"
#include <iostream>

using namespace views;

viewEndGame::viewEndGame(Game &game)
{
    game_ = game;
    vBox = new QVBoxLayout();
    hBoxButton = new QHBoxLayout();

    QString QSTemp;
    if (game_.getResultGame())
    {
        QString qTemp("<font color='black'> WIN </font>");
        labResultPart = new QLabel ();
        labResultPart->setText(qTemp);
        labResultPart->setMaximumHeight(50);
        labResultPart->setMaximumWidth(350);
        labResultPart->setStyleSheet(" background-color : green; }");
        labResultPart->setAlignment(Qt::AlignCenter | Qt::AlignCenter);

        QFont font = labResultPart->font();
        font.setPointSize(20);
        font.setBold(true);

        labResultPart->setAlignment(Qt::AlignmentFlag::AlignHCenter);
        labResultPart->setFont(font);
    }
    else
    {
        QString qTemp("<font color='black'> LOSE </font>");
        labResultPart = new QLabel ();
        labResultPart->setText(qTemp);
        labResultPart->setMaximumHeight(50);
        labResultPart->setMaximumWidth(350);
        labResultPart->setStyleSheet(" background-color : red; }");
        labResultPart->setAlignment(Qt::AlignCenter | Qt::AlignCenter);

        QFont font = labResultPart->font();
        font.setPointSize(20);
        font.setBold(true);

        labResultPart->setAlignment(Qt::AlignmentFlag::AlignHCenter);
        labResultPart->setFont(font);
    }
    vBox->addWidget(labResultPart);

    string namePlayer = "name : " + game_.getPlayer().getName();
    labNamePlayer = new QLabel(QString::fromStdString(namePlayer));
    labNamePlayer->setMaximumHeight(50);
    labNamePlayer->setMaximumWidth(350);
    labNamePlayer->setAlignment(Qt::AlignCenter | Qt::AlignCenter);

    QFont font2 = labNamePlayer->font();
    font2.setPointSize(20);
    font2.setBold(true);
    labNamePlayer->setFont(font2);

    vBox->addWidget(labNamePlayer);

    string param = (string) "Board "+ ((to_string(game_.getBoard().getHeight()))+ " * " + (to_string(game_.getBoard().getWidth())) );
    labSizeBoard = new QLabel (QString::fromStdString(param));
    labSizeBoard->setMaximumHeight(50);
    labSizeBoard->setMaximumWidth(350);
    labSizeBoard->setAlignment(Qt::AlignCenter | Qt::AlignCenter);

    QFont font3 = labSizeBoard->font();
    font3.setPointSize(20);
    font3.setBold(true);

    labSizeBoard->setFont(font3);

    vBox->addWidget(labSizeBoard);


    string temps = to_string(((int)game_.getTimeT().getTimePassed()))+ "secondes écoulées";
    labTime = new QLabel(QString::fromStdString(temps));
    labTime->setAlignment(Qt::AlignCenter | Qt::AlignCenter);

    QFont font6 = labTime->font();
    font6.setPointSize(14);
    font6.setBold(true);
    labTime->setFont(font6);

    vBox->addWidget(labTime);

    butNewGame = new QPushButton("New Game", this);
    setStyleSheet("QPushButton {""background-color: green""}");
    butNewGame->setMaximumHeight(30);
    butNewGame->setMaximumWidth(160);

    QFont font4 = butNewGame->font();
    font4.setPointSize(14);
    font4.setBold(true);
    butNewGame->setFont(font4);

    connect(butNewGame, &QPushButton::clicked, this, (&viewEndGame::newGame) );

    hBoxButton->addWidget(butNewGame);

    butClose = new QPushButton("Close Game", this);
    setStyleSheet("QPushButton {""background-color: red""}");
    butClose->setMaximumHeight(30);
    butClose->setMaximumWidth(160);

    QFont font5 = butClose->font();
    font5.setPointSize(14);
    font5.setBold(true);
    butClose->setFont(font5);

    connect(butClose, &QPushButton::clicked, this, (&viewEndGame::closeGame) );

    hBoxButton->addWidget(butClose);

    vBox->addLayout(hBoxButton);

    setLayout(vBox);
    this->setFixedSize(350,350);
    resize(350, 350);

    setWindowTitle("DEMINEUR FIN DE PARTIE");

    this->show();
}

viewEndGame::~viewEndGame()
{
    delete vBox;
    delete hBoxButton;

    delete labNamePlayer;
    delete labResultPart;
    delete labSizeBoard;
    delete labTime;

    delete butClose;
    delete butNewGame;

    delete viewstart;
}

void viewEndGame::newGame()
{
    viewstart = new viewStart();
    viewstart->show();
    this->close();
}

void viewEndGame::closeGame()
{
    this->close();
}
