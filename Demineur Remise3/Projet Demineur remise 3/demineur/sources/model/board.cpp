#include "headers/model/board.h"
#include "headers/model/position.h"

#include <queue>
#include <iterator>
#include <iostream>
#include <cmath>
#include <string>
#include <ctype.h>

namespace model {
using namespace std;

Board::Board (int height, int width) : height_(height), width_(width)
{

    posBombs_.clear();
    posFlags_.clear();
    initBoard();
}

void Board::initBoard ()
{
    if( isInitilize_== false)
    {
        board_.clear();
        board_.resize(height_);
        for (int x = 0; x < height_; x++)
        {
            board_[x].clear();
            board_[x].resize(width_);
            for (int y = 0; y < width_; y++)
            {
                this->board_[x][y]='d';
            }

        }
    }
}

vector <vector<char>> Board::getBoard()
{
    return board_;
}

// la ou sont les bombes et les cases dark doivent avoir le meme affichage
void Board::placeBombs()
{
    if(isInitilize_==false)
    {
        int cpt = 0;
        set<std::pair<string,Position>>::iterator it ;;
        for (it= posBombs_.begin(); it != posBombs_.end(); it++ )
        {
            auto temp1 = *it;
            Position temp2= temp1.second;
            board_[temp2.getAbs()][temp2.getOrd()] = 'b';
            cpt++;
        }
        setIsInitilized(true);
    }
}

void Board::initBombs(int choice, Position position)
{
    try
    {
        if(choice < 1 || choice > 3 )
        {
            throw ("Choice not between 1 and 3");
        }
        else
        {
            switch(choice)
            {
                case 1 : defaultBombs(position);
                    break;
                case 2 : pourcentBombs(position);
                    break;
                case 3 : nbBombs(position);
                    break;
            }
        }
    }
    catch(const out_of_range& e)
    {
throw (e);
    }
}


void Board::defaultBombs(Position position)
{
    double nbBombD =  (((0.0002*pow((height_*width_),2))+(0.0938*(height_*width_))+(0.8937))+0.5);
    int nbBomb = (int) nbBombD;
    initPosBombs(nbBomb, position);
}

// utilisation de l attribut percentMine_
void Board::pourcentBombs(Position position)
{
    int nbBomb = ((height_*width_)*(percentMine_));
    initPosBombs(nbBomb, position);
}

// utilisation de l attribut nbMine_
void Board::nbBombs(Position position)
{
    initPosBombs(nbMine_, position);
}

void Board::initPosBombs(unsigned nbBombs, Position position)
{
    if(isInitilize_==false)
    {
        this->nbMine_=nbBombs;
        posBombs_.clear();
        int x, y =0;
        while( posBombs_.size() != nbBombs )
        {
            x = rand() % height_;
            y = rand() % width_;
            Position pos= Position(x,y);
            string key = ""+ to_string(x)+","+ to_string(y);

            auto it2 = posBombs_.find(make_pair(key,pos));
            // test inutile car set refuse les doublons
            if ( ( it2 == posBombs_.end()) && !(pos==position) )
            {
                posBombs_.insert(make_pair(key,pos));
            }
        }
        this->placeBombs();
    }
}

int Board::getNbBombs()
{
    return this->nbMine_;
}

int Board::getHeight()
{
    return this->height_;
}

int Board::getWidth()
{
    return this->width_;
}

char Board::getValPosition( Position position)
{
    return board_[position.getAbs()][position.getOrd()];
}

// attention pour eviter toute confusion
// cette position est la position ou il n y aura pas de bombes
void Board::revelantPosFirst(int choice, Position position)
{
    try
    {
        if(choice <1 || choice >3)
        {
            throw ("choice must be between 1 and 3");
        }
        else
        {
            placeClearPosition(position);
            initBombs(choice, position);
            revelantPositionRecursif(position);
        }
    }
    catch(out_of_range& e)
    {
        cerr << e.what() << endl;
    }
}

int Board::nbMineArround(Position position)
{
    int nbMine = 0 ;
    if(inBoard(Position(position.getAbs()+1, position.getOrd()))
        && getValPosition(Position(position.getAbs()+1, position.getOrd()))=='b')
    {
        nbMine++;
    }
    if(inBoard(Position(position.getAbs()-1, position.getOrd()))
        && getValPosition(Position(position.getAbs()-1, position.getOrd()))=='b')
    {
        nbMine++;
    }
    if(inBoard(Position(position.getAbs()+1, position.getOrd()-1))
        && getValPosition(Position(position.getAbs()+1, position.getOrd()-1))=='b')
    {
        nbMine++;
    }
    if(inBoard(Position(position.getAbs()+1, position.getOrd()+1))
        && getValPosition(Position(position.getAbs()+1, position.getOrd()+1))=='b')
    {
        nbMine++;
    }
    if(inBoard(Position(position.getAbs()-1, position.getOrd()-1))
        && getValPosition(Position(position.getAbs()-1, position.getOrd()-1))=='b')
    {
        nbMine++;
    }
    if(inBoard(Position(position.getAbs()-1, position.getOrd()+1))
        && getValPosition(Position(position.getAbs()-1, position.getOrd()+1))=='b')
    {
        nbMine++;
    }
    if(inBoard(Position(position.getAbs(), position.getOrd()+1))
        && getValPosition(Position(position.getAbs(), position.getOrd()+1))=='b')
    {
        nbMine++;
    }
    if( inBoard(Position(position.getAbs(), position.getOrd()-1))
            &&getValPosition(Position(position.getAbs(), position.getOrd()-1))=='b')
    {
        nbMine++;
    }
    return nbMine;
}


// et ici le bool peut retourner false ou true selon qu il
// y a une bombe ou non a la pos en param
bool Board::revelantPositionRecursif(Position position)
{
    if(getValPosition(position)=='b')
    {
        return true;
    }
    else
    {
        queueToVisit_.push(position);

        while (!queueToVisit_.empty())
        {
            position = queueToVisit_.front();
            queueToVisit_.pop();
            if(inBoard(position))
            {
                int nbMine=0;
                if( (getValPosition(position)!='b')
                    && (getValPosition(position)!='f')
                    && (isdigit(getValPosition(position))==false))
                {
                    nbMine = nbMineArround(position);
                    if (nbMine==0)
                    {
                        placeClearPosition(position);
                        placeToQueue(Position(position.getAbs()-1,position.getOrd()));
                        placeToQueue(Position(position.getAbs()+1,position.getOrd()));
                        placeToQueue(Position(position.getAbs(),position.getOrd()-1));
                        placeToQueue(Position(position.getAbs(),position.getOrd()+1));
                        placeToQueue(Position(position.getAbs()-1,position.getOrd()-1));
                        placeToQueue(Position(position.getAbs()-1,position.getOrd()+1));
                        placeToQueue(Position(position.getAbs()+1,position.getOrd()-1));
                        placeToQueue(Position(position.getAbs()+1,position.getOrd()+1));
                    }
                    else
                    {
                        placeIndicePosition(position, nbMine);
                        nbMine = 0;
                    }
                }
            }
        }

        return false;
    }
}

void Board::placeToQueue(Position position)
{
    if( (inBoard(position))

        && (getValPosition(Position(position.getAbs(),position.getOrd()))!='b')
        && (getValPosition(Position(position.getAbs(),position.getOrd()))!='f')
        && (getValPosition(Position(position.getAbs(),position.getOrd()))!='c')
        && !(isdigit(getValPosition(position))) )

    {
        queueToVisit_.push(position);
    }
}

bool Board::inBoard(Position position)
{
    if (position.getAbs()>=0 && position.getAbs() < height_
            && position.getOrd()>=0 && position.getOrd()< width_)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Board::placeFlagPosition(Position position)
{
       if ( inBoard(position) && (getValPosition(position)== 'd' || getValPosition(position)== 'b') )
       {
            board_[position.getAbs()][position.getOrd()]='f';
        }
        else
        {
            throw ("position to place flag no valide ");
        }
}

void Board::deleteFlagPosition(Position position)
{
    string key = to_string(position.getAbs())+","+to_string(position.getOrd());
    if(!inBoard(position) && getValPosition(position)!='f')
    {
        //cout << "Pas de drapeau à cette position" << endl;
    }            
    else
    {
        if ((posBombs_.count(make_pair(key,position)))!=0)
        {
            board_[position.getAbs()][position.getOrd()]='b';
        }
        else
        {
            board_[position.getAbs()][position.getOrd()]='d';
        }
    }
}

void Board::placeClearPosition(Position position)
{

        board_[position.getAbs()][position.getOrd()]='c';

}

void Board::placeIndicePosition(Position position, int indice)
{
    try
    {
        if (indice < 1 || indice > 8)
        {
            throw ("the indice must be between 1 and 8");
        }
        else
        {
            board_[position.getAbs()][position.getOrd()]= (char) indice+48;
        }
    }
    catch(const out_of_range& e)
    {
        throw (e);
    }
}

void Board::displayBoard()
{
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            cout << " | " << board_[i][j] << " " ;
        }
        cout << "|" << endl;
    }
    cout << endl << endl;
}

