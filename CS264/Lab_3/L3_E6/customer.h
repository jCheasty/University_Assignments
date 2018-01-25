#pragma once
#include <iostream>
using namespace std;

struct customer{
    string name;
    customer* next;
};

customer* create_list(string name);
void insert_name(customer* head, string name);
void print_customers(customer *head);
int list_length(customer* head);