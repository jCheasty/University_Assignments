#include "customer.h"

customer* create_list(string name){
    auto* head = new customer();
    head->name= move(name);
    head->next= nullptr;
    return head;
}

void insert_name(customer* head, string name){
    customer* temp = head;
    while(temp->next!= nullptr)
        temp=temp->next;
    temp->next=create_list(move(name));
}

void print_customers(customer *head){
    customer *cur = head;
    while (cur->next != nullptr){
        cout<<cur->name<<" --> ";
        cur = cur->next;
    }
    cout<<cur->name;
}

int list_length(customer* head){
    int count=1;
    customer* temp=head;
    while(temp->next!= nullptr) {
        temp = temp->next;
        ++count;
    }
    return count;
}