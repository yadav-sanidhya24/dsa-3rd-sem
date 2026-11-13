#include <stdio.h>
#include "heap.h"
#include "queue.h"

int main() {
    queue pq;
    pq.h.n = 0; // Initialize queue/heap size to 0

    // Test Enqueue (Priority Queue implementation using Heap)
    int priorities[] = {20, 50, 10, 40, 30, 60};
    int n = sizeof(priorities) / sizeof(priorities[0]);

    printf("Enqueuing elements into the Priority Queue:\n");
    for (int i = 0; i < n; i++) {
        enqueue(&pq, priorities[i]);
        printf("Enqueued: %d\n", priorities[i]);
    }

    printf("\nDequeuing elements in order of highest priority (Max-Heap):\n");
    while (pq.h.n > 0) {
        printf("Dequeued: %d\n", dequeue(&pq));
    }

    return 0;
}

