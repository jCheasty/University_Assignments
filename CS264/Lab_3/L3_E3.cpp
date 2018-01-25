#include <iostream>
using namespace std;

    /*Write a program, using struct’s, that reads in the name and age of a
    list of people, and again, prints them out in reverse. The program should store the
    above details using an array of structs. Initially the program should ask the user for
    the number of people that will be input.*/

struct Person{
    string name;
    int age{};
};

int main(){
    int N;
    cout<<"Enter number of people: ";
    cin>>N;
    Person people[N];
    for(int i=0;i<N;++i){
        cout<<"Enter name for person "<<i+1<<": ";
        cin>>people[i].name;
        cout<<"Enter age for person "<<i+1<<": ";
        cin>>people[i].age;
    }
    for(int i=0;i<N;++i){
        cout<<endl<<"Person "<<N-i<<":"<<endl;
        cout<<"Name: "<<people[N-i-1].name<<endl;
        cout<<"Age: "<<people[N-i-1].age<<endl;
    }
    return 0;

}

/* Sample Output:

Enter number of people: 5

Enter name for person 1:Bill
Enter age for person 1:23

Enter name for person 2:Ted
Enter age for person 2:34

Enter name for person 3:Andy
Enter age for person 3:45

Enter name for person 4:Jeff
Enter age for person 4:12

Enter name for person 5:Hao
Enter age for person 5:34

Person 5:   Person 4:   Person3:    Person2:    Person1:
Name: Hao   Name: Jeff  Name: Andy  Name: Ted   Name: Bill
Age: 34     Age: 12     Age: 45     Age: 34     Age: 23

Process finished with exit code 0
*/