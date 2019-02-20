#include "headers/model/position.h"
#include <iostream>

namespace model{
using namespace std;

Position::Position()
{

}

Position::Position(int abs, int ord)
{
    abs_ = abs;
    ord_ = ord;
}

int Position::getAbs()
{
    return abs_;
}

int Position::getOrd()
{
    return ord_;
}


void Position::setAbs(int abs)
{
    abs_ = abs;
}

void Position::setOrd(int ord)
{
    ord_ = ord;
}


bool Position::operator==( const Position& pos1)const
{
    if ( ((this->abs_ == pos1.abs_) && (this->ord_== pos1.ord_)) )
    {
    return true ;
    }
    else
{
    return false;
    }
}

//avec l utilisation de set les données doivent etre ordonner
//donc il as fallut ajouter cette methode :
bool Position::operator<( const Position& pos1) const
{
    if ( ((abs_ < pos1.abs_) || (ord_ < pos1.ord_)) )
    {
    return true ;
    }
    else
{
    return false;
    }
}

}//end namespace model




