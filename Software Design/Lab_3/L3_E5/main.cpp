#include "customer.h"

    /*Now take a look at the last slide from the section of the notes on
    functions. In that section you will see how it is possible to separate out particular
    sets of routines into a separate implentation and header file which can be compiled
    independently to the main program. Following this approach separate out the example
    struct’s program such that the program source consists of a file called customer.h,
    customer.cpp, and main.cpp.*/

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