#include "headers/views/viewboard.h"

#include "headers/model/position.h"
#include "headers/model/board.h"
#include "headers/model/game.h"
#include "headers/model/player.h"
#include <iostream>

using namespace std;
using namespace model;
using namespace views;



ViewBoard::ViewBoard(Game &game) : game_(game)
{
    board_ = &game.getBoard();
    this->setVerticalSpacing(2);
    this->setHorizontalSpacing(2);
    this->setSizeConstraint(QLayout::SetFixedSize);

    initBoard();
}

ViewBoard::~ViewBoard()
{
    delete viewcase_;
    delete board_;
    delete &game_;
}

void ViewBoard::initBoard()

{
    cout << board_->getHeight()<< "  ici dans init "<< board_->getWidth() << endl;

    this->board_ = &game_.getBoard();
    for (int x = 0; x < board_->getHeight(); x++)
    {
        for (int y = 0; y < board_->getWidth(); y++)
        {

            viewcase_ = new Viewcase(game_.getBoard().getValPosition(Position(x,y)), x, y, game_);
            this->addWidget(viewcase_, x, y);
        }
    }
}

void ViewBoard::updateViewBoard()
{
    cout << board_->getHeight()<< "  ici dans update "<< board_->getWidth() << endl;

    for (int x = 0; x < board_->getHeight(); x++)
        {
            for (int y = 0; y < board_->getWidth(); y++)
            {
                cout << x << "  -  " << y << endl;
                    QWidget *elem = this->itemAtPosition(x,y)->widget();
                    Viewcase *viewcase_2 = (Viewcase*) elem;
                    cout << board_->getHeight()<< " upppppp  " << board_->getWidth() << endl;
                    cout << " la case    " <<  board_->getValPosition(Position(x,y)) << endl;
                    viewcase_2->setColor((board_->getValPosition(Position(x,y))));

            }

            }
        }

