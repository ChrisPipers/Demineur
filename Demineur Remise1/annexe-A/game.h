#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "position.h"
#include "rulesendgame.h"
#include "time.h"
#include "observable.h"

namespace model {

/** \Game
 *
 * @brief The Game class
 *
 * This class is the façade for manage the game and call all of method of the
 * namespace model
 *
 */
class Game : public Observable
{

public :

    /**
     * @brief Game
     *
     * This is the constructor of the class Game without parameter
     *
     */
    Game();

    /**
     * @brief Game
     *
     * This is the constructor by copy of the class game
     *
     * @param g is the constant Game to copy
     */
    Game (const Game & g);

    /**
     * @brief ~Game
     *
     * This is the destructor of the class Game
     * This destructor is by default
     *
     */
    ~Game()=default;

    // permet de donner un nom au player utile pour la sauvegarde dans le fichier
    /**
     * @brief initPlayer
     *
     * This method allows to initialize the player with a name
     *
     */
    void initPlayer();

    // appel les methodes de Board pour voir si c est fini
    /**
     * @brief getIsEnd
     *
     * This is a getter to call the method getIsEnd of the class RulesEndGame
     * and return the valor of the attribute isEnd_ of class RulesIsGame
     *
     * @return the valor of the attribute isEnd_ of the class RulesIsGame
     */
    bool getIsEnd();

    //utile pour la part graphique
    /**
     * @brief getBoard
     *
     * This method return the Board, this method are necessary for the graphic part
     *
     * @return the Board of the Game
     */
    Board &getBoard();

    //appel initBombs
    // puis appel place bombs
    // puis appel showPositionAround
    // while avec un break si le bool retourner est
    // false
    //
    // utiliser time pour ca car si time est a zero
    // ou plus simplement utiliser ca une fois puis
    // showPositionAround dans la boucle
    /**
     * @brief showPosFirst
     *
     * This method allows to reveal the first position at the start of
     * of the game
     * This method call the showPosFirst of the class Board
     *
     * @param position is the first position to reveal at the start of
     * game
     */
    void showPosFirst(Position position);

    /**
     * @brief showPositionAround
     *
     * This method allows to analyze the position around the position
     * in parameter of the method
     * This method call the showPositionAround() of the class
     * Board
     *
     * @param position is the first position to analyze in the board
     *
     * @return a boolean allows the result of the first position, if
     * the first position is a bomb this method return false and true
     * if not
     */
    bool showPositionAround(Position position);

    /**
     * @brief restartGame
     *
     * This method allows to restart the game, put all of attribute at null
     * except the name of the player
     */
    void restartGame();

    // met le time en pose et "congele" le board
    /**
     * @brief pauseGame
     *
     * This method allows to put the game at pause, stop the time and lock
     * the board
     */
    void pauseGame();

    // arret le jeu
    /**
     * @brief setGame
     *
     * This method allows to put the game at end or not
     *
     * @param end is the new parameter for the attribute isEnd_
     */
    void setGame(bool end);

private:

    /**
     * @brief board_
     *
     * This attribute is the board of the game
     */
    Board board_;

    /**
     * @brief player_
     *
     * This attribute is the player of the game
     */
    Player player_;

    /**
     * @brief rulesEndGame_
     *
     * This attribute is the RulesEndGame of the game
     */
    RulesEndGame rulesEndGame_;

    /**
     * @brief isEnd_
     *
     * This attribute is a boolean id the game is end or not
     */
    bool isEnd_;

    /**
     * @brief time_
     *
     * This attribute is the Time of the game
     */
    Time time_;

    /**
     * @brief posSelected_
     *
     * This attribute is the current position selected by the player
     */
    Position posSelected_;

};
}






















#endif // GAME_H
