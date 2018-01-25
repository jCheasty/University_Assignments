#include <iostream>
#include <cstring>
using namespace std;


    /*Now write a program that extends the functionality of the above
    program (Exercise 1) such that it keeps reading the sequence until it reads −1. That is, the program
    should not initially ask for the length of the sequence.

    Hint: In designing a solution to this problem you will need a list that can keep
    growing arbitrarily. This can be achieved by allocating an array of a fixed length and
    then reading numbers until the array becomes full. At this point a new array can be
    allocated which has a size of the original array plus some fixed amount. Once allocated,
    the contents of the first array should be copied to the second array (at which point
    the first array should be freed).To copy the contents of one array to the other you can
    either implement your own routine or use 'memcpy' (full detail of which can be found on
    cplusplus.com).*/

int main(){

    double d;
    int count=0,size=10;
    auto* arr = new double[size];
    cout<<"Enter arbitrary number of doubles(-1 to quit): ";
    do{
        cin>>d;
        if(d==-1)
            continue;
        else if(count>=size){
            auto tempsize= static_cast<size_t>(size + 10);
            auto* temparr = new double[tempsize];
            memcpy(temparr, arr, size*sizeof(double));
            size=tempsize;
            delete[] arr;
            arr=temparr;
        }
        arr[count] = d;
        count++;
    }while (d!=-1);

    for(int i=0;i<count;++i)
        cout<<arr[count-i-1]<<" ";
}

/*Sample Outputs:
 *
 * --------------------------
 * Input: -1
 * Output: Process finished with exit code 0
 * --------------------------
 * Input:  0 9 8 7 6 5 4 3 2 1 1 2 3 4 5 6 7 8 9 0 9 8 7 6 -1
 * Output: 6 7 8 9 0 9 8 7 6 5 4 3 2 1 1 2 3 4 5 6 7 8 9 0
 *         Process finished with exit code 0
 * --------------------------
 * Input: 3.4 5.6 6.7 7.8 3.2 0.4 7.8 4.5 1.2 6.7 8.9 6.3 7.7 123.7 546 56
 *        12.2 45 56 76 0 7.8 43.4 5.5 66.6 1.2 3.4 4.5 0.56 6.7 5.6 9.8 4.3 -1
 *
 * Output: 4.3 9.8 5.6 6.7 0.56 4.5 3.4 1.2 66.6 5.5 43.4 7.8 0 76 56 45 12.2
 *         56 546 123.7 7.7 6.3 8.9 6.7 1.2 4.5 7.8 0.4 3.2 7.8 6.7 5.6 3.4
 *         Process finished with exit code 0
 *---------------------------
 */