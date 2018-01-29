#include <iostream>
using namespace std;

    /*Write a program which allows the user to input a sequence of doubles
    and then prints that sequence in reverse. The length of the sequence should be specified
    by the user at run-time. Hence, initially the program should ask the user to input how
    many numbers the sequence will contain.*/

int main(){
    int n;
    cout<<"Specify number of doubles: ";
    cin>>n;
    double arr[n];
    for(int i=0; i<n; ++i)
        cin>>arr[i];
    for(int i=0; i<n; ++i)
        cout<<arr[n-i-1]<<" ";
    return 0;
}

/* Sample Output:
 *
 * Specify number of doubles:5
 * 1.2 3.4 5.6 7.8 1.9
 * 1.9 7.8 5.6 3.4 1.2
 */