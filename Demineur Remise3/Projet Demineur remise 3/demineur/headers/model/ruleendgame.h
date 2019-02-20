#ifndef RULESENDGAME_H
#define RULESENDGAME_H

// pour verifier si nb flag sur chaque bombe faut que les
// deux vector aie la meme taille sinon pas besoin
// d aller plus loin

#include "headers/model/board.h"

namespace model {

/** \RulesEndGame
 * @brief The RulesEndGame class
 *
 * This class allows to define if the game is end or not
 *
 */
class RuleEndGame
{
public:

    /**
     * @brief RulesEndGame
     *
     * This is the constructor of this class without parameter
     *
     */
    RuleEndGame();

    // on fait une classe comme ca on appel la methode
    // isEnd de cette objet
    // on lui donne une copie du board pour verifier dessus
    /**
     * @brief RulesEndGame
     *
     * This is the constructor of this class with an object board
     *
     * @param board is the board to give at the attribute of class board_
     */
    RuleEndGame( Board &board);

    /**
     * @brief
     *
     * This is the destructor of the class it is by default
     *
     */
    ~RuleEndGame()=default;

    /**
     * @brief allClear
     *
     * This method verify and return a boolean if each position which there
     * aren't a bombs is clear
     *
     * @return a boolean true if each position clear is revelant and false if not
     */
    void allClear();

    /**
     * @brief getIsEnd
     *
     * This is a getter to return the valor of the attribute isEnd_
     *
     * @return the valor of the attribute isEnd_
     */
    bool getIsEnd(Board);

    // le setter es utiliser si le jeu est fini et met le boolean isEnd_
    // a vrai
    /**
     * @brief setIsEnd
     *
     * This is the setter to put the boolean attribute isEnd_ at true
     *
     */
    void setIsEnd();


private:

    /**
     * @brief board_ this attribute is board where apply the method to verify
     * if the game is end or not
     */
    Board board_;

    /**
     * @brief isEnd_ is the boolean attribute if the game is end or not
     */
    bool isEnd_;

};

}


#endif // RULESENDGAME_H
