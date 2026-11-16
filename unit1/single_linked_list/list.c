#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node* getnode(int x)
{
    node *p = (node*)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Error while allocating dynamic memory\n");
    }
    p->data=x;
    return p;
}



void freenode(node *p)
{
    if(p!=NULL)
        free(p);
    else
    printf("pointer is a null pointer\n");
}

node* init_list()
{
    return NULL;
}


node* insert_front(node *head,int value)
{
    node *temp = getnode(value);
    temp -> next = head;
    head = temp;
    return head;
}


node* del_front(node *head)
{
    if(head!=NULL)
    {
        node *temp = head;
        head = head->next;
        freenode(temp);
    }
    else
    {
        printf("Emptylist \n");
    }
    return head;

}


node* insert_end(node *head,int value)
{
    node *temp = getnode(value);
    temp->next=NULL;
    if(head==NULL)
    {
        head = temp;
        return head;
    }
    node *p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}


node* del_end(node *head)
{
    node *p= head;
    if(head==NULL)
    {
        printf("List is already empty\n");
        return head;
    }
    else if(p->next==NULL)
    {
        freenode(p);
        head=NULL;
        return head;
    }
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    node *last = p->next;
    freenode(last);
    p->next = NULL;
    return head;
}



node* insert_after(node *head, int val1, int val2)
{
    if(head==NULL)
    {
        printf("empty list\n");
        return head;
    }
    node*p=head;
    while(p->next!=NULL && p->data!=val1)
    {
        p=p->next;
    }
    if(p->data==val1)
    {
        node* new_node= getnode(val2);
        new_node->next = p->next;
        p->next=new_node;
        return head;
    }
    else
    {
        printf("Value not found\n");
        return head;
    }
}


node* del_val(node *head,int val)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return head;
    }
    if(head->data==val)
    {
        head = del_front(head);
        return head;
    }
    node *p=head;
    while(p->next!=NULL && p->next->data!=val)
    {
        p=p->next;
    }
    if(p->next!=NULL)
    {
        node* del_node = p->next;
        p->next = del_node->next;
        freenode(del_node);
        return head;
    }
    printf("value not found\n");
    return head;
    
}

void display(node *head)
{
    node* p = head;
    while(p!=NULL)
    {
        printf("%d -> ",p->data);
        p=p->next;
    }
    printf("NULL\n");
}

void del_list(node*head)
{
    node *p = head;
    while(p!=NULL)
    {
        node* del = p;
        p=p->next;
        freenode(del);
    }
}
