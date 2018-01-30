#include <iostream>
using namespace std;

    /*The greatest common divisor (GCD) of two integers is the largest integer
    that evenly divides into each of the two integers. Write a function called gcd that returns
    the greatest common divisor of two integers. The program should contain a function
    called gcd, with appropriate parameters and return type, that provide all of the logic
    for computing the gcd of the two inputted numbers.*/

int GCD (int a, int b);

int main(){
    int x,y;
    cout<<"Please enter two values(0-9): ";
    cin>>x>>y;
    cout<<"Greatest Common Divisor: "<<GCD(x,y);
}

int GCD(int a, int b){
    return b==0 ? a : GCD(b,a%b);
}