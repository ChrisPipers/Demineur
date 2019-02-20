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
#include <vector>

namespace model {
using namespace std;

// game for model mode console
/*
Game::Game()
{
    bool endGame;
    time_ = TimeT();
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
    displayGame();

    while( !isEnd_)
    {
        displayGame();
        endGame = play();
        cout << endl << endl;
        isEnd(board_);
        if (isEnd_)
        {
            manageWin();
        }
        else
        {
            if(endGame==true)
            {
                manageLose(pos);
            }
        }
    }
}
*/


Game::Game()
{

}


Game::Game(string namePlayer, int height, int width, int choice, int nbBombs, int percentBombs)
{
    choice_ = choice + 1;
    player_.setName(namePlayer);
    board_ = Board(height, width);

    if(nbBombs>5)
    {
        board_.setNbMines(nbBombs);
    }

    if(percentBombs>=5)
    {
        double temp = (double) percentBombs/100;
        board_.setPourcentMines(temp);
    }

    isEnd_ = false;
    setResultGame(-1);
}

Game::~Game()
{

}

Board &Game::getBoard(){
    return this->board_;
}

void Game::initPlayer()
{
    string name, act;
    cout << "Entrer votre nom :" << endl;
    cin >> act ;
    name = nvs::toString(act);
    player_.setName(name);

}

void Game::isEnd(Board board_)
{
    isEnd_ = ruleEndGame_.getIsEnd(board_);
    if(ruleEndGame_.getIsEnd(board_))
    {
        setIsEnd();
        setResultGame(true);
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
    this->notifyObserver();
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

    board_ = Board(x,y);
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
    }while( !(((board_.getValPosition(pos)=='d') || (board_.getValPosition(pos)=='b'))  || (board_.getValPosition(pos)=='f')) );

    return pos;
}


void Game::firstAction(Position position, string sAction, int choice)
{
    cout << position.getAbs() << " " << position.getOrd() << endl;
    char action = (char) sAction.at(0);
    switch(action)
    {
        case 'c' :  board_.revelantPosFirst(choice, position);
                    setIsStart();
                    break;
        case 'f' :  board_.initBombs(choice, Position(-1,-1));
                    board_.placeFlagPosition(position);
                    setIsStart();
                    break;
     }
    time_.resetTimePassed();
    ruleEndGame_ = RuleEndGame(board_);
    this->notifyObserver();
}

void Game::setIsEnd()
{
    isEnd_ = true;
}

void Game::update()
{
    board_.updateboard();
    notifyObserver();
}

void Game::savePart()
{
    // etoile et point pour un delimiteur de recherche
    string toSave;
    string heightSize;
    string widthSize;
    toSave += "*" + player_.getName() + ".";

    // permet d avoir une chaine formater à la meme taille
    if (board_.getHeight()<10)
    {
        heightSize = "0" + to_string(board_.getHeight());
    }
    else
    {
        heightSize = to_string(board_.getHeight());
    }

    if (board_.getWidth()<10)
    {
        widthSize = "0" + to_string(board_.getWidth());
    }
    else
    {
        widthSize = to_string(board_.getWidth());
    }

    toSave += "*"+heightSize+"."+ "*"+widthSize+"." ;
    toSave += "*" + to_string(board_.getNbBombs()) +".";
    toSave += "*"+to_string(time_.getTimePassed())+".";

    readPalmares();

    unsigned it = 0;

    selectSavePalmares(toSave);

    ofstream textfile ("../palmares.txt", ios::out | ios::trunc );
    if(!textfile.is_open())
    {
        cerr << " not open save part " << endl;
    }
    else
    {
        it = 0;
        while(it < palmares_.size())
        {
            string temp = vectorToString(palmares_[it]);
            if(temp.size()>2)
            {
                textfile << temp << "\n";
            }
            it++;
        }
    }
    textfile.close();
}

void Game::readPalmares()
{
    palmares_.clear();
    ifstream textfile ("../palmares.txt", ios::app);
    string line;

    if(!textfile.is_open())
    {
        cerr << " not open read palmares " << endl;
    }
    else
    {
        //cout << " open read palmares " << endl ;
    }

    while(!textfile.eof())
    {
        getline(textfile, line);
        palmares_.push_back(stringToVector(line));
    }
    textfile.close();
}

int Game::getChoice()
{
    return this->choice_;
}

vector<string> Game::stringToVector(string chaineToConv)
{
    string temp1;
    bool start;
    vector<string> vLine ;

    for (char & c : chaineToConv)
    {
        if(c == '*')
        {
            start=true;
        }
        if(c == '.')
        {
            vLine.push_back(temp1);
            temp1.clear();
            start=false;
        }
        if(start==true && (c!='*'))
        {
            temp1 += c;
        }
    }
    return vLine;
}

string Game::vectorToString(vector<string>vectToConv)
{
    string temp;
    unsigned i = 0;
    while(i<vectToConv.size())
    {
        temp += "*"+vectToConv[i]+".";
        i++;
    }
    return temp;
}

void Game::selectSavePalmares(string newResultS)
{
    bool find = false;
    bool add = false;
    unsigned i= 0, j=1;
    vector<string> vLine;
    vector<string> newResult = stringToVector(newResultS);
    vLine = palmares_.at(0);
    if(palmares_.size()>1) {
    while( (!find) && i<palmares_.size() && palmares_.size()>0 )
    {
        vLine = palmares_.at(i);
        find = true;
        //each line -> name height width nbBombs time
        //             1    2      3     4       5
        //             0    1      2     3       4
        if(vLine.size()>0){
            while(j<4 && find )
            {
                if(newResult[j]==vLine[j])
                {
                    find = true;
                }
                else
                {
                    find = false;
                }
                j++;
            }

            string temp88 = vectorToString(vLine);
            if(find)
            {
                int a = stoi(newResult[4]);
                int b = stoi(vLine[4]);
                if(a<b)
                {
                    palmares_.erase(palmares_.begin()+i);
                    palmares_.push_back(newResult);
                    add = true;
                }
            }
        }
        j = 1;
        i++;

    }
    }
    if(!add)
    {
        string temp8 = vectorToString(newResult);
        palmares_.push_back(newResult);
    }

    unsigned indice = 0;
    while(indice< palmares_.size())
    {
        string tempind = vectorToString(palmares_.at(indice));
        indice++;
    }
}

// play for the model mode console
bool Game::play()
{
    string actionS;
    Position pos;
    bool endGame = false;
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
    this->notifyObserver();
    if(endGame)
    {
        setIsEnd();
    }
    return endGame;
}

//play for view
bool Game::play(Position pos, char action)
{
    bool endGame = false;
    time_.setTimePassed();
    switch(action)
    {
        case 'c' : endGame=(board_.revelantPositionRecursif(pos));
            break;
        case 'f' : board_.placeFlagPosition(pos);
            break;
        case 'd' : board_.deleteFlagPosition(pos);
            break;
     }   
    //board_.displayBoard();

    this->notifyObserver();
    return endGame;
}

Player Game::getPlayer()
{
    return this->player_;
}

void Game::displayGame()
{
    //system("cls");
    //cout << endl << endl;
    //board_.displayBoardForPlayer();
    //board_.displayBoard();
    //cout << endl;
    //cout << "nombres de bombes : " << board_.getNbBombs() << endl << endl;
    //time_.setTimePassed();
    //cout << "time : " << time_.getTimePassed() << endl;
}

void Game::manageLose(Position pos)
{
    system("cls");
    cout << " bombe a la position : " << pos.getAbs() << ", " << pos.getOrd() << endl << endl;;
    //board_.displayBoard();
    setIsEnd();
    cout << " temps : " << time_.getTimePassed() << endl;
    cout << "   ***********************************   " << endl << endl;
    cout << " **** **** ****   Perdu   **** **** **** " << endl << endl;
    cout << "   ***********************************   " << endl;
    this->notifyObserver();
}

void Game::manageWin()
{
    cout << "   ************************************   " << endl << endl;
    cout << " **** **** ****   Gagner   **** **** **** " << endl << endl;
    cout << "   ************************************   " << endl;
    savePart();
    this->notifyObserver();
}

TimeT Game::getTimeT()
{
    return this->time_;
}

bool Game::getIsEnd()
{
    return this->isEnd_;
}

bool Game::getResultGame()
{
    return this->win_;
}

vector<vector<string>> Game::getVPalmares()
{
    return this->palmares_;
}


void Game::setResultGame(bool result)
{
    this->win_ = result;
}

}//end namespace model
