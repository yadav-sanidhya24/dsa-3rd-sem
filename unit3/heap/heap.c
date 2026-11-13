#include <stdio.h>
#include "heap.h"

void init(heap *ptr_heap)
{
    ptr_heap->key[0]=-1;
    ptr_heap->n=0;
}

static void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

static void heapify(int a[], int n, int pos)
{
    int i =pos;
    int j = 2*i;
    int val = a[i];
    int is_heap = 0;
    while (!is_heap && j<=n)
    {
        if(j+1 <= n && a[j+1]>a[j])
        {
            j+=1;
        }
        if(a[j] > a[i])
        {
            a[i]=a[j];
            i=j;
            j=2*i;
        }
        else
        {
            is_heap=1;
        }
        a[i]=val;
    }
    
}
void insert(heap *ptr_heap,int x)//bottom up upproach
{
    int pos = ++ptr_heap->n;
    ptr_heap->key[pos]=x;
    while(pos>1 && ptr_heap->key[pos] > ptr_heap->key[pos/2])
    {
        swap(&ptr_heap->key[pos],&ptr_heap->key[pos/2]);
        pos=pos/2;
    }
}

int del_max(heap *ptr_heap)
{
    int res = ptr_heap->key[1];
    ptr_heap->key[1]=ptr_heap->key[ptr_heap->n];
    heapify(ptr_heap->key,--ptr_heap->n,1);
    return res;
}