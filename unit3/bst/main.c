#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
	tree t;
	init(&t);
	insert_tree_iter(&t,100);
	insert_tree_rec(&t,50);
	insert_tree_rec(&t,200);
	insert_tree_iter(&t,300);
	insert_tree_rec(&t,250);
	insert_tree_iter(&t,30);
	inorder_rec(t.root);
	printf("NULL\n");
	t.root=delete_tree(t.root,30);
	t.root=delete_tree(t.root,200);
	//t.root=delete_tree(t.root,100);
	t.root=delete_tree(t.root,300);
	//t.root=delete_tree(t.root,50);
	t.root=delete_tree(t.root,250);
	
	printf("\n");
	inorder_rec(t.root); printf("NULL\n");
    return 0;
}