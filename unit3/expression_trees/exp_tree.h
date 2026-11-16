#ifndef STACK_BIN_TREE_H
#define STACK_BIN_TREE_H
#define MAX_SIZE 20
typedef struct node_t
{
    char key;
    struct node_t *left;
    struct node_t *right;
}node;

typedef struct STACK
{
    node* key[MAX_SIZE];
    int top;
}stack;

void init_stack(stack *ptr_stack);
void deinit_stack(stack *ptr_stack);
node *getnode(char c);
int is_empty(stack *ptr_stack);
int is_full(stack *ptr_stack);
void push_operand(stack *ptr_stack, char c);
void push_operator(stack*ptr_stack, char c);
node *pop(stack *ptr_stack);
node *construct_tree( char* postfix, stack *ptr_stack);
float eval_recursive(node *root);
float evaluate_exp_tree(node *root);
float eval_postfix(char *postfix);
#endif