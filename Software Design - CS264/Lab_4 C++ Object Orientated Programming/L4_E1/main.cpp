#include "die.h"

    /*Take your solution to Exercise 1.3 of Lab 2 (i.e. the dice problem) and
    rewrite it using C++ classes. In particular define a new class called die. The class
    should permit a die of any positive number of sides to be represented. The class should
    also enforce a constraint that a die should have no less that 4 sides. If the client code
    tries to construct a die of less than 4 sides the die should default to 6 sided (and print
    a informational warning message to the standard error).
    The class should provide three public methods (not including constructors, etc.):

    int roll();
    int getValue();
    int getNumsides();

    Using the resulting die class create a program that has the same functionality
    as required in Exercise 1.3 of Lab2.*/

int main(){

    int sides, n;
    cout<<"Specify number of sides on the dice: ";
    cin>>sides;
    Die dice(sides);
    n=dice.getNumSides()*2-1;
    double freq[n],pfreq[n],rolls;
    for(int i=0; i<n; ++i){
        freq[i] = 0;
        pfreq[i] = 0;
    }
    cout<<"Specify number of rolls of the dice: ";
    cin>>rolls;
    if(rolls<=0) {
        cout << "Error - Number of rolls must be positive, defaulting to 1 roll." << endl;
        rolls = 1;
    }

    for(int i=0; i<rolls; ++i)
        freq[dice.getValue()-2]++;
    for(int i=0; i<n; ++i)
        pfreq[i] = freq[i] / rolls * 100;

    cout<<left<<setw(15)<<"Outcome:"<<setw(15)<<"Frequency:"<<"%Frequency:"<<endl;
    for(int i=0; i<n; ++i)
        cout<<left<<setw(15)<<i+2<<setw(15)<<freq[i]<<pfreq[i]<<"%"<<endl;
    return 0;
}

/*Sample I/O:

Specify number of sides on the dice:3
Error - Less than 4 sides, defaulting to 6 sides.
Specify number of rolls of the dice:100

Outcome:       Frequency:     %Frequency:
2              2              2%
3              5              5%
4              8              8%
5              8              8%
6              13             13%
7              21             21%
8              12             12%
9              13             13%
10             11             11%
11             5              5%
12             2              2%
Destroying Object
Process finished with exit code 0

------------------------------------------

Specify number of sides on the dice:12
Specify number of rolls of the dice:2000

Outcome:       Frequency:     %Frequency:
2              13             0.65%
3              32             1.6%
4              45             2.25%
5              50             2.5%
6              62             3.1%
7              91             4.55%
8              90             4.5%
9              128            6.4%
10             118            5.9%
11             147            7.35%
12             157            7.85%
13             156            7.8%
14             146            7.3%
15             130            6.5%
16             124            6.2%
17             111            5.55%
18             103            5.15%
19             93             4.65%
20             64             3.2%
21             52             2.6%
22             36             1.8%
23             32             1.6%
24             20             1%
Destroying Object
Process finished with exit code 0

-----------------------------------------

Specify number of sides on the dice:4
Specify number of rolls of the dice:0
Error - Number of rolls must be positive, defaulting to 1 roll.

Outcome:       Frequency:     %Frequency:
2              0              0%
3              0              0%
4              0              0%
5              0              0%
6              0              0%
7              1              100%
8              0              0%
Destroying Object
Process finished with exit code 0

------------------------------------------
*/