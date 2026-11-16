#ifndef BST_ARR_H
#define BST_ARR_H
#define MAX_SIZE 200
typedef struct Node
{
    int key;
    int left;
    int right;
}node;

typedef struct Tree
{
    node elem[MAX_SIZE];
    int root;
    int count;
}tree;

void init(tree *ptr_tree);
void disp(tree *ptr_tree);
void insert(tree *ptr_tree, int x);
int number_of_nodes(tree *ptr_tree);
int number_of_leaves(tree *ptr_tree);

#endif