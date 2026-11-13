#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "exp_tree.h"
void init_stack(stack *ptr_stack)
{
    ptr_stack->top = -1;
}

void deinit_stack(stack *ptr_stack)
{
    while(!is_empty(ptr_stack))
    {
        node *temp = pop(ptr_stack);
        if(temp!=NULL)
        {
            free(temp);
        }
    }
    ptr_stack->top=-1;
}

node* getnode(char c)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->key = c;
    temp->left = temp -> right = NULL;
    return temp;
}
int is_empty(stack *ptr_stack)
{
    return ptr_stack->top==-1;
}

int is_full(stack *ptr_stack)
{
    return ptr_stack->top==MAX_SIZE-1;
}

void push_operand(stack *ptr_stack, char c)
{
    if(!is_full(ptr_stack))
    {
        ptr_stack->top= ptr_stack->top +=1;
        node* temp = getnode(c);
        ptr_stack->key[ptr_stack->top]=temp;
    }
    else
    {
        printf("STACK IS FULL\n");
    }
}

void push_operator(stack *ptr_stack, char c)
{
    node *op1 = pop(ptr_stack);
    node *op2 = pop(ptr_stack);
    node* temp = getnode(c);
    temp->right = op1;
    temp->left = op2;
    if(!is_full(ptr_stack))
    {
        ptr_stack->top= ++ptr_stack->top;
        ptr_stack->key[ptr_stack->top]=temp;
    }
    else
    {
        printf("STACK IS FULL\n");
    }
}

node *pop(stack *ptr_stack)
{
    if(!is_empty(ptr_stack))
    {
        node* top = ptr_stack->key[ptr_stack->top];
        ptr_stack->top -=1;
        return top;
    }
    printf("Stack is Empty\n");
    return NULL;
}

node *construct_tree(char* postfix, stack *ptr_stack)
{
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isalnum(postfix[i]))
        {
            push_operand(ptr_stack,postfix[i]);
        }
        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
        {
            push_operator(ptr_stack,postfix[i]);
        }
        else ;
    }
    return ptr_stack->key[ptr_stack->top];
}

float eval_recursive(node *root)//helper function
{
    if(root->left==NULL && root->right==NULL)//if leafnode return the numeric value of character
    {
        return root->key - '0' ;
    }

    float lval = eval_recursive(root->left);
    float rval = eval_recursive(root->right);

    switch(root->key)
    {
        case '+' : return lval + rval;
        case '-' : return lval - rval;
        case '*' : return lval * rval;
        case '/' : return lval / rval;
        case '^' : return pow(lval,rval);
        default:return 0;
    }
}

float evaluate_exp_tree(node* root)//wrapper function
{
    if(root==NULL) return 0;
    return eval_recursive(root);
}
float eval_postfix( char *postfix)
{
    stack stk;
    init_stack(&stk);
    node *root = construct_tree(postfix,&stk);
    return evaluate_exp_tree(root);
}