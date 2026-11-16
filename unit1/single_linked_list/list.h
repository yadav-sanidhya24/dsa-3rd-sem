#ifndef LIST_H
#define LIST_H

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node* getnode(int x);
void freenode(node *p);
node* init_list();
node* insert_front(node *list,int value);
node* del_front(node *list);
node* insert_end(node *list,int value);
node* del_end(node *list);
node* insert_after(node *list, int val1, int val2);
node* del_val(node *head,int val);
void display(node *list);
void del_list(node*head);

#endif