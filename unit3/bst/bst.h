#ifndef BST_H
#define BST_H

typedef struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
}node;

typedef struct bst
{
    node *root;
}tree;

void init(tree *ptr_t);
node *getnode(int x);
static node* insert_rec(node *root,node *temp);
void insert_tree_rec(tree *ptr_t,int x);
void insert_tree_iter(tree *ptr_t,int x);
void inorder_rec(node *root);
node *search(node*root);
node *delete_tree(node *root,int x);
#endif
/*int main()
{
	tree_t t;
	init(&t);
	insert(&t,100);
	insert(&t,50);
	insert(&t,200);
	insert(&t,300);
	insert(&t,250);
	insert(&t,30);
	inorder_rec(t.root);
	t.root=delete_tree(t.root,30);
	t.root=delete_tree(t.root,200);
	t.root=delete_tree(t.root,100);
	//t.root=delete_tree(t.root,300);
	t.root=delete_tree(t.root,50);
	//t.root=delete_tree(t.root,250);
	
	printf("\n");
	inorder_rec(t.root);
}*/