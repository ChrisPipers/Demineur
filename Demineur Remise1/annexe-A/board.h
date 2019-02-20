#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "position.h"

namespace model {

/** \class Board
 *
 * @brief The Board class represents the board of the game
 * each case contain one of four valor, clear, dark, flag or bomb
 *
 */
class Board{
public:

    // 9 valeur par défaut
    // board tableau de char car la taille est tj
    // de 1 byte ( valeur sur ) et plus petit qu un int
    // INIT et met tout a dark
    /**
     * @brief Board
     *
     * This is the constructor of the board with parameter
     * by default with the valor nine but it's possible to
     * select an another size
     *
     * the Board contain width * height case who can contain
     * one of four valor, c for clear, d for dark, f for flag,
     * b for bomb or one at height integer allow the number of bomb
     * there are around
     *
     * the valor of each case is a char {c, d, f, b, 1, 2, 3,
     * 4, 5, 6, 7, 8}
     *
     * @param width is the parameter of the width of the board, the default
     * valor is nine
     *
     * @param height is the parameter of the height of the board, the default
     * valor is nine
     */
    Board (int width = 9, int height=9);

    /**
     * @brief getBoard
     *
     * This method allows to return the board who contains width * height char
     *
     * @return the board of char at a moment of the game
     */
    vector <vector<char>> getBoard();

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
     * of bombs there are three choices , by default, according a percentage
     * allows the number of case in the board (height * width)
     * The position is the position of the first click where cannot place a bomb
     *
     * @param choice is an integer who represent the choice how initialization
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
     * a formula by default according to the size of board (height * width) for
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
    void pourcentBombs(double rateBombs, Position position);

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
    void nbBombs(int nbBombs, Position position);

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
    char getValPosition(Position position);

    /**
     * @brief showPosFirst
     *
     * This method allows to reveal the first position at the start of
     * of the game
     *
     * @param position is the first position to reveal at the start of
     * game
     */
    void showPosFirst(Position position);

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
     * @brief showPositionAround
     *
     * This method allows to analyze the position around the position
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
    bool showPositionAround(Position position);

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

    // display en mode console
    /**
     * @brief displayBoard
     *
     * This method allows to diplayed the board in the console
     */
    void displayBoard();


private:
    /**
     * @brief board_
     *
     * This attribute is a vector of vector of char who represent
     * the board
     * With this attribute we can create the board 2D (height*width)
     */
    vector<vector<char>> board_;

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
     * with the method showPositionAround
     */
    queue <Position, list <Position>> queueToVisit_;

    /**
     * @brief posBombs_
     *
     * This attribute is a vector who contain each position where place
     * the bombs on the board
     */
    vector <Position> posBombs_;

    /**
     * @brief posFlags_
     *
     * This attribute is a vector who there are a flag in the board
     */
    vector <Position> posFlags_;

    /**
     * @brief nbMine_
     *
     * This attribute is an integer represent the number of bombs
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

};
}


#endif // BOARD_H
