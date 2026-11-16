#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    node* head = init_list();
    display(head);
    head=insert_front(head,10);
    display(head);
    head=insert_end(head,20);
    display(head);
    head=insert_end(head,40);
    display(head);
    head=insert_after(head,20,30);
    display(head);
    head=insert_after(head,70,10);
    display(head);
    return 0;
}