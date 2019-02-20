#ifndef VIEWPARAMETER_H
#define VIEWPARAMETER_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

#include "headers/views/viewmainwindow.h"
using namespace model;
namespace views {
class viewParameter;
class ViewMainWindow;

/**
 * @brief The viewParameter class
 *
 * This class allows at the player to selected each parameter of the game
 *
 */
class viewParameter : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief viewParameter
     *
     * This is the constructor of the class viewParameter, allows at the player
     * to select the size of the board, her name, and which maniere to initialize the
     * bombs ont the board
     *
     */
    explicit viewParameter();

    /**
     *
     * This is the destructor of the class
     *
     */
    ~viewParameter();

    /**
     * @brief update
     *
     * This method allows to update the display allows the choice of initilize
     *
     */
    void update();

private:
    QVBoxLayout *vBox;

    QLabel *labInitBombs;
    QLabel *labHeight;
    QLabel *labWidth;
    QLabel *labNbBombs;
    QLabel *labPerBombs;
    QLabel *labNamePlayer;

    QComboBox *choiceInit;

    QLineEdit *editHeight;
    QLineEdit *editWidth;
    QLineEdit *editNumberBombs;
    QLineEdit *editPourcentBombs;
    QLineEdit *editNamePlayer;

    ViewMainWindow *mainWin;

    QPushButton *play;

    /**
     * @brief launch
     *
     * This method allows to launch a new ViewMainWindows with the parameter
     * entry in the attribute of the class viewparameter
     *
     */
    void launch();

};


}








#endif // VIEWPARAMETER_H
