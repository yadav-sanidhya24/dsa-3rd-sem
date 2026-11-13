#include <stdio.h>
#include "heap.h"

int main() {
    heap h;
    h.n = 0; // Initialize heap size to 0

    // Test insertions
    int elements[] = {20, 15, 30, 40, 10, 50, 60};
    int n = sizeof(elements) / sizeof(elements[0]);

    printf("Inserting elements into the max-heap:\n");
    for (int i = 0; i < n; i++) {
        insert(&h, elements[i]);
        printf("Inserted %d\n", elements[i]);
    }

    // Print current heap array elements (1-based index)
    printf("\nHeap array elements (1 to n_):\n");
    for (int i = 1; i <= h.n; i++) {
        printf("%d ", h.key[i]);
    }
    printf("\n\n");

    // Test delete_max operations
    printf("Deleting max elements one by one:\n");
    while (h.n > 0) {
        printf("Deleted Max: %d\n", del_max(&h));
        printf("\nHeap array elements (1 to n_):\n");
    for (int i = 1; i <= h.n; i++) {
        printf("%d ", h.key[i]);
    }
    printf("\n\n");
    }

    
    return 0;
}