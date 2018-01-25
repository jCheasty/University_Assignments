#include <iostream>
using namespace std;

    /*Write a function, called my swap, that takes two integers as input and
    swaps their values. To demonstrate that the function works you should write a program
    that instructs the user to input two numbers. The program should store those numbers
    in two separate variables. The program should then output the values stored in the two
    variables to the screen, swap the two numbers by calling my swap, and then again print
    out the values stored in the two variables.*/


void my_swap(int &a, int &b);

int main(){
    int x,y;
    cout<<"Enter two values(0-9): ";
    cin>>x>>y;
    cout<<"Before Swap:"<<endl<<"First value: "<<x<<" Second value: "<<y<<endl;
    my_swap(x,y);
    cout<<"After Swap:"<<endl<<"First value: "<<x<<" Second value: "<<y<<endl;
    return 0;
}

void my_swap(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}