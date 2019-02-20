/*
#define CATCH_CONFIG_MAIN

#include "headers/tests/test.h"
#include "headers/tests/catch.hpp"
#include "headers/model/timeT.h"

#include <ctime>
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace model;

TEST_CASE("test1 the constructor ")
{
    TimeT aTimet;
    SECTION("create a TimeT without parameter")
    {
        REQUIRE((aTimet.getTime()==0));
        REQUIRE((aTimet.getTimePassed()==0));
    }
}

TEST_CASE("test1 method setTimePassed()")
{
    TimeT aTimet;
    unsigned timeTemp1, timeTemp2, timeTemp3, timeTemp4;
    timeTemp1 = aTimet.getTimePassed();
    Sleep(10000);
    aTimet.setTimePassed();
    timeTemp2 = aTimet.getTimePassed();
    Sleep(10000);
    aTimet.setTimePassed();
    timeTemp3 = aTimet.getTimePassed();

    SECTION("create a TimeT without parameter")
    {
        REQUIRE((timeTemp1==0));
        REQUIRE((timeTemp2>timeTemp1));
        REQUIRE((timeTemp3>timeTemp2));
    }
}

TEST_CASE("test1 method stopTime²Passed() ")
{
    TimeT aTimet;
    Sleep(30000);
    unsigned timeEnd = aTimet.stopTimePassed();

    SECTION("create a Time an test the method stopTimePassed() after a sleep of 30 sec ( 30 000 millisec) ")
    {
        REQUIRE((timeEnd>=30));
    }
}

TEST_CASE("test2 stopTimePassed() ")
{
    TimeT aTimet;
    Sleep(60000);
    unsigned timeEnd = aTimet.stopTimePassed();

    SECTION("create a Time an test the method stopTimePassed() after a sleep of 60 sec ( 60 000 millisec) ")
    {
        REQUIRE((timeEnd>=60));
    }
}

TEST_CASE("test3 stopTimePassed() ")
{
    TimeT aTimet;
    Sleep(120000);
    unsigned timeEnd = aTimet.stopTimePassed();

    SECTION("create a Time an test the method stopTimePassed() after a sleep of 120 sec ( 120 000 millisec) ")
    {
        REQUIRE((timeEnd>=120));
    }
}
*/
