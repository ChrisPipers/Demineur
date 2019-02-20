#ifndef VIEWENDGAME_H
#define VIEWENDGAME_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QString>

#include "headers/views/viewstart.h"
using namespace model;
namespace views {
class viewStart;

/**
 * @brief The viewEndGame class
 *
 * This class allows to build and manage the end of the part, display
 * the result of the part (win or loose), the parameter of the part and
 * allows to close the game or restart a new part
 *
 */
class viewEndGame : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief viewEndGame
     *
     * This is the constructor of the class
     *
     * @param game is the attribute allows to display the result and the parameter
     * of the part
     */
    explicit viewEndGame(Game &game);

    /**
     *
     * This is the destructor of the class
     *
     */
    ~viewEndGame();

private:
    QVBoxLayout *vBox;
    QHBoxLayout *hBoxButton;

    QLabel *labNamePlayer;
    QLabel *labResultPart;
    QLabel *labSizeBoard;
    QLabel *labTime;

    QPushButton *butClose;
    QPushButton *butNewGame;

    Game game_;
    viewStart *viewstart;

    /**
     * @brief newGame
     *
     * This method allows to launch a new part when the player clicked on the button
     * butNewGame
     *
     */
    void newGame();

    /**
     * @brief closeGame
     *
     * This method allows to close the game when the player clicked on the button
     * butClose
     *
     */
    void closeGame();


};



}


#endif // VIEWENDGAME_H
