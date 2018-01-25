#include<iostream>
using namespace std;

    /*At the end of the lecture slides on struct’s, there is an example of
    creating a static link list that stores three peoples’ names. Copy this program to a file*/

struct customer{
    string name;
    customer *next{};
};

void print_customers(customer &head){

    customer *cur=&head;

    while(cur!= nullptr){
        cout<<cur->name<<endl;
        cur = cur->next;
    }
}

int main(){
    customer customer1, customer2, customer3;
    customer1.next=&customer2;
    customer2.next=&customer3;
    customer3.next= nullptr;
    customer1.name= "Jack";
    customer2.name= "Jane";
    customer3.name= "Joe";
    print_customers(customer1);
    return 0;
}
//Output: Jack Jane Joe