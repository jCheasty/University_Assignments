#include <iostream>
using namespace std;

    /*Write two functions with the following function prototypes:
    void print_string_array(char str[])
    void print_string_ptr(char *str)
    Both of the above functions should print zero-terminated c-strings to the screen
    character by character i.e. by stepping through the string one character at a time and
    returning once a '\0' character is encountered. The first function should use the array
    indexing operator to achieve this, whilst the second should use a pointer to traverse the
    characters of the string.

    Demonstrate the use both the above functions by using them in a program to
    print out a string which is pre-initialised in the main function*/

void print_string_array(char str[]);
void print_string_ptr(char *str);

int main(){

    char str []="This is a super string";
    print_string_array(str);
    print_string_ptr(str);
    return 0;
}

void print_string_array(char str[]){
    cout<<"Array Indexing: ";
    for(int i=0; str[i]!='\0';++i)
        cout<<str[i];
    cout<<endl;
}

void print_string_ptr(char *str){
    cout<<"Pointer Indexing: ";
    for(int i=0; *(str+i)!='\0'; ++i)
        cout<<*(str+i);
}

/*
 * Sample Output:
 * 
 * Array Indexing: This is a super string
 * Pointer Indexing: This is a super string
 */