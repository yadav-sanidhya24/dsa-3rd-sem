#include <stdio.h>
#include "tbt.h"

int main()
{
    tree t;
    init(&t);
    printf("enter number of elements: ");int n; scanf("%d",&n);
    printf("Enter elements: ");
    
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        insert(&t,x);
    }

    disp(&t);
}