#include "customer.h"

void print_customers(customer &head){
    customer *cur = &head;
    while (cur != nullptr){
        cout<<cur->name<<endl;
        cur = cur->next;
    }
}