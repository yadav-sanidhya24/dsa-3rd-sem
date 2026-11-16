#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

typedef struct Node
{
    int key;
    struct Node *next;
}node;
typedef struct Queue
{
    node *front;
    node *rear;
}queue;

void init_queue(queue *ptr_queue);
void deinit_queue(queue *ptr_queue);
node *getnode(int x);
void enqueue(queue *ptr_queue, int x);
int dequeue(queue *ptr_queue);
int is_empty(queue *ptr_queue);
void disp(queue *ptr_queue);
#endif