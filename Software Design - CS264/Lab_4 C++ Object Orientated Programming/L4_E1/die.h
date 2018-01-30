#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Die{
public:
    explicit Die(int);
    ~Die();

    int getNumSides();
    int roll();
    int getValue();

private:
    int sides;
};