#include "headers/model/ruleendgame.h"
#include "headers/model/board.h"
#include <iostream>
namespace model {
using namespace std;

RuleEndGame::RuleEndGame()
{

}

RuleEndGame::RuleEndGame(Board & board)
{
    this->board_ =  board;
    this->isEnd_ = false;
}

// on verif si ya autant de dark que de bombes
void RuleEndGame::allClear()
{
    int nbDark=0, nbBombs=0, i=0, j = 0;
    while (i < board_.getWidth())
    {
        j = 0;
        while (j < board_.getHeight())
        {
            char temp = board_.getValPosition(Position(i,j));
            if ( temp == 'd' )
            {
               nbDark++;
            }
            if( temp == 'b')
            {
                nbBombs++;
            }
            j++;
        }
        i++;
    }
    if( (nbBombs==board_.getNbBombs()&& nbDark==0) )
    {
        setIsEnd();
    }
}

bool RuleEndGame::getIsEnd(Board board)
{
    this->board_ = board;
    allClear();
    return isEnd_;
}

void RuleEndGame::setIsEnd()
{
    this->isEnd_ = true;
}

}//end namespace model
