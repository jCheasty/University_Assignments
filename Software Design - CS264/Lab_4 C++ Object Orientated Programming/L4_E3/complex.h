#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class myComplex{

public:
    myComplex();
    myComplex(double, double);

    void print();
    double getReal();
    void setReal(double);
    double getImage();
    void setImage(double);

    myComplex operator + (const myComplex &z);
    myComplex operator - (const myComplex &z);
    myComplex operator * (const myComplex &z);

protected:
    double real, image;
};