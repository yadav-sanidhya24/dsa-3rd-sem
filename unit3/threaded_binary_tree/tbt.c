#include <stdio.h>
#include <stdlib.h>
#include "tbt.h"

node *getnode(int x)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->left = temp->right =NULL;
    temp->lthread = temp->rthread = 1;
    temp->key=x;
    return temp;
}

void init(tree *ptr_tree)
{
    ptr_tree->root = NULL;
}
static void freenodes(node *root)
{
    if(root)
    {
        freenodes(root->left);
        freenodes(root->right);
        free(root);
    }
}
void deinit(tree *ptr_tree)
{
    freenodes(ptr_tree->root);
    ptr_tree->root=NULL;
}

void insert(tree *ptr_tree, int x)
{
    node *temp = getnode(x);
    node  *curr = ptr_tree->root;
    node *parent=NULL;
    while(curr!=NULL)
    {
        parent = curr;
        if(x < curr->key)
        {
            if(curr->lthread==0)
                curr=curr->left;
            else
                break;
        }
        else
        {
            if(curr->rthread==0)
                curr=curr->right;
            else
                break;
        }
    }
    if(parent==NULL)
    {
        ptr_tree->root=temp;return;
    }
    if(x < parent->key)
    {
        temp->left = parent->left;
        temp->right = parent;
        parent->left=temp;
        parent->lthread = 0;
    }
    else
    {
        temp->right = parent->right;
        temp->left = parent;
        parent->right = temp;
        parent->rthread = 0;
    }
}

void disp(tree *ptr_tree)
{
    if(ptr_tree->root==NULL)
    {
        return;
    }
    node* curr = ptr_tree->root;
    while(curr->lthread==0)
    {
        curr = curr->left;
    }

    while(curr!=NULL)
    {
        printf("%d ->",curr->key);

        if(curr->rthread==1)
        {
            curr=curr->right;
        }
        else
        {
            curr=curr->right;
            while(curr!=NULL && curr->lthread==0)
            {
                curr=curr->left;
            }
        }
    }
    printf("NULL\n");
}