/*
#define CATCH_CONFIG_MAIN

#include "headers/tests/test.h"
#include "headers/tests/catch.hpp"
#include "headers/model/ruleendgame.h"

using namespace std;
using namespace model;

TEST_CASE("test1 the constructor of RulesEndGame ")
{
    Board board_;
    board_.initBoard();

    RuleEndGame ruleEndgame = RuleEndGame(board_);

    SECTION(" test with a board at the start of the party ")
    {
        REQUIRE (ruleEndgame.getIsEnd(board_)==false);
    }
}

TEST_CASE("test1 setIsEnd() ")
{
    Board board_;
    board_.initBoard();

    RuleEndGame ruleEndgame = RuleEndGame(board_);

    SECTION("test if the method return false without call this the method setIsEnd() ")
    {
        REQUIRE (ruleEndgame.getIsEnd(board_)==false);
    }
}

TEST_CASE("test2 setIsEnd() ")
{
    Board board_;
    board_.initBoard();

    RuleEndGame ruleEndgame = RuleEndGame(board_);
    ruleEndgame.setIsEnd();

    SECTION("test if the method return false with call this the method setIsEnd() ")
    {
        REQUIRE (ruleEndgame.getIsEnd(board_)==true);
    }
}

TEST_CASE("test1 allClear ")
{
    Board board_ = Board(20,20);
    board_.initBoard();

    RuleEndGame ruleEndgame = RuleEndGame(board_);


    SECTION("test with a board at the start of the party the result of the method allClear")
    {
        REQUIRE (ruleEndgame.getIsEnd(board_)==false);
    }
}

TEST_CASE("test2 allClear() ")
{


    Board board_;
    board_.initBoard();
    board_.revelantPosFirst(1,Position(3,3));

    board_.displayBoard();
    RuleEndGame ruleEndgame = RuleEndGame(board_);

    SECTION("test with a board after two clear of the party the result of the method allClear")
    {
        REQUIRE (ruleEndgame.getIsEnd(board_)==false);
    }
}

TEST_CASE("test3 allClear() ")
{


    Board board_ = Board(5,5);
    board_.initBoard();
    board_.revelantPosFirst(1,Position(3,3));
    for (int x = 0; x < board_.getHeight(); x++) {
        for (int  y = 0; y < board_.getWidth(); y++) {
            if(board_.getValPosition(Position(x,y))=='d')
            {
                board_.revelantPositionRecursif(Position(x,y));
            }
        }
    }



    board_.displayBoard();
    RuleEndGame ruleEndgame = RuleEndGame(board_);
    board_.displayBoard();

    SECTION("test with a board after two clear of the party the result of the method allClear")
    {
        REQUIRE (ruleEndgame.getIsEnd(board_)==true);
    }
}
*/


