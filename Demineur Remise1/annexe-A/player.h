#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "score.h"
#include "time.h"

namespace model {

/** \Player
 *
 * @brief The Player class allows to build a player for the game
 * the player have just a name for the game
 *
 */
class Player
{
public:

    /**
     * @brief Player
     *
     * This is the constructor of the class Player without parameter
     */
    Player();

    /**
     * @brief Player
     *
     * This is the constructor of the class Player with the parameter
     * name
     *
     * @param name is a string which the name of the player
     */
    Player(const string name);

    /**
     * @brief getName
     *
     * This method allows to return the name of the player
     *
     * @return a string which is the name of the player
     */
    string getName();


Private:

    /**
     * @brief name_
     *
     * This attribute is the name of the player
     *
     */
    string name_;

};


}



#endif // PLAYER_H
