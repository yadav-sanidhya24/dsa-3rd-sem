#ifndef BAL_TREE_H
#define BAL_TREE_H

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int *height;
}node;

typedef struct Tree
{
    node *root;
}tree;

void init(tree *ptr_tree);
void insert(tree *ptr_tree, int x);
void delete_node(tree *ptr_tree, int x);
#endif