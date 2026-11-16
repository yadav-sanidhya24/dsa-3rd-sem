#include <stdio.h>
#include <stdlib.h>
#include <queue_list.h>
node *getnode(int x)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->key = x;
    temp->next = NULL;
    return temp;
}
void init_queue(queue *ptr_queue)
{
    ptr_queue->front = ptr_queue->rear = NULL;
}
void deinit_queue(queue *ptr_queue)
{
    if(!is_empty(ptr_queue))
    {
        while(ptr_queue->front != NULL)
        {
            node *temp = ptr_queue->front;
            ptr_queue->front = ptr_queue->front->next;
            free(temp);
        }
        ptr_queue->rear=NULL;
    }
}
void enqueue(queue *ptr_queue, int x)
{
    node *temp = getnode(x);
    if(!is_empty(ptr_queue))
    {
        ptr_queue->rear->next = temp;
        ptr_queue->rear = temp;
        return;
    }
    ptr_queue->front = ptr_queue->rear = temp;
}

int dequeue(queue *ptr_queue)
{
    if(!is_empty(ptr_queue))
    {
          
        node *temp = ptr_queue->front;
        int res = temp->key;
        if(ptr_queue->front != ptr_queue->rear)
        {
            ptr_queue->front= ptr_queue->front->next;
            free(temp);
            return res;
        }
        ptr_queue->front= ptr_queue->rear = NULL;
        free(temp);
        return res;
    }
    else
    {
        return -1;
    }
}

int is_empty(queue *ptr_queue)
{
    return ptr_queue->front ==NULL;
}

void disp(queue *ptr_queue)
{
    node *curr = ptr_queue->front;
    while(curr!=NULL)
    {
        printf("%d->",curr->key);
        curr = curr->next;
    }
    printf("NULL\n");
}
