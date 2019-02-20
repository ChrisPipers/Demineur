/*
#define CATCH_CONFIG_MAIN

#include "headers/tests/test.h"
#include "headers/tests/catch.hpp"
#include "headers/model/time.h"
#include "iostream"
#include <unistd.h>


using namespace std;
using namespace model;

TEST_CASE("test1 the constructor ")
{
    Time time;


    cout << time.getTime() << endl;
    sleep(4000u);

    time.setTimePassed();
    cout << time.getTimePassed()<< endl;

    SECTION("create a Board without parameter")
    {

    }
}
*/
