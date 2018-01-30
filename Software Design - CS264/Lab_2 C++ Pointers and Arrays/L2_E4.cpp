#include <iostream>
using namespace std;

    /*Write two functions with the following function prototypes:
    int my_string_len(char str[])
    void my_string_cat(char dest[], char src[], int dest size)

    Both functions should take zero-terminated strings as input. The first function should
    return the length of the string to the calling function. The second function should take
    a source and a destination string and the total size of the array pointed to by dest. It
    should then concatenate the source string onto the end of the destination string, if and
    only if the destination string has the capacity to store both strings. If the
    destination string does not have the capacity it should not alter either, print an error,
    and return to the calling function.

    Note: your functions should not use library functions such as 'strlen' or 'strcat'.

    Demonstrate the use of both the above functions by using them in a program in
    which you initialise two character arrays with two strings, print out their length, print
    out the combined length, and print out the combined string.*/

const int N=20;
int my_string_len(char str[]);
void my_string_cat(char dest[], char src[], int dest_size);

int main(){

    char s []="abra";
    char d [N]="kadabra";
    my_string_cat(s,d,sizeof(d));
    return 0;
}

int my_string_len(char str[]){
    int count=0;
    for(int i=0;str[i]!='\0';++i)
        count++;
    return count;
}

void my_string_cat(char dest[], char src[], int dest_size){

    int l1=my_string_len(src), l2=my_string_len(dest), l3=l1+l2;
    cout<<"Length of source string: "<<l1<<endl;
    cout<<"Length of destination string: "<<l2<<endl;
    cout<<"Length of combined string: "<<l3<<endl;

    if(l3>dest_size)
        cout<<"Error - Insufficient Capacity.("<<dest_size<<")";
    else{
        for(int i=l2; i<l3; ++i)
            dest[i]=src[i-l2];
        for(int j=0; dest[j]!='\0'; ++j)
            cout<<dest[j];
        cout<<endl;
    }
}

/* Sample Outputs:
 *
 * For N=11, src:'abra', dest:'kadabra' | For N=10
 * Length of source string: 7           | Length of source string: 7
 * Length of destination string: 4      | Length of destination string: 4
 * Length of combined string: 11        | Length of combined string: 11
 * abrakadabra                          | Error - Insufficient Capacity.(10)
 * */