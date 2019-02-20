/*
#define CATCH_CONFIG_MAIN

#include "headers/tests/test.h"
#include "headers/tests/catch.hpp"
#include "headers/model/board.h"

#include <cmath>
#include <stdexcept>
#include <iomanip>

using namespace model;
using namespace std;


TEST_CASE("test1 the constructor ")
{
    Board b = Board();

    SECTION("create a Board without parameter")
    {
        REQUIRE (b.getHeight()==9);
        REQUIRE (b.getWidth()==9);
    }
}

TEST_CASE("test2 the constructor ")
{
    Board b = Board(20,20);
    SECTION("create a Board with parameter")
    {
        REQUIRE (b.getHeight()==20);
        REQUIRE (b.getWidth()==20);
    }
}

TEST_CASE("test3 the constructor ")
{
    Board b = Board(24, 14);
    SECTION("create a Board with parameter")
    {
        REQUIRE (b.getWidth()==24);
        REQUIRE (b.getHeight()==14);
    }
}

TEST_CASE("test1 initBoard ")
{
    Board b = Board(20, 20);
    SECTION("create a Board by default and verify the initilization and the number of bombs and if the position select isn't a bombs")
    {
        REQUIRE (b.getValPosition(Position(0,0))=='d');
        REQUIRE (b.getValPosition(Position(19,19))=='d');
        REQUIRE (b.getValPosition(Position(0,19))=='d');
        REQUIRE (b.getValPosition(Position(19,0))=='d');
    }
}

TEST_CASE("test2 initBoard ")
{
    Board b = Board(24, 10);
    SECTION("create a Board and verify the initilization")
    {
        REQUIRE (b.getValPosition(Position(0,0))=='d');
        REQUIRE (b.getValPosition(Position(23,9))=='d');
        REQUIRE (b.getValPosition(Position(0,9))=='d');
        REQUIRE (b.getValPosition(Position(23,0))=='d');
    }
}

TEST_CASE("test1 setPourcentMines() ")
{
    Board b = Board(20, 20);
    double percentBombs = 0.5;
    b.setPourcentMines(percentBombs);

    SECTION("create a Board and verify the setter setPourcentMines() with the valor 0.5")
    {
        REQUIRE_NOTHROW (b.setPourcentMines(percentBombs));
    }
}

TEST_CASE("test2 setPourcentMines() ")
{
    Board b = Board(20, 20);
    double percentBombs = 0.05;

    SECTION("create a Board and verify the setter setPourcentMines() with the valor 0.05")
    {
        REQUIRE_NOTHROW (b.setPourcentMines(percentBombs));
    }
}

TEST_CASE("test3 setPourcentMines() ")
{
    Board b = Board(20, 20);
    double percentBombs = 0.90;

    SECTION("create a Board and verify the setter setPourcentMines() with the valor 0.90")
    {
        REQUIRE_NOTHROW (b.setPourcentMines(percentBombs));
    }
}

TEST_CASE("test4 setPourcentMines() ")
{
    Board b = Board(20, 20);
    double percentBombs = 1.0;

    SECTION("create a Board and verify the setter setPourcentMines() with the valor 1.00")
    {
        REQUIRE_THROWS (b.setPourcentMines(percentBombs));
    }
}

TEST_CASE("test5 setPourcentMines() ")
{
    Board b = Board(20, 20);
    double percentBombs = 1.10;

    SECTION("create a Board and verify the setter setPourcentMines() with the valor 1.10")
    {
        REQUIRE_THROWS (b.setPourcentMines(percentBombs));
    }
}

TEST_CASE("tes6 setPourcentMines() ")
{
    Board b = Board(20, 20);
    double percentBombs = -0.10;

    SECTION("create a Board and verify the setter setPourcentMines() with the valor -0.10")
    {
        REQUIRE_THROWS (b.setPourcentMines(percentBombs));
    }
}

TEST_CASE("test7 setPourcentMines() ")
{
    Board b = Board(20, 20);
    double percentBombs = -1.10;

    SECTION("create a Board and verify the setter setPourcentMines() with the valor -1.10")
    {
        REQUIRE_THROWS (b.setPourcentMines(percentBombs));
    }
}

TEST_CASE("test8 setPourcentMines() ")
{
    Board b = Board(20, 20);
    double percentBombs = 0;

    SECTION("create a Board and verify the setter setPourcentMines() with the valor 0.00 ( 0 ) ")
    {
        REQUIRE_THROWS (b.setPourcentMines(percentBombs));
    }
}

TEST_CASE("test1 setNbMines() ")
{
    Board b = Board(20, 20);
    int  nbBombs = 1;

    SECTION("create a Board and verify the setter setNbMines() with the valor 1 on a board of 400 cases")
    {
        REQUIRE_NOTHROW (b.setNbMines(nbBombs));
    }
}

TEST_CASE("test2 setNbMines() ")
{
    Board b = Board(20, 20);
    int  nbBombs = 18;

    SECTION("create a Board and verify the setter setNbMines() with the valor 18 on a board of 400 cases")
    {
        REQUIRE_NOTHROW (b.setNbMines(nbBombs));
    }
}

TEST_CASE("test3 setNbMines() ")
{
    Board b = Board(20, 20);
    int  nbBombs = 350;

    SECTION("create a Board and verify the setter setNbMines() with the valor 350 on a board of 400 cases")
    {
        REQUIRE_NOTHROW (b.setNbMines(nbBombs));
    }
}

TEST_CASE("test4 setNbMines() ")
{
    Board b = Board(20, 20);
    int  nbBombs = 0;

    SECTION("create a Board and verify the setter setNbMines() with the valor 0 on a board of 400 cases")
    {
        REQUIRE_THROWS (b.setNbMines(nbBombs));
    }
}

TEST_CASE("test5 setNbMines() ")
{
    Board b = Board(20, 20);
    int  nbBombs = 400;

    SECTION("create a Board and verify the setter setNbMines() with the valor 400 on a board of 400 cases")
    {
        REQUIRE_THROWS (b.setNbMines(nbBombs));
    }
}

TEST_CASE("test6 setNbMines() ")
{
    Board b = Board(20, 20);
    int  nbBombs = 401;

    SECTION("create a Board and verify the setter setNbMines() with the valor 401 on a board of 400 cases")
    {
        REQUIRE_THROWS (b.setNbMines(nbBombs));
    }
}

TEST_CASE("test7 setNbMines() ")
{
    Board b = Board(20, 20);
    int  nbBombs = -1;

    SECTION("create a Board and verify the setter setNbMines() with the valor -1 on a board of 400 cases")
    {
        REQUIRE_THROWS (b.setNbMines(nbBombs));
    }
}

TEST_CASE("test8 setNbMines() ")
{
    Board b = Board(20, 20);
    int  nbBombs = -100;

    SECTION("create a Board and verify the setter setNbMines() with the valor -100 on a board of 400 cases")
    {
        REQUIRE_THROWS (b.setNbMines(nbBombs));
    }
}

TEST_CASE("test1 initBombs(), defaultBombs(), and placeBombs() ")
{
    Board b = Board();
    // int choix avec bombes par defaut
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(5,5);
    // nombre de bombe a trouver par defaut calculer via une calculette selon la formule
    // 0.0002*(width*heigh)²+0.0938*(width*heigh)+0.8937
    int nbBomb = 10;

    b.initBombs(choice, posDepart);

    b.placeBombs();

    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            if (b.getValPosition(Position(x,y))=='b')
            {
                bombFind+=1;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(5,5));

    SECTION("create a Board by default 9*9 and verify the initilization of the number of bombs by default and if the position select isn't a bombs")
    {
        REQUIRE (bombFind == nbBomb);
        REQUIRE (charPosSel!='b');
    }
}

TEST_CASE("test2 initBombs(), defaultBombs() and placeBombs() ")
{
    Board b = Board(20,20);
    // int choix avec bombes par defaut
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(5,5);
    // nombre de bombe a trouver par defaut calculer via une calculette selon la formule
    // 0.0002*(width*heigh)²+0.0938*(width*heigh)+0.8937
    int nbBomb = 70;

    b.initBombs(choice, posDepart);

    b.placeBombs();

    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(5,5));

    SECTION("create a Board by choice 20*20 and verify the initilization of the number of bombs by default and if the position select isn't a bombs")
    {
        REQUIRE ( bombFind == nbBomb );
        REQUIRE (charPosSel != 'b');
    }
}

TEST_CASE("test3 initBombs(), defaultBombs() and placeBombs() ")
{
    Board b = Board(5,5);
    // int choix avec bombes par defaut
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(2,2);
    // nombre de bombe a trouver par defaut calculer via une calculette selon la formule
    // 0.0002*(width*heigh)²+0.0938*(width*heigh)+0.8937
    int nbBomb = 3;

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(2,2));

    SECTION("create a Board by choice 5*5 and verify the initilization of the number of bombs by default  and if the position select isn't a bombs")
    {
        REQUIRE ( bombFind == nbBomb );
        REQUIRE (charPosSel != 'b');
    }
}

TEST_CASE("test1 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board();
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(2,2);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.30;
    int nbBomb = (9*9)*pNbBomb;

    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(2,2));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by default 9*9 and verify the initilization and the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test2 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(5,5);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.50;
    int nbBomb = (20*20)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(5,5));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 20*20 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test3 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(5,5);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.50;
    int nbBomb = (5*5)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 5*5 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test4 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(5,5);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.20;
    int nbBomb = (5*5)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 5*5 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test5 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(5,5);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.21;
    int nbBomb = (5*5)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 5*5 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

// the twelve next test is for verify the rounded of the number of bomb
TEST_CASE("test6 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.20;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test7 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.21;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test8 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.22;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test9 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.23;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test10 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.24;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test11 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.25;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test12 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.26;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test13 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.27;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test14 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.28;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test15 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.29;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test16 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.30;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test17 initBombs(), pourcentBombs() and placeBombs() ")
{
    Board b = Board(9,9);
    // int choix avec un pourcentage de bombes
    int choice = 2;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    double pNbBomb = 0.33;
    int nbBomb = (9*9)*pNbBomb;
    b.setPourcentMines(pNbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));
    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by choice 9*9 and verify the initilization of the percent of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test1 initBombs(), nbBombs() and placeBombs() ")
{
    Board b = Board();
    // int choix avec un pourcentage de bombes
    int choice = 3;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    int nbBomb = 20;
    b.setNbMines(nbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    SECTION("create a Board by default 9*9 and verify the initilization of the number of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}


TEST_CASE("test2 initBombs(), nbBombs() and placeBombs() ")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 3;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    int nbBomb = 20;
    b.setNbMines(nbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    SECTION("create a Board by choice 20*20 and verify the initilization of the number of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test3 initBombs(), nbBombs() and placeBombs() ")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 3;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    int nbBomb = 190;
    b.setNbMines(nbBomb);

    b.initBombs(choice, posDepart);

    b.placeBombs();

    //verifie si le nombre de bombes correspond au nombre attendu
    int bombFind = 0;
    for (int x = 0; x < b.getWidth(); x++)
    {
        for (int y = 0; y < b.getHeight(); y++)
        {
            char temp = b.getValPosition(Position(x,y));
            if (temp=='b' )
            {
                bombFind++;
            }
        }
    }
    char charPosSel = b.getValPosition(Position(0,0));

    SECTION("create a Board by default 9*9 and verify the initilization of the number of bombs by choice and if the position select isn't a bombs")
    {
        REQUIRE ( nbBomb == bombFind);
        REQUIRE ( charPosSel != 'b');
    }
}

TEST_CASE("test1 placeFlagPosition()")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(0,0);
    // pourcentage de bombe selectionner
    b.initBombs(choice, posDepart);

    b.placeBombs();

    b.placeFlagPosition(Position (0,0));
    b.placeFlagPosition(Position (5,5));
    b.placeFlagPosition(Position (19,19));

    SECTION("create a Board by default 20*20 and put 3 flags at (0,0), (5,5) and (19,19)")
    {
        REQUIRE ((b.getValPosition(Position(0,0)) =='f'));
        REQUIRE ((b.getValPosition(Position(5,5)) =='f'));
        REQUIRE ((b.getValPosition(Position(19,19)) =='f'));
    }
}

TEST_CASE("test2 placeFlagPosition()")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(1,1);
    // pourcentage de bombe selectionner
    b.initBombs(choice, posDepart);

    b.placeBombs();

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by default 20*20 and put 3 flags at (-1,-1), (0,0), (19,19) and (20,20)")
    {
        //REQUIRE_THROWS_AS(b.placeFlagPosition(Position (-1,-1)),std::out_of_range);
        REQUIRE_NOTHROW ((b.placeFlagPosition(Position (0,0))));
        REQUIRE_NOTHROW ((b.placeFlagPosition(Position (19,19))));
        //REQUIRE_THROWS(b.placeFlagPosition(Position (20,20)));

    }
}

TEST_CASE("test1 deleteFlagPosition()")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(1,1);
    // pourcentage de bombe selectionner
    b.initBombs(choice, posDepart);

    b.placeFlagPosition(Position (0,0));
    b.placeFlagPosition(Position (5,5));
    b.placeFlagPosition(Position (19,19));

    b.deleteFlagPosition(Position(0,0));
    b.deleteFlagPosition(Position(5,5));
    b.deleteFlagPosition(Position(19,19));

    SECTION("create a Board by default 20*20 and put 3 flags at (0,0), (5,5) and (19,19) and delete them")
    {
        REQUIRE(b.getValPosition(Position(0,0))=='d');
        REQUIRE(b.getValPosition(Position(5,5))=='d');
        REQUIRE(b.getValPosition(Position(19,19))=='d');

    }
}

TEST_CASE("test1 placeClearPosition()")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(1,1);
    // pourcentage de bombe selectionner
    b.initBombs(choice, posDepart);

    b.placeClearPosition(Position (0,0));
    b.placeClearPosition(Position (5,5));
    b.placeClearPosition(Position (19,19));

    SECTION("create a Board by default 20*20 and put 3 clear position at (0,0), (5,5) and (19,19)")
    {
        REQUIRE(b.getValPosition(Position(0,0))=='c');
        REQUIRE(b.getValPosition(Position(5,5))=='c');
        REQUIRE(b.getValPosition(Position(19,19))=='c');

    }
}

TEST_CASE("test1 placeIndicePosition()")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(1,1);
    // pourcentage de bombe selectionner
    b.initBombs(choice, posDepart);

    b.placeIndicePosition(Position (0,0),1);
    b.placeIndicePosition(Position (5,5),2);
    b.placeIndicePosition(Position (19,19),3);

    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by default 20*20 and put 3 indice 1, 2, 3 at (0,0), (5,5) and (19,19)")
    {
        REQUIRE(b.getValPosition(Position(0,0))=='1');
        REQUIRE(b.getValPosition(Position(5,5))=='2');
        REQUIRE(b.getValPosition(Position(19,19))=='3');

    }
}

TEST_CASE("test2 placeIndicePosition()")
{
    Board b = Board(20,20);
    // int choix avec un pourcentage de bombes
    int choice = 1;
    // position selectionner -> donc pas de bombes
    Position posDepart = Position(1,1);
    // pourcentage de bombe selectionner
    b.initBombs(choice, posDepart);

    b.placeIndicePosition(Position (0,0),1);
    b.placeIndicePosition(Position (5,5),2);
    b.placeIndicePosition(Position (19,19),3);


    // pas verifier avec les % car calcul difficile avec les arrondit
    SECTION("create a Board by default 20*20 and put 3 indice 1, 2, 3 at (0,0), (5,5) and (19,19)"
            "and 8 at (4,4) , 9 at (6,6), -1 at (12,10) and -9 at (0,19) ")
    {
        REQUIRE((char)b.getValPosition(Position(0,0))=='1');
        REQUIRE((char)b.getValPosition(Position(5,5))=='2');
        REQUIRE((char)b.getValPosition(Position(19,19))=='3');

        REQUIRE_NOTHROW(b.placeIndicePosition(Position (4,4),8));

        REQUIRE_THROWS(b.placeIndicePosition(Position (6,6),9));
        REQUIRE_THROWS(b.placeIndicePosition(Position (12,10),-1));
        REQUIRE_THROWS(b.placeIndicePosition(Position (0,19),-9));
    }
}

TEST_CASE("test1 revelantPosFirst()")
{
    Board b = Board(15,15);
    int choice = 1;
    Position posDepart = Position(0,0);
    b.displayBoard();
    b.revelantPosFirst(1, posDepart);
    b.displayBoard();
    SECTION("create a board and revelant the position , the first position without action before")
    {
        REQUIRE((b.getValPosition(Position(0,0))=='c'||isdigit(b.getValPosition(Position(0,0)))));
    }
}

TEST_CASE("test2 revelantPosFirst()")
{
    Board b = Board(15,15);
    int choice = 1;
    Position posDepart = Position(14,14);
    b.displayBoard();
    b.revelantPosFirst(1, posDepart);
    b.displayBoard();
    //b.displayBoardForPlayer();
    SECTION("create a board and revelant the position , the first position without action before")
    {
        REQUIRE(((b.getValPosition(Position(14,14)))=='c'||isdigit(b.getValPosition(Position(14,14)))));
    }
}
*/
