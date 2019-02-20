/*
#define CATCH_CONFIG_MAIN

#include "headers/tests/test.h"
#include "headers/tests/catch.hpp"
#include "headers/model/player.h"

using namespace model;

TEST_CASE("test1 the constructor for create a Player ")
{
    Player player = Player();
    SECTION("test1 the default constructor of Player")
    {
        REQUIRE (player.getName()=="User1");
    }
}

TEST_CASE("test2 the constructor for create a Player ")
{
    Player player = Player("MegaMitch");
    SECTION("test2 the constructor of Player with the name MegaMitch")
    {
        REQUIRE (player.getName()=="MegaMitch");
    }
}
*/
