#ifndef VIEWSTART_H
#define VIEWSTART_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>

#include "headers/views/viewparameter.h"

using namespace model;
namespace views {
class viewParameter;

/**
 * @brief The viewStart class
 *
 * This class allows to build the view to start the game
 * the player can launch a new game or see the palmares
 *
 */
class viewStart : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief viewStart
     *
     * This is the constructor of the class viewStart
     * the player can launch a new game or see the palmares
     *
     */
    explicit viewStart();

    /**
     *
     * This is the destructor of the class viewStart
     *
     */
    ~viewStart();

private:
    Game game;

    QVBoxLayout *vBox;

    QHBoxLayout *hBox;

    QLabel *labTitreGame;

    viewParameter *viewparameter;

    QPushButton *butPlay;
    QPushButton *butPalmares;

    /**
     * @brief palmares
     *
     * This method allows to display the palmares in a QMessageBox when the player
     * clicked on the button butPalmares
     *
     */
    void palmares();

    /**
     * @brief newGame
     *
     * This method allows to launch a new game when the player clicked on the button
     * butPlay
     *
     */
    void newGame();

};


}






#endif // VIEWSTART_H
