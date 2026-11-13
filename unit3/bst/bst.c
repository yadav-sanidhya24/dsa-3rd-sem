#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void init(tree *ptr_t)//done
{
    ptr_t->root=NULL;
}


node *getnode(int x)//done
{
    node* temp=(node*)malloc(sizeof(node));
    if(temp!=NULL)
    {
        temp->key=x;
        temp->left=NULL;
        temp->right=NULL;
    }
    return temp;
}


static node* insert_rec(node *root,node *temp)//done
{
   if(root==NULL)
   {
    root = temp;
   }
   else if(temp->key < root->key)
   {
    root->left=insert_rec(root->left,temp);
   }
   else if(temp->key >= root->key)
   {
    root->right=insert_rec(root->right,temp);
   }
   return root;
}


void insert_tree_rec(tree *ptr_t,int x)//done
{
    node *temp = getnode(x);
    ptr_t ->root= insert_rec(ptr_t->root,temp);
}


void insert_tree_iter(tree *ptr_t,int x)//done
{
    node *temp = getnode(x);
    if (ptr_t->root==NULL)
        {
            ptr_t->root = temp;
            return;
        }
    node *curr = ptr_t->root;
    node *parent = NULL;
    while(curr!=NULL)
    {
        parent = curr;
        if(temp->key < curr->key)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
    if(temp->key < parent->key)
    {
        parent->left = temp;
    }
    else
    {
        parent->right = temp;
    }
}
void inorder_rec(node *root)//done
{
    if(root!=NULL)
    {
        inorder_rec(root->left);
        printf("%d -> ",root->key);
        inorder_rec(root->right);
    }
}  

node *delete_tree(node *root,int x)//done
{
    node *curr = root, *parent = NULL;
    if (root==NULL)
    {
        return root;
    }
    while(curr!=NULL && curr->key!=x)//finding key
    {
        if(x < curr->key)
        {
            parent=curr;
            curr = curr->left;
        }
        else
        {
            parent=curr;
            curr = curr->right;
        }
    } 
    if(curr==NULL)
    {
        printf("Key not found\n");
        return root;
    }
    if(curr->left!=NULL && curr->right!=NULL)//node with both childs
    {
        node *succ, *succ_parent;
        succ = curr -> right;
        succ_parent = curr;
        while(succ->left!=NULL)
        {
            succ_parent=succ;
            succ=succ->left;
        }
        curr->key=succ->key;
        if(succ_parent->left==succ)
        {
            if(succ->left==NULL)
            {
                succ_parent->left=succ->right;
            }
            else
            {
                succ_parent->left=succ->left;
            }
        }
        else
        {
            if(succ->left==NULL)
            {
                succ_parent->right=succ->right;
            }
            else
            {
                succ_parent->right=succ->left;
            }
        }
        free(succ);
        succ=NULL;
        return root;
    }
    if(parent==NULL)//root node case with only one child, because both child case is taken care in the 2 child case
    {
        node *child = (curr->left!=NULL)?curr->left : curr->right ; 
        free(curr);
        return child;//child becomes the root node
    }
    if(curr->left==NULL || curr->right==NULL)//node with one child or no child
    {
        if(parent->left==curr)
        {
            if(curr->left==NULL)
            {
                parent->left=curr->right;
            }
            else
            {
                parent->left=curr->left;
            }
        }
        else
        {
            if(curr->left==NULL)
            {
                parent->right=curr->right;
            }
            else
            {
                parent->right=curr->left;
            }
        }
        free(curr);
        curr=NULL;
        return root;
    }
    return root;
}