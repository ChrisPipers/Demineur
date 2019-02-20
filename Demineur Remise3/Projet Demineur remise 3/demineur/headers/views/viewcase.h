#ifndef CASE_H
#define CASE_H

#include <QLabel>
#include <QPixmap>
#include <QLayoutItem>
#include <QObject>

#include "headers/model/position.h"
#include "headers/model/game.h"
#include <string>

using namespace model;
namespace views {

/**
 * @brief The Case class
 *
 * This class allows to build a case of the QGridLayout for build the
 * board
 * This class derive the QLabel, a viewcase is a QLabel
 *
 */
class Viewcase : public QLabel
{

private slots:
    /**
     * @brief onClicked
     *
     * this method allows when the case is clicked to make the action autorized
     * there are three action possible ( place flag, revelant position or if there is a flag
     * or to take off the flag)
     *
     */
    void onClicked();
public :
    /**
     * @brief Case
     *
     * This is the constructor of the case
     *
     * @param color is the color ( 'b', 'd', 'c', '[1-8]' ) of the case according with the board of the part
     * @param x is the position x on the abscise
     * @param y is the position y on the ordonate
     *
     */
    Viewcase(char color, int x, int y, Game &game);

    /**
     * @brief
     *
     * This is the destructor of the class case
     *
     */
    ~Viewcase(){}

    /**
     * @brief setColor
     *
     * This method allows to change the color of the case according on the evolution of
     * the game
     *
     * @param color is the new color for the case
     */
    void setColor(char color);

    /**
     * @brief getCasePos
     *
     * this method allows to know the position of the case on the QGridLayoutµ
     *
     * @return the position on the case
     *
     */
    Position  getCasePos();

    /**
     * @brief mousePressEvent
     *
     * This method allows to make the action autorized by the game when the mouse
     * is clicked
     *
     * @param ev is the event of the mouse click
     *
     */
    void mousePressEvent(QMouseEvent * ev);


    //bool eventFilter(QObject *watched, QEvent *event);


private :
    char color_;
    int x_;
    int y_;
    Game &game_;
    Position posSelect_;
    bool posStartIsSelected_;
};

}
















#endif // CASE_H
