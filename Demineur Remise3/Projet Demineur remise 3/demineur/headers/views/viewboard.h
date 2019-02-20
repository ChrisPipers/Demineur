#ifndef VIEWBOARD_H
#define VIEWBOARD_H

#include <QGridLayout>
#include "headers/model/game.h"
#include "headers/model/board.h"
#include "headers/model/position.h"
#include "headers/views/viewcase.h"

using namespace model;
namespace views {

/**
 * @brief The ViewBoard class
 *
 * This class allows to creat a ViewBoard who containt some ViewCase
 * this class derive the QGridLayout to place and dispose the
 * ViewCase
 *
 */
class ViewBoard : public QGridLayout
{
public:
    /**
     * @brief ViewBoard
     *
     * This is the constructor of the class ViewBoard, the board containt
     * much viewCase to represent each case of the board of the game
     *
     * @param game is the game to take the board and initilize and update the
     * viewboard allows the valor of the part
     */
    ViewBoard(Game &game);

    /**
     * @brief ~ViewBoard
     *
     * this is the destructor of the class
     *
     */
    virtual ~ViewBoard();

    /**
     * @brief initBoard
     *
     * This method allows to initiliaze each position of the viewBoard with the
     * valor by default
     *
     */
    void initBoard();

    /**
     * @brief updateViewBoard
     *
     * This method allows to update each position of the ViewBoard allows the evolution
     * of the part
     *
     */
    void updateViewBoard();

private:

    Game &game_;
    Board *board_;
    Viewcase *viewcase_;


};

}

#endif // VIEWBOARD_H
