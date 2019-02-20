#include "headers/model/player.h"
#include <string>

namespace model {
using namespace std;

Player::Player()
{
    this->name_ = "User1";
}

Player::Player(const string name)
{
    this->name_=name;
}

string Player::getName()
{
    return this->name_;
}

void Player::setName(std::string name)
{
    this->name_ = name;
}


}//end namespace model
