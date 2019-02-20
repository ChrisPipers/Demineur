#include <string>

#include "headers/views/viewstart.h"
#include "headers/views/viewparameter.h"

using namespace views;

viewStart::viewStart()
{
    vBox = new QVBoxLayout;

    hBox = new QHBoxLayout;

    labTitreGame = new QLabel(" MINESWEEPER ");
    labTitreGame->setAlignment(Qt::AlignCenter);
    QFont font = labTitreGame->font();
    font.setPointSize(30);
    font.setBold(true);
    labTitreGame->setFont(font);
    vBox->addWidget(labTitreGame);

    butPlay = new QPushButton("New Game", this);
    connect(butPlay, &QPushButton::clicked, this, (&viewStart::newGame));
    hBox->addWidget(butPlay);

    butPalmares = new QPushButton("Palmares", this);
    connect(butPalmares, &QPushButton::clicked, this, (&viewStart::palmares));
    hBox->addWidget(butPalmares);

    vBox->addLayout(hBox);
    setLayout(vBox);

    resize(400, 200);
    this->setFixedSize(400,200);
    setWindowTitle("MINESWEEPER");

    this->show();
}

viewStart::~viewStart()
{
    delete vBox;

    delete hBox;

    delete labTitreGame;

    delete butPlay;

    delete butPalmares;

    delete viewparameter;

}


void viewStart::newGame()
{
    viewparameter = new viewParameter();
    viewparameter->show();
    this->close();
}

void viewStart::palmares()
{
    game = Game();
    game.readPalmares();
    string sPalmares;
    vector<vector<string>> vPalmares = game.getVPalmares();
    vector<string> vTemp;
    if(vPalmares.size()>0)
    {
        for (unsigned i = 0; i < vPalmares.size(); i++) {
            vTemp = vPalmares.at(i);
            sPalmares += "Meilleur score de: " +vTemp[0]  + "\t"
                    + "plateau de taille: " + vTemp[1] + " x " + vTemp[2] + " " + "\t"
                    + "temps mis: " + vTemp[2] + " secondes "
                    + "\n";

        }
    }

    QMessageBox sMessBoxPalmares;
    sMessBoxPalmares.setText(QString::fromStdString(sPalmares));
    sMessBoxPalmares.setWindowTitle("PALMARES DEMINEUR");
    sMessBoxPalmares.exec();

}



