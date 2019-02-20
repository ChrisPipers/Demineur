#ifndef VIEWMAINWINDOW_H
#define VIEWMAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QBoxLayout>
#include <QMouseEvent>
#include <QMouseEvent>

#include "headers/views/viewboard.h"
#include "headers/views/viewendgame.h"


using namespace model;
namespace views {
class ViewMainWindow;
class viewEndGame;
/**
 * @brief The Viewmainwindow class
 *
 * This class allows to build the main windows of the part with the
 * viewboard, the time, the number of bombs and the name of the player
 *
 */
class ViewMainWindow : public QWidget, public Observer
{
    Q_OBJECT

public:

    /**
     * @brief ViewMainWindow
     *
     *  This is the constructor of the class with the parameter to initialise a new game
     *
     * @param namePlayer is the name of the player to creat a new game
     * @param height is the height of the new board
     * @param width is the width of the new board
     * @param choice is the choice how initiliaze the number of bombs
     * @param intNbBombs is the number of bombs selected if the choice is 2
     * @param percentBombs is the number of bombs selected if the choice is 3
     */
    explicit ViewMainWindow(string namePlayer, int height, int width, int choice, int intNbBombs, int percentBombs);

    /**
     *
     * This is the destructor of the class
     *
     */
    ~ViewMainWindow();

    /**
     * @brief update
     *
     * This method allows to update each parameter and attribute of the class viewMainWindow
     *
     */
    void update();

private:

    Game game_;

    QVBoxLayout * vbox_;

    ViewBoard *viewBoard_;

    QHBoxLayout * hbox_;

    QHBoxLayout * hboxTime_;

    QVBoxLayout * vboxNamePlayer_;

    QHBoxLayout * hboxNbBombs_;

    QLabel * textNbBombs_;
    QLabel * textTime_;
    QLabel * nomPlayer_;

    QLCDNumber * nbBombs_;
    QLCDNumber * time_;

    viewEndGame *viewendgame;
};

}

#endif // VIEWMAINWINDOW_H
