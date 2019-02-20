#ifndef GAME_H
#define GAME_H

#include "headers/model/player.h"
#include "headers/model/board.h"
#include "headers/model/position.h"
#include "headers/model/ruleendgame.h"
#include "headers/model/timeT.h"
#include "headers/observer/observer.h"
#include <map>
#include <string>

namespace model {

/** \Game
 *
 * @brief The Game class
 *
 * This class is the facade for manage the game and call all of method of the
 * namespace model
 *
 */
class Game :  Observer
{
// attention quand la partie graphique sera faites quand ont ferme
// la page graphique il y a une erreur c est parce qu il faut
// desinscrire / detruire l'observer
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
     * This is a method to call the method getIsEnd of the class RulesEndGame
     * and modify the valor of the attribute isEnd_ of class Game
     *
     */
    void isEnd(Board);

    /**
     * @brief setIsEnd
     *
     * This is the setter to past the attribute isEnd_ at true
     *
     */
    void setIsEnd();

    //utile pour la part graphique
    /**
     * @brief getBoard
     *
     * This method return the Board, this méthod are necessary for the graphic part
     *
     * @return the Board of the Game
     */
    Board &getBoard();

    //appel initBombs
    // puis appel place bombs
    // puis appel revelantPositionRecursif
    // while avec un break si le bool retourner est
    // false
    //
    // utiliser time pour ca car si time est a zero
    // ou plus simplement utiliser ca une fois puis
    // revelantPositionRecursif dans la boucle
    /**
     * @brief revelantPosFirst
     *
     * This method allows to revelant the first position at the start of
     * of the game
     * This method call the revelantPosFirst of the class Board
     *
     * @param position is the first position to revelant at the start of
     * game
     */
    void revelantPosFirst();

    /**
     * @brief revelantPositionRecursif
     *
     * This method allows to analyze the position arond the position
     * in parameter of the method
     * This method call the revelantPositionRecursif of the class
     * Board
     *
     * @param position is the first position to analyze in the board
     *
     * @return a boolean allows the result of the first position, if
     * the first position is a bomb this method return false and true
     * if not
     */
    bool revelantPositionRecursif(Position position);

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

    /**
     * @brief savePart
     *
     * This method allows at end of the game to save the
     * part if the player according with the parameter
     * of the part have the best chrono
     *
     * @param player is the player to save her name in the
     * file
     *
     * @param time is the time to save in the file
     *
     * @return a boolean to comfirm if the saving is made
     */
    void savePart();

    /**
     * @brief getClassementPlayer
     *
     * This method allows to read in the file of saving and return
     * a map with the name of the player and the time made
     *
     * @return this method return a map with the name of players and
     * with her time made
     */
    std::map<std::string , double> getClassementPlayer();

    /**
     * @brief posValide
     *
     * This method allow to know if the position in parameter is in
     * the board of the board
     *
     * @param position is the position to analyze if is in the
     * board or not
     *
     * @return a boolean if the position in parameter is in the
     * board or not
     */
    bool posValide(Position position);

    /**
     * @brief choiceTypePart
     *
     * This method allows to ask at the player if selected the number of
     * bombs by default or select the percent or the number
     *
     * @return the choice of the player 1 for by default
     * 2 select the percent and 3 select the number
     */
    int choiceTypePart();

    /**
     * @brief helpDisplayChoice
     *
     * This method allows to display the help for help the player
     *
     */
    void helpDisplayChoice();

    /**
     * @brief manageChoice
     *
     * This method allows to initilize the parameter of the party
     *
     * @param choicePart is a interger of the choice of the player between
     * 1 and 3 but only 2 and 3 is useb because 1is by default
     */
    void manageChoice(int choicePart);

    /**
     * @brief validAndDefinePourcentBombs
     *
     * This method allows to ask at the player the percent of bombs desired
     * in the board and modify this value in the board with the
     * method setPourcentMines()
     *
     */
    void validAndDefinePourcentBombs();

    /**
     * @brief validAndDefineNbBombs
     *
     * This method allows to ask at the player the number of bombs desired
     * in the board and modify this value in the board with the
     * method setNbMines()
     *
     */
    void validAndDefineNbBombs();

    /**
     * @brief selectSizeBoard
     *
     * This method allows to ask at the player the size of width and the size of
     * the height seleted by the player
     *
     */
    void selectSizeBoard();

    /**
     * @brief getIsStart
     *
     * This method allows to know if the party is already start or not
     *
     * @return a boolean if the part is already start or not
     */
    bool getIsStart();

    /**
     * @brief setIsStart
     *
     * This setter allows to put the attribut isStart_ at true
     *
     */
    void setIsStart();

    /**
     * @brief selectAction
     *
     * This method allows ask at the player if he choice to clear a position
     * place a flag, delete a flag
     *
     * @return a string who is the choice of the player, the different
     * value is "clear", "flag" and "deflag"
     */
    std::string selectAction();

    /**
     * @brief selectPositionToAction
     *
     * This method allows to ask at the player where make the action
     * previously selected
     * This method verify if this position is valid (in the board and if the
     * valor of the position is 'd' only)
     *
     * @return the position selected by the player
     */
    Position selectPositionToAction();

    /**
     * @brief firstAction
     *
     * This method allows to manage the first action of the game
     *
     */
    void firstAction(Position, std::string, int);

    /**
     * @brief update
     *
     * This method allows to update the display of the board
     *
     */
    void update();

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
    RuleEndGame ruleEndGame_;

    /**
     * @brief isEnd_
     *
     * This attribute is a boolean if the game is end or not
     */
    bool isEnd_;

    /**
     * @brief isStart_
     *
     * This attribute is a boolean if the game is start or not
     */
    bool isStart_;

    /**
     * @brief time_
     *
     * This attribute is the Time at the moment T of the game
     */
    TimeT time_;

    /**
     * @brief posSelected_
     *
     * This attribute is the current position selected by the player
     */
    Position posSelected_;

    /**
     * @brief timeEnd
     *
     * this attribute is the time at the end of the party
     */
    unsigned timeEnd;

};
}

#endif // GAME_H
