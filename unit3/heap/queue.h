#ifndef QUEUE_H
#define QUEUE_H
#include "heap.h"

typedef struct Queue
{
    heap h;
}queue;

void init_queue(queue *ptr_q);
void enqueue(queue *ptr_q, int x);
int dequeue(queue *ptr_q);
#endif