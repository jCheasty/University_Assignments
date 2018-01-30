#include "complex.h"

    /* For this exercise you should start by copying the source files from
    the previous exercise into the Ex3 directory. Starting from this point the objective of
    this exercise is then to re-implement the operations from Exercise 1.2 using operator
    overloading. In particular you should provide implementations for the following
    operators: +, -, *. */

int main(){

    myComplex a,e;
    myComplex b(2.3,21.3),c(4.5, 8.9),d(45.6,7.7);

    a.setReal(7.7);
    a.setImage(25.6);
    cout<<"Number a: "<<a.getReal()<<"+"<<a.getImage()<<"i"<<endl;
    cout<<"Number b: "<<b.getReal()<<"+"<<b.getImage()<<"i"<<endl;
    cout<<"Number c: "<<c.getReal()<<"+"<<c.getImage()<<"i"<<endl;
    cout<<"Number d: "<<d.getReal()<<"+"<<d.getImage()<<"i"<<endl;
    cout<<"Number e: "<<e.getReal()<<"+"<<e.getImage()<<"i"<<endl;


    b=b+a;
    cout<<endl<<"b=b+a: ";
    b.print();

    c=c-a;
    cout<<"c=c-a: ";
    c.print();

    d=d*a;
    cout<<"d=d*a: ";
    d.print();

    e=b+d;
    cout<<"e=b+d: ";
    e.print();

    return 0;
}

/*Sample I/O:

Number a: 7.7+25.6i
Number b: 2.3+21.3i
Number c: 4.5+8.9i
Number d: 45.6+7.7i
Number e: 0+0i

b=b+a: 10+46.9i
c=c-a: -3.2-16.7i
d=d*a: 154+1226.65i
e=b+d: 164+1273.55i

Process finished with exit code 0
*/