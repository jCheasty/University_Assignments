#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print(T ar[], int size){
    for (int i = 0; i < size; i++)
        cout << ar[i] << " ";
    cout<<"\n\n";
};

template <typename T>
void print(vector<T> vec){
    typename vector<T>::const_iterator i;
    for ( i= vec.begin(); i != vec.end(); ++i)
        cout << *i << " ";
    cout <<"\n\n";
};

int main() {

    double darr[] = {31.4, 76.6, 124.1, 4.6};
    print(darr, 4);

    string sarr[] = {"this", "is", "a", "string"};
    print(sarr, 4);


    vector<double> dvec={23.4,56.4,77.7,12.3};
    print(dvec);

    vector<string> svec={"another","test","string","for","STL"};
    print(svec);

    return 0;
}