void Board::displayBoardForPlayer()
{
    for (int i = 0; i < height_;i++) {
        for (int j = 0; j < width_; j++) {
            if (board_[i][j]=='b')
            {
                cout << " | " << 'd' << " " ;

            }
            else
            {
                cout << " | " << board_[i][j] << " " ;
            }
        }
        cout << "|" << endl;
    }
    cout << endl << endl;
}

void Board::setPourcentMines(double percentMine_)
{
    if(percentMine_>0.90 || percentMine_<0.05)
    {
        throw string("pourcent of bombs select is to bigger , select less to 100% or more bigger to 5%");
    }
    else
    {
        this->percentMine_ = percentMine_;
    }
}

void Board::setNbMines(int nbMine_)
{
    if(nbMine_>=(height_*width_) || nbMine_ < 1)
    {
        throw string("number of bombs select is to bigger, select less to 100%");
    }
    else
    {
        this->nbMine_ = nbMine_;
    }
}

void Board::updateboard()
{
    //system("cls");
    //cout << endl << endl;
    //displayBoardForPlayer();
    //cout << "nombre de bombes : " <<nbMine_<< endl;
}

void Board::setIsInitilized(bool init)
{
    this->isInitilize_=init;
}

bool Board::getIsInitilized()
{
    return this->isInitilize_;
}

}//end namespace model
