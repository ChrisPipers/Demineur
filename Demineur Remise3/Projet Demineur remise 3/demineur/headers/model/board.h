#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <queue>
#include <set>
#include <list>
#include <string>
#include <stdexcept>
#include <iostream>

#include "headers/model/position.h"
#include "headers/observer/observable.h"

namespace model {

/** \class Board
 *
 * @brief The Board class represents the board of the game
 * each case containt one of four valor, clear, dark, flag or bomb
 *
 */
class Board {
public:

    // 9 valeur de la hauteur et largeur par défaut
    // board tableau de char car la taille est tj
    // de 1 byte ( valeur sur ) et plus petit qu un int
    // INIT et met tout a dark
    /**
     * @brief Board
     *
     * This is the constructor of the board with parameter
     * by defaut with the valor nine but it's possible to
     * select an another size
     *
     * the Board containt width * height case who can containt
     * one of four valor, c for clear, d for dark, f for flag,
     * b for bomb or one at heigt integer allow the number of bomb
     * there are around
     *
     * the valor of each case is a char {c, d, f, b, 1, 2, 3,
     * 4, 5, 6, 7, 8}
     *
     * @param width is the parameter of che width of the board, the default
     * valor is nine
     *
     * @param height is the parameter of che height of the board, the default
     * valor is nine
     */
    Board (int height = 9, int width = 9) ;

    /**
     * @brief
     *
     * This is the destructor of the board, it's by default
     *
     */
    ~Board()=default;

    /**
     * @brief initBoard
     *
     * This méthod allows to initialize all positions of the board
     * with the valor 'd' for dark
     *
     */
    void initBoard ();

    /**
     * @brief getBoard
     *
     * This méthod allows to return the board who contains width * height char
     *
     * @return the board of char at a moment of the game
     */
    std::vector <std::vector<char>> getBoard();

    // placeBombs et init font deux choses diff
    //
    // init cree un certain nb de bombe
    // a tel position et l ajoute au vecteur
    //
    // place modifie le board
    //
    // attention la permiere position selectionner
    // par le joueur ne peut etre une bombe
    // une autre position sera selectionner dans ce cas
    /**
     * @brief placeBombs
     *
     * This method allows to place the bombs allows each position
     * present in the vector posBombs_ on the board
     */
    void placeBombs();

    // attention apres le premier clic pour reveler les bombes sont placer
    // au premier clic impossible de tomber sur une bombe
    // MAIS si il met un flag la le prochain clic peut tomber
    // sur une bombe
    // formule ( (0.0002) * (width*height)^2 ) + ( 0.0938 * (width*height) ) + 0.8937 arrond a l entier le plus proche
    // attention soit : via la formule - via nombre de mine select by player - soit pourcentage select by player
    // cette méthode appel une des 3 methodes pour le nbm de bombes
    //
    // le param choice permet de choixir une des 3 options
    // pour initialiser les bombes
    //
    // la position permet de creer les bombes sans select la pose
    // choisie par le joueur
    /**
     * @brief initBombs
     *
     * This method allows to select the type of initialization of bomb
     * on the board, the int choice represent the choice of initialization
     * of bombsthere are three choices , by default, according a percentage
     * allows the number of case in the board (height * width)
     * The position is the position of the first clic where cannot place a bomb
     *
     * @param choice is an integer who represent the choice how initilization
     * the bombs on the board
     *
     * @param position is the first position selected by the player where cannot
     * place a bomb
     */
    void initBombs(int choice, Position position);

    /**
     * @brief defaultBombs
     *
     * This method allows to place the bombs on the board by default, there is
     * a formula by default according to the size of board (height * wifth) for
     * determine the number of bombs to place on the board
     *
     * @param position is the first position selected by the player where cannot
     * place a bomb
     */
    void defaultBombs(Position position);

    /**
     * @brief pourcentBombs
     *
     * This method allows to place the bombs on the board according to the percentage
     * selected by the player, the percentage is determinate by the size of the board
     * ((height * width) * percentage)
     *
     * @param rateBombs is the percentage of bombs seleted by the player to place at
     * the board
     *
     * @param position is the first position selected by the player where cannot
     * place a bomb
     */
    void pourcentBombs(Position position);

