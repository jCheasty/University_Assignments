#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

   /*Write a program that simulates the rolling of two dice. The program
    should call rand to roll the first die, and call rand again to roll the second die. The
    sum of the two values should then be calculated. Your program should roll the pair of
    dice a user specified number of times, keeping track of the number of times each possible
    total value occurs. To do this it should use an array of 11 items (since there are only 11
    possible outcomes i.e. 2 to 12). At the end of the run the program should print out, in a
    tabulated format, the percentage of times each possible total value occurs.*/


int rolldice();

int main(){

    double rolls, freq[]={0,0,0,0,0,0,0,0,0,0,0};
    double pfreq[]={0,0,0,0,0,0,0,0,0,0,0};
    srand(static_cast<unsigned int>(time(nullptr)));

    cout<<"Specify number of rolls: ";//Normally Distributed for a large 'rolls' value(CLT).
    cin>>rolls;

    for(int i=0; i<rolls; ++i)
        freq[rolldice()-2]++;
    for(int i=0; i<11; ++i)
        pfreq[i] = freq[i] / rolls * 100;

    cout<<left<<setw(15)<<"Outcome:"<<setw(15)<<"Frequency:"<<"%Frequency:"<<endl;
    for(int i=0; i<11; ++i)
        cout<<left<<setw(15)<<i+2<<setw(15)<<freq[i]<<pfreq[i]<<"%"<<endl;
    return 0;
}

int rolldice(){
    int firstroll=0, secondroll=0;
    firstroll=rand()%6+1;
    secondroll=rand()%6+1;
    return firstroll+secondroll;
}

/*Sample Output:

Specify number of rolls:2000
 2000
Outcome:       Frequency:     %Frequency:
2              49             2.45%
3              87             4.35%
4              164            8.2%
5              224            11.2%
6              281            14.05%
7              340            17%
8              283            14.15%
9              242            12.1%
10             174            8.7%
11             104            5.2%
12             52             2.6%

Process finished with exit code 0*/