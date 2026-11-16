#include <stdio.h>
#include "bst_arr.h"

void init(tree *ptr_tree)
{
    ptr_tree->count=0;
    ptr_tree->root=-1;
}

void static disp_recursive(node elem[], int temp)
{
    if(temp!=-1)
    {
        disp_recursive(elem,elem[temp].left);
        printf("%d ",elem[temp].key);
        disp_recursive(elem,elem[temp].right);
    }
}

void disp(tree *ptr_tree)
{
    printf("Tree: ");
    disp_recursive(ptr_tree->elem,ptr_tree->root);
    printf("\n");
}

void insert(tree *ptr_tree, int x)
{
    if(ptr_tree->count==MAX_SIZE)
    {
        printf("full\n");
        return;
    }

    int temp = ptr_tree->count++;
    ptr_tree->elem[temp].left= -1;
    ptr_tree->elem[temp].right= -1;

    ptr_tree->root= insert_recursive(ptr_tree->elem, ptr_tree->root, temp);
}

static int insert_recursive(node elem[], int root, int temp)
{
    if(root == -1)
    {
        root = temp;
    }
    else if(elem[root].key > elem[temp].key)
    {
        elem[root].left = insert_recursive(elem, elem[root].left,temp);
    }
    else
    {
        elem[root].right = insert_recursive(elem, elem[root].right,temp);
    }
    return root;
}

int number_of_nodes(tree *ptr_tree)
{
    return ptr_tree->count;
}

int number_of_leaves(tree *ptr_tree)
{
    int count_leaves=0;
    for(int i=0;i<ptr_tree->count;i++)
    {
        if(ptr_tree->elem[i].left ==-1 && ptr_tree->elem[i].right == -1)
        {
            count_leaves++;
        }
    }
    return count_leaves;
}