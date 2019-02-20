/*
#define CATCH_CONFIG_MAIN

#include "headers/tests/test.h"
#include "headers/tests/catch.hpp"
#include "headers/model/position.h"

using namespace model;

TEST_CASE("test1 the constructor for create a Position ")
{
   Position position = Position(1,1);

   SECTION("test1 the constructor of Position")
   {
        REQUIRE (position.getAbs()==1);
        REQUIRE (position.getOrd()==1);
    }
}


TEST_CASE("test2 the constructor for create a Position ")
{
   Position position = Position(9,9);

   SECTION("test2 the constructor of Position")
   {
        REQUIRE (position.getAbs()==9);
        REQUIRE (position.getOrd()==9);
    }
}


TEST_CASE("test3 the constructor for create a Position ")
{
   Position position = Position(1,5);

   SECTION("test3 the constructor of Position ")
   {
        REQUIRE (position.getAbs()==1);
        REQUIRE (position.getOrd()==5);
    }
}


TEST_CASE("test1 the method setAbs on a Position ")
{
   Position position = Position(1,1);
   position.setAbs(9);

   SECTION("test the attribute abs of a position is modified ")
   {
        REQUIRE (position.getAbs()==9);
        REQUIRE (position.getOrd()==1);
    }
}

TEST_CASE("test1 the method setOrd a Position ")
{
   Position position = Position(1,1);
   position.setOrd(9);

   SECTION("test the attribute ord of a position is modified ")
   {
        REQUIRE (position.getAbs()==1);
        REQUIRE (position.getOrd()==9);
    }
}

TEST_CASE("test1 the method surcharge operator == for a Position ")
{
   Position position1 = Position(1,1);
   Position position2 = Position(1,1);

   SECTION("test if the surchage == is functionnal ")
   {
        REQUIRE ( (position1==position2) == true);
    }
}

TEST_CASE("test2 the method surcharge operator == for a Position ")
{
   Position position1 = Position(1,1);
   Position position2 = Position(1,9);

   SECTION("test if the surchage == is functionnal ")
   {
        REQUIRE ( (position1==position2) == false);
    }

}

TEST_CASE("test3 the method surcharge operator == for a Position ")
{
   Position position1 = Position(1,9);
   Position position2 = Position(9,1);

   SECTION("test if the surchage == is functionnal ")
   {
        REQUIRE ( (position1==position2) == false);
    }

}

TEST_CASE("test4 the method surcharge operator == for a Position ")
{
   Position position1 = Position(1,9);
   Position position2 = Position(1,9);

   SECTION("test if the surchage == is functionnal ")
   {
        REQUIRE ( (position1==position2) == true);
    }

}

TEST_CASE("test5 the method surcharge operator == for a Position ")
{
   Position position1 = Position(10,17);
   Position position2 = Position(10,17);

   SECTION("test if the surchage == is functionnal ")
   {
        REQUIRE ( (position1==position2)== true);
    }

}

TEST_CASE("test6 the method surcharge operator == for a Position ")
{
   Position position1 = Position(10,17);
   Position position2 = Position(10,17);

   SECTION("test if the surchage == is functionnal ")
   {
        REQUIRE ( (position1==position2));
    }

}

TEST_CASE("test1 the method surcharge operator < for a Position ")
{
    Position position1 = Position(1,1);
    Position position2 = Position(1,1);

    SECTION("test if the surchage < is functionnal with two position equivalent ")
    {
        REQUIRE ( (position1<position2) == false);
    }
}

TEST_CASE("test2 the method surcharge operator < for a Position ")
{
    Position position1 = Position(1,1);
    Position position2 = Position(1,9);

    SECTION("test if the surchage < is functionnal with the first position smaller ( ord smaller )")
    {
        REQUIRE ( (position1<position2) == true);
    }
}

TEST_CASE("test3 the method surcharge operator < for a Position ")
{
    Position position1 = Position(1,1);
    Position position2 = Position(9,1);

    SECTION("test if the surchage < is functionnal with the first position smaller ( abs smaller )")
    {
        REQUIRE ( (position1<position2) == true);
    }
}

TEST_CASE("test4 the method surcharge operator < for a Position ")
{
    Position position1 = Position(1,9);
    Position position2 = Position(1,1);

    SECTION("test if the surchage < is functionnal with the first position bigger ( ord bigger )")
    {
        REQUIRE ( (position1<position2) == false);
    }
}

TEST_CASE("test5 the method surcharge operator < for a Position ")
{
    Position position1 = Position(9,1);
    Position position2 = Position(1,1);

    SECTION("test if the surchage < is functionnal with the first position bigger ( abs bigger )")
    {
        REQUIRE ( (position1<position2) == false);
    }
}

TEST_CASE("test6 the method surcharge operator < for a Position ")
{
    Position position1 = Position(9,9);
    Position position2 = Position(1,1);

    SECTION("test if the surchage < is functionnal with the first position smaller ( ord and abs smaller )")
    {
        REQUIRE ( (position1<position2) == false);
    }
}

TEST_CASE("test7 the method surcharge operator < for a Position ")
{
    Position position1 = Position(1,1);
    Position position2 = Position(9,9);

    SECTION("test if the surchage < is functionnal with the first position smaller ( ord and abs bigger )")
    {
        REQUIRE ( (position1<position2) == true );
    }
}

*/
