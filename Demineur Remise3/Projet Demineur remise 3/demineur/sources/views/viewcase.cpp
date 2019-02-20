#include "headers/views/viewcase.h"
#include <iostream>
#include "headers/model/position.h"
#include <QObject>
#include <QMouseEvent>
#include <iostream>
#include <streambuf>
#include <QStyleFactory>
using namespace std;
using namespace views;

Viewcase::Viewcase(char color, int x, int y, Game &game): color_(color), x_(x), y_(y), game_(game)
{
    this->setStyleSheet("background-color: rgb(096, 096, 096);");
    this->setMaximumSize(56,56);
    this->setMinimumSize(56,56);

    //this->installEventFilter(this);
}

/*
bool Viewcase::eventFilter(QObject *watched, QEvent *event){
        QStyleSheetStyle st;
        if(event->type() == QEvent::Enter){
                st = this->style();
                this->setStyleSheet("background-color: red");

        }else if(event->type() == QEvent::Leave){

        }


    return false;
}
*/

Position Viewcase::getCasePos()
{
    return posSelect_;
}

void Viewcase::setColor(char color)
{
    cout << game_.getBoard().getHeight()<< "  set color   "<< game_.getBoard().getWidth() << endl;

    switch(color){

    case 'b':
        if(game_.getIsEnd())
        {
            setPixmap(QPixmap(":/images/bomb.png"));
            this->setStyleSheet("background-color: rgb(255, 255, 255);");
            this->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
            break;
        }
        else
        {
            setPixmap(QPixmap());
            break;
        }

    case 'd':
        setPixmap(QPixmap());
        break;

    case 'c':
        this->setStyleSheet("background-color: rgb(102, 204, 000);");
        break;

    case 'f':
        setPixmap(QPixmap(":/images/flag.png"));
        //this->setStyleSheet("background-color: rgb(006, 057, 113);");
        break;

    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
        QString temp (1, color);
        this->setText("<font color='black'>"+temp+"</font>");
        this->setStyleSheet("background-color: rgb(190, 190, 190);");

        QFont font = this->font();
        font.setPointSize(20);
        font.setBold(true);
        this->setFont(font);
        this->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
        break;
    }
}

void Viewcase::onClicked()
{
    posSelect_ = Position(x_, y_);
}

void Viewcase::mousePressEvent(QMouseEvent * ev)
{
    bool end = false;
    posSelect_ = Position(x_, y_);
    Qt::MouseButtons mouseButtons = ev->buttons();
    if(mouseButtons == Qt::LeftButton){
        if(game_.getIsStart()==false)
        {
            game_.firstAction(posSelect_, "clear",game_.getChoice());
        }
        else
        {
             end = game_.play(posSelect_, 'c');
        }
    }
    else if(mouseButtons == Qt::RightButton)
    {
        if ( (game_.getBoard().getValPosition(posSelect_))!='f' )
        {
        if(game_.getIsStart()==false)
        {
            game_.firstAction(posSelect_, "flag", game_.getChoice());
        }
        else
        {
            game_.play(posSelect_,'f');
        }
    }
        else
        {
            game_.play(posSelect_,'d');
        }
    }
    game_.isEnd(game_.getBoard());
    if(end)
    {
        game_.setResultGame(false);
        game_.setIsEnd();
        game_.update();
    }
}

