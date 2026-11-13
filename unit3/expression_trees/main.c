#include <stdio.h>
#include <string.h>
#include "exp_tree.h"
int main()
{
    char postfix[100];
    printf("enter postfix expression: ");
    scanf("%[^\n]",postfix);
    printf("Answer: %.2f",eval_postfix(postfix));
    return 0;
}