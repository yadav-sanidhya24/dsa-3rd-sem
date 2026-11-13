#ifndef THREADED_BINARY_TREE_H
#define THREADED_BINARY_TREE_H

typedef struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
    int lthread;
    int rthread;
}node;

typedef struct Tree
{
    node *root;
}tree;

node *getnode(int x);
void init(tree *ptr_tree);
static void freenodes(node *root);
void deinit(tree *ptr_tree);
void disp(tree *ptr_tree);
void insert(tree *ptr_tree, int x);

#endif