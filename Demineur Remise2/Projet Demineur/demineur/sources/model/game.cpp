#include "headers/model/game.h"
#include "headers/model/player.h"
#include "headers/model/board.h"
#include "headers/model/position.h"
#include "headers/model/ruleendgame.h"
#include "headers/model/timeT.h"

#include "headers/model/keyboard.hpp"
#include "headers/model/stringConvert.hpp"

#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

namespace model {
using namespace std;

Game::Game()
{
    bool endGame;
    timeEnd = 0;
    board_.addObserver(this);
    Position pos ;
    this->isEnd_=false;
    initPlayer();
    selectSizeBoard();
    int choice = choiceTypePart();
    string actionS = selectAction();
    pos = selectPositionToAction();
    isEnd(board_);
    firstAction(pos,actionS,choice);
    isEnd(board_);

    system("cls");
    cout << endl << endl;
    board_.displayBoardForPlayer();
    cout << "nombres de bombes : " << board_.getNbBombs() << endl << endl;;
    while( !isEnd_)
    {

        cout << endl << endl;
        board_.displayBoardForPlayer();
        cout << "nombres de bombes : " << board_.getNbBombs() << endl << endl;;
        time_.setTimePassed();
        cout << "temps : " <<  time_.getTimePassed()<< endl;
        savePart();

        actionS = selectAction();
        pos = selectPositionToAction();

        char action = (char) actionS.at(0);
        switch(action)
        {
            case 'c' : endGame=(board_.revelantPositionRecursif(pos));

                break;
            case 'f' : board_.placeFlagPosition(pos);
                break;
            case 'd' : board_.deleteFlagPosition(pos);
                break;
         }
        cout << endl << endl;
        isEnd(board_);
        if (isEnd_)
        {
            cout << "   ************************************   " << endl << endl;
            cout << " **** **** ****   Gagner   **** **** **** " << endl << endl;
            cout << "   ************************************   " << endl;
            savePart();
        }
        else
        {
            if(endGame==true)
            {
                system("cls");
                cout << " bombe a la position : " << pos.getAbs() << ", " << pos.getOrd() << endl << endl;;
                board_.displayBoard();
                setIsEnd();
                cout << "   ***********************************   " << endl << endl;
                cout << " **** **** ****   Perdu   **** **** **** " << endl << endl;
                cout << "   ***********************************   " << endl;
            }
        }
    }
}


void Game::initPlayer()
{
    string name, act;
    cout << "Entrer votre nom :" << endl;
    cin >> act ;
    name = nvs::toString(act);
    player_.setName(name);

}

void Game::isEnd(Board board)
{
    isEnd_ = ruleEndGame_.getIsEnd(board);
    if(isEnd_)
    {
        timeEnd = time_.getTimePassed();
    }
}

void Game::revelantPosFirst()
{
    Position position;
    bool posV ;
    do
    {
        int x, y;
        cout << "Entrez la coordonnée x " << endl;
        cin >> x;
        cout << "Entrez la coordonnée y " << endl;
        cin >>y;
        position = Position(x,y);
        posV = posValide(position);

    }while(posV);
    int choicePart = choiceTypePart();
    manageChoice(choicePart);
}

int Game::choiceTypePart()
{
    int i = {-1};
    do    
    {
        try
        {
            cout << "valeur pour le type d initilisation du nombre de bombes (dans [0, 3]) : ";
            i = nvs::lineFromKbd<int>();
        }
        catch (const exception & e)
        {
            cout << "problème choix partie: " << e.what() << endl;
        }

        if(i==0)
        {
            helpDisplayChoice();
        }
    }
    while (i < 1 || i > 3);
    manageChoice(i);
    return i;
}

void Game::selectSizeBoard()
{
    int x = {-1};
    do
    {
        try
        {
            cout << "selectionner la longeur du plateau (dans [5, 20]) : ";
            x = nvs::lineFromKbd<int>();
        }
        catch (const exception & e)
        {
            cout << "problème longueur board: " << e.what() << endl;
        }
    }
    while (x < 5 || x > 20);

    int y = {-1};
    do
    {
        try
        {
            cout << "selectionner la largeur du plateau (dans [5, 20]) : ";
            y = nvs::lineFromKbd<int>();
        }
        catch (const exception & e)
        {
            cout << "problème largeur board : " << e.what() << endl;
        }
    }
    while (y < 5 || y > 20);

    board_=Board(x,y);
}

void Game::helpDisplayChoice()
{
    cout << "-----------------------------------------------" << endl;
    cout << "Help" << endl;
    cout << "Vous avez le choix entre 3 types de partie : " << endl;
    cout << setw(8) << "1 :" << endl;
    cout << setw(12) << "Nombre de mines par défaut" << endl;
    cout << setw(8) << "2 :" << endl;
    cout << setw(12) << "Pourcentage de mines que vous séléctionneé" << endl;
    cout << setw(8) << "3 :" << endl;
    cout << setw(12) << "Nombre de mines que vous séléctionné" << endl;
    cout << "-----------------------------------------------" << endl;
}

void Game::manageChoice(int choicePart)
{
    switch(choicePart)
    {
        case 2 : validAndDefinePourcentBombs();
            break;
        case 3 : validAndDefineNbBombs();
            break;
    }
}

void Game::validAndDefinePourcentBombs()
{
    int intPourcent;
    do
    {
        try
        {
            cout << "selectionner le pourcentage de mines (dans [5, 90]) : ";
            intPourcent = nvs::lineFromKbd<int>();
        }
        catch (const exception & e)
        {
            cout << "problème pourcent bombes: " << e.what() << endl;
        }
    }
    while (intPourcent < 5 || intPourcent > 90);

    double pourcentMine = (double) intPourcent;
    pourcentMine = pourcentMine/100;
    board_.setPourcentMines(pourcentMine);
}

void Game::validAndDefineNbBombs()
{
    int nb;
    do
    {
        cout << "Entrez le pourcentage de bombes souhaité sur le plateau" << endl;
        cout << "Pourcentage entre 5% et 90%" << endl;
        cin >> nb ;
    }while(nb<5 && nb>((board_.getHeight()*board_.getWidth()-10)));
    // longueur*largeur -10 car il faut un minimum pour avoir un jeu jouable

    board_.setNbMines(nb);
}

bool Game::posValide(Position position)
{
    if (position.getAbs()>=0 && position.getAbs()<board_.getHeight()
            && position.getOrd()>=0 && position.getOrd()<board_.getWidth())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Game::getIsStart()
{
    return this->isStart_;
}

void Game::setIsStart()
{
    this->isStart_ = true;
}

string Game::selectAction()
{
    string act="";
    string action="";

    do
    {
        cout << " entrer  \"flag\" pour poser un drapau" << endl ;
        cout << " entrer \"clear\" pour reveler une pour reveler une position " <<endl;
        if (isStart_==true)
        {
            cout << " entrer \"deflag\" pour enelever un drapeau à une position " << endl;
        }
        cin >> act ;
        action = nvs::toString(act);
    }while( !((action=="flag") || (action=="clear") || (action=="deflag")));

    return action;
}

Position Game::selectPositionToAction()
{
    Position pos = Position(-1,-1);
    int x = {-1};
    do
    {
        cout << "********** entrer position **********"<< endl;
        do
        {
            try
            {
                cout << "selectionner abscisse pour la position (dans [0, "+to_string(board_.getHeight()-1)+"]) : ";
                x = nvs::lineFromKbd<int>();
            }
            catch (const exception & e)
            {
                cout << "problème select abscisse : " << e.what() << endl;
            }
        }
        while (x < 0 || x > board_.getHeight()-1);

        int y = {-1};
        do
        {
            try
            {
                cout << "selectionner ordonnee pour la position (dans [0, "+to_string(board_.getWidth()-1)+"]) : ";
                y = nvs::lineFromKbd<int>();
            }
            catch (const exception & e)
            {
                cout << "problème select ordonnee : " << e.what() << endl;
            }
        }
        while (y < 0 || y > board_.getWidth()-1);

        pos = Position(x,y);
    }while( !(((board_.getValPosition(pos)=='d') || (board_.getValPosition(pos)=='b'))) );

    return pos;
}


void Game::firstAction(Position position, string sAction, int choice)
{
    char action = (char) sAction.at(0);
    switch(action)
    {
        case 'c' :  board_.revelantPosFirst(choice, position);
                    setIsStart();
                    break;
        case 'f' :  board_.placeFlagPosition(position);
                    setIsStart();
                    break;
     }
    time_ = TimeT();
    ruleEndGame_ = RuleEndGame(board_);
}

void Game::setIsEnd()
{
    isEnd_ = true;
}

void Game::update()
{
    board_.updateboard();
}

void Game::savePart()
{
    string toSave;
    toSave += "name : " +player_.getName()+" * ";
    toSave += "size board : " + to_string(board_.getHeight()) + " * " + to_string(board_.getWidth()) + " " ;
    toSave += "in time : " + to_string(timeEnd) + " " ;

    ofstream textfile ("../palmares.txt", ios::app);
    if(!textfile.is_open())
        {
            cerr << " not open " << endl;
        }
        else
        {
            cout << " ouvert " << endl ;
            cout << toSave << endl;
        }

        textfile << toSave;
        textfile << '\n';
        textfile.close();

}


}//end namespace model
