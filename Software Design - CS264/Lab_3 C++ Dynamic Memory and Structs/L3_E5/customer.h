#pragma once
#include <iostream>
using namespace std;

struct customer{
    string name;
    customer* next;
};

void print_customers(customer &head);