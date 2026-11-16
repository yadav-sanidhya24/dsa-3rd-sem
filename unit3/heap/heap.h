#ifndef HEAP_H
#define HEAP_H
#define MAX_SIZE 100
typedef struct Heap
{
    int key[MAX_SIZE];
    int n;
}heap;

void init(heap *ptr_heap);
void insert(heap *ptr_heap,int x);
int del_max(heap *ptr_heap);
#endif