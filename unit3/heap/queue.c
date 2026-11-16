#include <stdio.h>
#include "queue.h"

void init_queue(queue *ptr_q)
{
    ptr_q->h.n=0;
    ptr_q->h.key[0]=-1;
}
void enqueue(queue *ptr_q, int x)
{
    insert(&ptr_q->h,x);
}
int dequeue(queue *ptr_q)
{
    return del_max(&ptr_q->h);
}   