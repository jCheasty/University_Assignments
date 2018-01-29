#include "customer.h"

    /*Finally, using the above set of files(L3_E5) as a base, 
    extend functionality of the customers api such that it provides 
    all of the functionality necessary to construct a linked list 
    of people to input by the user. 
    To do this you should add the following routines:

    customer *create_list(string name);
    void insert_name(customer* head, string name);
    int list_length(customer* head);
    void print_customers(customer *head);

    Demonstrate the functionality by writing a program which allows the user to input
    an arbitrary number of customers. The program should store these customers in
    a linked list. The program should keep inputting customers until the user inputs a
    user with the name end at which point all the user details should be printed to the screen.
    */

int main(){
    string s, e="end";
    cin>>s;
    customer* head = create_list(s);
    do{
        cin>>s;
        if(s==e)
            continue;
        insert_name(head,s);
    }while(s!=e);
    print_customers(head);
    cout<<endl;
    cout<<list_length(head)<<" nodes";
    return 0;
}

/*Sample Input:
 * Bill Andy Ted Jeff Jill Holly Aoife Corban end
 *
 *Sample Output:
 * Bill --> Andy --> Ted --> Jeff --> Jill --> Holly --> Aoife --> Corban
 * 8 nodes
 *
 */