    /**
     * @brief nbBombs
     *
     * This method allows to place the bombs on the board according to the number
     * selected by the player
     *
     * @param nbBombs is the number of bombs selected by the player to place at the
     * board
     *
     * @param position is the first position selected by the player where cannot
     * place a bomb
     */
    void nbBombs(Position position);

    /**
     * @brief initPosBombs
     *
     * This method allows to define much random position to the number
     * of bombs define
     *
     * @param nbBombs is the number of bombs define for this part
     *
     * @param position this is the position where we cannot fine
     * a bombe if we clear for the first action
     * this position value is (-1,-1) if the first action is put a flag
     *
     */
    void initPosBombs(unsigned nbBombs, Position position);

    /**
     * @brief getNbBombs
     *
     * This method allows to return the number of bombs present
     * on the board
     *
     * @return a interger of the number of bombs present in the
     * board
     */
    int getNbBombs();

    /**
     * @brief getHeight
     *
     * This is the getter to return the valor of the height of the board
     *
     * @return an integer of the valor of the height of the board
     */
    int getHeight();

    /**
     * @brief getWidth();
     *
     * This is the getter to return the valor of the width of the board
     *
     * @return an integer of the valor of the width of the board
     */
    int getWidth();

    // les valeurs des char
    // b -> bomb
    // f -> flag
    // c -> clear
    // d -> dark ( non explorer )
    // celle avec des chiffres en plus allant de 1 à 8
    // selon le nombre de bombes au allantour mais
    // faire attention a la coloration aussi
    /**
     * @brief getValPosition
     *
     * This method allows to return the valor at the position of the board
     *
     * @param position is the position in the board which we want know the
     * valor
     *
     * @return the valor in the board at the position in parameter
     */
    char getValPosition( Position position);

    /**
     * @brief revelantPosFirst
     *
     * This method allows to revelant the first position at the start of
     * of the game
     *
     * @param position is the first position to revelant at the start of
     * game
     */
    void revelantPosFirst(int choice, Position position);

    // montre toute les cases adjacentes sans bombes
    // utiliser recursivité
    //
    // le bool retourner pour facilité le cas ou le joueur
    // tombe sur une bombe ( true pour ok , false pour non ok donc
    // est tomber sur une bombe )
    //
    // utilisation de la queue tant que pos est sans bombe
    //
    // attention les cases avec un flags ne sont pas reveler
    /**
     * @brief revelantPositionRecursif
     *
     * This method allows to analyze the position arond the position
     * in parameter of the method
     *
     * This method use a queue for analyse each position in the board
     *
     * @param position is the first position to analyze in the board
     *
     * @return a boolean allows the result of the first position, if
     * the first position is a bomb this method return false and true
     * if not
     */
    bool revelantPositionRecursif(Position position);

    /**
     * @brief placeToQueue
     *
     * This method allows to reveal the board. If the position
     * at the board cannot the valor 'b' or 'f' or 'c' or a interger
     * isn't add to the queue for be analyze
     *
     * @param position is the position to verify her value
     */
    void placeToQueue(Position position);

    /**
     * @brief inBoard
     *
     * This method allows to know if the position in parameter
     * is in the board
     *
     * @param position is the position to analyze if it is in the
     * board
     *
     * @return a boolean if the position is in the board or not
     */
    bool inBoard(Position position);

    /**
     * @brief placeFlagPosition
     *
     * This method allows to place the valor 'f', for flag, in the board
     * at the position in parameter
     *
     * @param position is the position where place the valor 'f'
     */
    void placeFlagPosition(Position position);

    // delete flag change le f en d pour dark car une position avec un
    // flag ne peut etre devoiler
    /**
     * @brief deleteFlagPosition
     *
     * This method allows to delete the valor 'f', for flag, and put
     * the valor d, for dark, at the position in parameter
     * (a position with a flag cannot be reveal, she is dark)
     *
     * @param position is the position where change the valor f to the
     * valor d in the board
     */
    void deleteFlagPosition(Position position);

