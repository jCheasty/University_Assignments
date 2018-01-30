#include "complex.h"

    /* Create a class called MyComplex for performing arithmetic with complex
    numbers. Write a driver program to test your class. Complex numbers have the form
    z = a + ib where i =√−1.

    Use double variables to represent the protected members of the class. Provide
    a constructor function that enables an object of this class to be initialised when it is
    declared. You should also define a default constructor which initialises both a and b to
    be set equal to zero.

    You should also provide getter and setter methods for both the real and imaginary
    components of the MyComplex number:

    double getReal()
    void setReal(double)
    double getImage()
    void setImage(double)

    In this question you should implement the following methods without using operator
    overloading.
    Addition of two MyComplex numbers, using the following prototype:
    MyComplex Add(const MyComplex &z)
    Subtraction of two MyComplex numbers, using the following prototype:
    MyComplex Subtract(const MyComplex &z)
    Multiplication of two MyComplex numbers, using the following prototype:
    MyComplex Multiply(const MyComplex &z)
    For example given three objects, a, b, and c, the code
    c = a.Add(b);
    should be equivalent to c = a + b.
    You should also provide a print function to output a complex number to the
    screen in the following format: “2 + 4i”. The function should have the following
    prototype:
    void print()*/

int main(){

    myComplex a,e;
    myComplex b(2.3,1.3),c(5.6, 8.9),d(45.6,7.7);

    a.setReal(17.7);
    a.setImage(15.6);
    cout<<"Number a: "<<a.getReal()<<"+"<<a.getImage()<<"i"<<endl;
    cout<<"Number b: "<<b.getReal()<<"+"<<b.getImage()<<"i"<<endl;
    cout<<"Number c: "<<c.getReal()<<"+"<<c.getImage()<<"i"<<endl;
    cout<<"Number d: "<<d.getReal()<<"+"<<d.getImage()<<"i"<<endl;
    cout<<"Number e: "<<e.getReal()<<"+"<<e.getImage()<<"i"<<endl;


    b=b.Add(a);
    cout<<endl<<"b=b+a: ";
    b.print();

    c=c.Subtract(a);
    cout<<"c=c-a: ";
    c.print();

    d=d.Multiply(a);
    cout<<"d=d*a: ";
    d.print();

    e=b.Add(d);
    cout<<"e=b+d: ";
    e.print();

    return 0;
}

/*Sample I/O:

Number a: 17.7+15.6i
Number b: 2.3+1.3i
Number c: 5.6+8.9i
Number d: 45.6+7.7i
Number e: 0+0i

b=b+a: 20+16.9i
c=c-a: -12.1-6.7i
d=d*a: 687+847.65i
e=b+d: 707+864.55i

Process finished with exit code 0
*/