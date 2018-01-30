#include <iostream>
#include <algorithm>
using namespace std;

void Exercise_1();
void Exercise_2();
void Exercise_3();
void Exercise_4();
void Exercise_5();

int main(){

    int n;
    char c;
    do{
        cout<<"Choose Exercise(1-5): ";
        cin>>n;
        if(cin.fail()){
            cout<<"Error - Bad Input.";
            break;
        }
        switch(n) {
            case 1:
                Exercise_1();
                break;
            case 2:
                Exercise_2();
                break;
            case 3:
                Exercise_3();
                break;
            case 4:
                Exercise_4();
                break;
            case 5:
                Exercise_5();
                break;
            default:
                cout<<"Error - Bad Input.";
                break;
        }
        cout<<"Continue? y/n: ";
        cin>>c;

    }while(c=='y');
    return 0;
}

void Exercise_1(){

    /* Write a program that inputs three integers from the keyboard, and prints
    the sum, average, product, smallest and largest of these numbers.*/

    cout<<"Please enter three numbers: ";
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"Sum: "<<a+b+c<<endl;
    cout<<"Product: "<<a*b*c<<endl;
    cout<<"Average: "<<(a+b+c)/3<<endl;
    cout<<"Min: "<<min(min(a,b),c)<<endl;
    cout<<"Max: "<<max(max(a,b),c)<<endl;
}

void Exercise_2(){

    /*Write a program that reads in two integers and determines and prints
    if the first is a multiple of the second.*/

    int x,y;
    cout<<"Please enter two numbers: ";
    cin>>x>>y;
    if(x%y==0)
        cout<<"The first '"<<x<<"' is a multiple of the second '"<<y<<"'."<<endl;
    else
        cout<<"The first '"<<x<<"' is not a multiple of the second '"<<y<<"'."<<endl;
}

void Exercise_3(){

    /*Write a program that inputs a five-digit number, separates the number
    into its individual digits and prints the digits separated from one another by three spaces
    each.*/

    int n;
    cout<<"Input a five digit number: ";
    cin>>n;
    for(int i=0;i<5;++i){
        cout<<int(n/pow(10,(4-i)))<<"   ";
        n=n%int(floor(pow(10,(4-i))));
    }
}

void Exercise_4(){

    /*Develop a C++ program that will determine if a department-store customer
    has exceeded the credit limit on a charge account. For each customer, the following
    information is available:

    1. account number (an integer);
    2. balance at the beginning of the month;
    3. total of all items charged by the customer this month;
    4. total of all credits applied to the customer’s account this month;
    5. allowed credit limit

    The program should input this information, calculate the new balance (= beginning
    balance + charges - credits) and determine if the new balance exceeds the customer’s
    credit limit. For those customers whose credit limit is exceeded, the program should
    display the customer’s account number, credit limit, new balance and the message
    “Credit limit exceeded.”

    The program should permit multiple customer details to be inputted with the
    above information being printed to the screen after each customer. The program should
    terminate when an account number of -1 is inputted.*/

    int acc_no=0,bal=0,charges=0,credits=0,climit=0;

    do{
        cout << "Enter account number: ";
        cin >> acc_no;
        if(acc_no==-1)
            continue;

        cout << "Enter initial balance: ";
        cin >> bal;

        cout << "Enter total charges: ";
        cin >> charges;

        cout << "Enter total credits: ";
        cin >> credits;

        cout << "Enter credit limit: ";
        cin >> climit;

        bal = bal + charges - credits;
        if (bal > climit) {
            cout << "Credit Limit Exceeded!" << endl;
            cout << "Account No: " << acc_no << endl << "Credit Limit: " << climit << endl;
            cout << "Balance: " << bal << endl;
        }
    }while(acc_no!=-1);
}

void Exercise_5(){

    /*An integer is said to be prime if it is divisible only by the two distinct
    factors 1 and itself. Write a function that determines if a number is prime. Use this
    function in a program that determines and prints all the prime numbers between 1 and 5000.*/

    bool isprime=true;

    for(int i=1;i<=5000;++i) {
        if(i<2||(i%2==0&&i!=2)){
            continue;
        }
        for (int j=3;j<=sqrt(i);j=j+2){
            if(i%j==0)
                isprime=false;
        }
        if(isprime)
            cout<<i<<"| ";
        isprime=true;
    }
    cout<<endl;
}