    /**
     * @brief placeClearPosition
     *
     * This position place in the board the valor 'c' at the position
     * in parameter
     *
     * @param position is the position where change the valor c in the
     * board
     */
    void placeClearPosition(Position position);

    /**
     * @brief placeIndicePosition
     * @param position
     * @param indice
     */
    void placeIndicePosition(Position position, int indice);

    // display en mode console
    /**
     * @brief displayBoard
     *
     * This method allows to diplayed the board for tests and debug in the console
     */
    void displayBoard();

    // display en mode console
    /**
     * @brief displayBoard
     *
     * This method allows to diplayed the board for the player in the console
     */
    void displayBoardForPlayer();

    /**
     * @brief setPourcentMines
     *
     * This setter allows to change the valor of the percent
     * of mine must be present in the board
     *
     * @param percent is the new percent of mine must be present
     * in the board
     */
    void setPourcentMines(double percent);

    /**
     * @brief setNbMines
     *
     * This setter allows to change the valor of the number of mine
     * must be present in the board
     *
     * @param nbMine is the new number of mine must be present
     * in the board
     */
    void setNbMines(int nbMine);

    /**
     * @brief nbMineArround
     *
     * This method allows to know how much bombs there are
     * around the position in parameter this number can have the
     * valor 0 to 8
     *
     * @param position is the position to analyze how much bombs
     * there are around
     *
     * @return a interger how much bombs there a arount the position
     *
     */
    int nbMineArround(Position position);

    /**
     * @brief updateboard
     *
     * This method allows tu update the board, here this isn't
     * very utility
     *
     */
    void updateboard();

    /**
     * @brief setIsInitilized
     *
     * This method allows to put at true the attribute isInitilize
     *
     */
    void setIsInitilized(bool);

    /**
     * @brief getIsInitilized
     *
     * This is the getter for know the valor of the attribute isInitilize
     *
     * @return a boolean if the board is initilized or not
     */
    bool getIsInitilized();

private:

    /**
     * @brief outOfRange
     *
     * This method allows to launch a exception if the position is outside of the board
     *
     * @param position is the position to analyze if in the bord of the board
     */
    inline void outOfRange(Position position)
    {
        if (position.getAbs()> this->getWidth() || position.getOrd()> this->getHeight() ||
               position.getAbs()< 0 || position.getOrd()<0 )
        {
            std::string s = "Position out of range of the board";
            throw std::out_of_range(s);
        }
    }

    /**
     * @brief board_
     *
     * This attribute is a vector of vector of char who represent
     * the board
     * With this attribute we can create the board 2D (height*width)
     */
    std::vector<std::vector<char>> board_;

    /**
     * @brief height_
     *
     * This attribute is an integer represent the height of the board
     */
    int height_;

    /**
     * @brief width_
     *
     * This attribute is an integer represent the width of the board
     */
    int width_;

    // peut etre pas necessaire si met le carac 'c' et utilisationd e la queue
    //vector<vector<bool>> boardZoneVisited_;
    /**
     * @brief queueToVisit_
     *
     * This attribute is the queue used for analyze each position in the board
     * with the method revelantPositionRecursif
     */
    std::queue <Position, std::list <Position>> queueToVisit_;

    /**
     * @brief posBombs_
     *
     * This attribute is a vector who containt each position where place
     * the bombs on the board
     */
    std::set<std::pair<std::string,Position>> posBombs_;

    /**
     * @brief posFlags_
     *
     * This attribute is a vector who there are a flag in the board
     */
    std::set<std::pair<std::string,Position>> posFlags_;

    /**
     * @brief nbMine_
     *
     * This attribute is an integer reprensent the number of bombs
     * in the board
     */
    int nbMine_;

    /**
     * @brief percentMine_
     *
     * This attribute is an integer represent the percent of bombs
     * in the board
     */
    double percentMine_;


    /**
     * @brief isInit
     *
     * This attribute allows to know if the board is already initilized
     *
     */
    bool isInitilize_;

};
}


#endif // BOARD_H
