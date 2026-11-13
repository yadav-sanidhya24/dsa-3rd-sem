#ifndef DLIST_H
#define DLIST_H
#include <stdio.h>
typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}node;

node* getnode(int x);
node* init_list();
void freenode(node *list_node);
node* insert_front(node* head,int x);
node* del_front(node* head);
node* insert_end(node* head,int x);
node* del_end(node* head);
node* insert_after(node* head,int val,int x);
node* del_val(node* head,int val);
void display_forward(node* head);
void display_backward(node* head);
node* del_list(node* head);
#endif
