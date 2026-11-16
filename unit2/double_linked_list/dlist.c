#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

node* getnode(int x)
{
    node *list_node = (node*)malloc(sizeof(node));
    if(list_node==NULL)
    {
        printf("Error in memory allocation\n");
        return list_node;
    }
    list_node -> data = x;
    list_node ->prev = NULL;
    list_node -> next = NULL;
    return list_node;
}


node* init_list()
{
    return NULL;
}


void freenode(node* list_node)
{
    if(list_node!=NULL)
    {
        free(list_node);
    }
    return;
}


node* insert_front(node* head, int x)
{
    if(head==NULL)
    {
        head = getnode(x);
        return head;
    }
    node *p = getnode(x);
    p->prev = NULL;
    p->next = head;
    head->prev=p;
    head = p;
    return head;
}

node* del_front(node* head)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return head;
    }
    node *p = head;
    head = head -> next;
    if(head!=NULL)
    {
        head ->prev = NULL;
    }
    freenode(p);
    return head;
}

node* insert_end(node* head, int x)
{
    if(head==NULL)
    {
        head= insert_front(head,x);
        return head;
    }
    node *p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    node *temp = getnode(x);
    p->next = temp;
    temp->prev = p;
    return head;
}

node* del_end(node* head)
{
    if(head==NULL)
    {
        return head;
    }
    node *p = head;
    if(head->next==NULL)
    {
        head = del_front(head);
        return head;
    }
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->prev->next = NULL;
    freenode(p);
    return head;
}


node* insert_after(node* head,int val, int x)
{
    if(head==NULL)
    {
        printf("Empty list\n");
        return head;
    }
    if(head->data==val)
    {
        node* temp = getnode(x);
        temp->next = head->next;
        temp -> prev = head;
        if(head->next!=NULL)
        {
            head->next->prev=temp;
        }
        head->next = temp;
        return head;
    }
    node *p = head;
    while(p->next!=NULL && p->data!=val)
    {
        p=p->next;
    }
    if(p->data==val)
    {
        node *temp = getnode(x);
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        if(temp->next!=NULL)
        {
            temp->next->prev = temp;
        }
        return head;
    }
    printf("value not found\n");
    return head;
}

node* del_val(node* head,int val)
{
    if(head==NULL)
    {
        printf("Empty list\n");
        return head;
    }
    if(head->data==val)
    {
        head = del_front(head);
        return head;
    }
    node*p = head;
    while(p->next!=NULL && p->data!=val)
    {
        p=p->next;
    }
    if(p->next==NULL && p->data==val)
    {
        head = del_end(head);
        return head;
    }
    if(p->data==val)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        freenode(p);
        return head;
    }
    printf("value not found");
    return head;

}


void display_forward(node* head)
{
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    node *p = head;
    while(p!=NULL)
    {
        printf("%d -> ",p->data);
        p=p->next;
    }
    printf("NULL\n");
}


void display_backward(node* head)
{
    node *p = head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p!=NULL)
    {
        printf("%d -> ",p->data);
        p=p->prev;
    }
    printf("NULL\n");
}


node* del_list(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node *p = head;
    while(p!=NULL)
    {
        node* temp = p;
        p=p->next;
        freenode(temp);
    }
    return NULL;  
}