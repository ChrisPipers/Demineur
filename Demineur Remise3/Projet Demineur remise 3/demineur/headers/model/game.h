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
#include <vector>

namespace model {

/** \Game
 *
 * @brief The Game class
 *
 * This class is the facade for manage the game and call all of method of the
 * namespace model
 *
 */
class Game : public Observable {

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

    /*

     * @brief Game
     *
     * This is the constructor of the game by the another game
     *
     * @param aGame is the new game to copy
     *

    Game(Game const &aGame);
    */

    /**
     * @brief Game
     *
     * This is the constructor of the class game with each parameter to initialize the part
     *
     * @param namePlayer is a string , it's the name of the player
     * @param height is an integer with the value of height of board
     * @param width is an integer with the value of width of board
     * @param choice is an integer of the choice of init the number of bombs on the board, if the choice is 1
     * the number of bombs is by default, if the choice is 2 the attribute percentBombs is used to compute the
     * number of bombs to place at the board and if the choice is 3 the attribute nbBombs is used to compute
     * the number of bombs to place at the board
     * @param nbBombs is an integer of the number of bombs to place in the board
     * @param percentBombs is an integer of percent of bombs to place in the board (ex: 5 -> 0.05 -> 5 % )
     */
    Game(string namePlayer, int height, int width, int choice, int nbBombs, int percentBombs);


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
    ~Game();

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
     * @brief getChoice
     *
     * This getter return the valor of the choice selected to initilize the number of bombs
     *
     * @return an integer who is the valor to choice the initiliaze of number of bombs on the board
     */
    int getChoice();

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
     * @param position is the first position play by the player
     * @param string is the choice make by the player to play (revelant position,
     * put flag at position)
     * @param int is the choice to initialize the number of bombs in the board
     *
     */
    void firstAction(Position, std::string, int);

    /**
     * @brief update
     *
     * This method allows to update the display of the board
     *
     */
    void update() ;

    /**
      * @brief getPlayer
      *
      * This method allows to return the player of the class game/part
      *
      * @return a player who is the player of the game/part
      */
    Player getPlayer();

    /**
      * @brief manageLose
      *
      * This method allows to manage the end of the part when the player loose
      * the part is useb when we play not by graphics
      *
      */
    void manageLose(Position);

    /**
      * @brief manageWin
      *
      * This method allows to manage the end of the part when the player win
      * the part is useb when we play not by graphics
      *
      */
    void manageWin();

    /**
     * @brief displayGame
     *
     * This method allows to display the game wich each important information
     *
     */
    void displayGame();

    /**
     * @brief play
     * @return
     */
    bool play();

    /**
     * @brief play
     * @param pos
     * @param action
     * @return
     */
    bool play(Position pos, char action);

    /**
     * @brief readPalmares
     *
     * This method allows to read the palmares in the file texte parlmares.txt
     * and put each line of this file in a vector
     *
     */
    void readPalmares();

    /**
     * @brief selectSavePalmares
     *
     * This method allows to select which palmares save in the file, keep it just
     * the better score allows the less time put
     *
     * @param newResultS is the new line to verify if there are the same part with the
     * same parameter and id there is, if the time in the new Result is less than
     * the older result the newResultS remplace the old result
     */
    void selectSavePalmares(string newResultS);

    /**
     * @brief getTimeT
     *
     * This method allows to return the time of the part
     *
     * @return the attribute time of the class game
     */
    TimeT getTimeT();

    /**
     * @brief getIsEnd
     *
     * This method allows to return the attribute if the game is end or not
     *
     * @return a boolean if the part is end or not
     */
    bool getIsEnd();

    /**
     * @brief getResultGame
     *
     * This method allows if the part is end if the game is win or not
     *
     * @return a boolean if the part is win or not
     */
    bool getResultGame();

    /**
     * @brief setResultGame
     *
     * This is the setter to modify the valor of the attribute result of the game
     *
     * @param result is the new valor of the attribute result
     */
    void setResultGame(bool result);

    /**
     * @brief stringToVector
     *
     * This method allows to put each word of a string of char in a vector
     * each case of the vector have a word of the parameter chaineToconv
     *
     * @param chaineToConv is a string to put in a vector
     * @return a vector of string wich each case have a word of the parameter
     * chaineToConv
     */
    vector<string> stringToVector(string chaineToConv);

    /**
     * @brief vectorToString
     *
     * This method allows to parse a vector of string to a string
     *
     * @param vectToConv is the vector of string to parse to a string
     * @return is the string with each word contain in the vector in paramter
     * vectToConv
     */
    string vectorToString(vector<string>vectToConv);

    /**
     * @brief getVPalmares this method allows to return a vector of vector of string
     * each line is a result of the best part by a player
     *
     * @return a vector of vector of string who containt the palamres of the game
     */
    vector<vector<string>> getVPalmares();

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
    //TimeT time_;

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
    TimeT time_;

    /**
     * @brief choice_ this attribute is the choice how initialize the bombs on the board
     */
    int choice_;

    /**
     * @brief palmares_ this attribute is a vector of vector of string who each line containt the
     * palmares of the part
     */
    vector <vector<string>> palmares_;

    /**
     * @brief win_ this attribute allows to know if the part is win or not
     */
    bool win_;

};

}

#endif // GAME_H
