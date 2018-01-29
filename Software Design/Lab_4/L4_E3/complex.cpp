#include "complex.h"

myComplex::myComplex(){
    real=0;
    image=0;
}

myComplex::myComplex(double r, double i){
    real=r;
    image=i;
}

void myComplex::print(){
    if(image<0)
        cout<<real<<image<<"i"<<endl;
    else
        cout<<real<<"+"<<image<<"i"<<endl;
}

double myComplex::getReal(){return real;}
double myComplex::getImage(){return image;}

void myComplex::setReal(double r){real=r;}
void myComplex::setImage(double i){image=i;}

myComplex myComplex::operator+(const myComplex &z) {
    myComplex temp;
    temp.real=real+z.real;
    temp.image=image+z.image;
    return temp;
}

myComplex myComplex::operator-(const myComplex &z) {
    myComplex temp;
    temp.real=real-z.real;
    temp.image=image-z.image;
    return temp;
}

myComplex myComplex::operator*(const myComplex &z) {
    myComplex temp;
    temp.real= real*z.real-image*z.image;
    temp.image=real*z.image+z.real*image;
    return temp;
}