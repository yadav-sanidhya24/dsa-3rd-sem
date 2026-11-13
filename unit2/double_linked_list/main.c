#include <stdio.h>
#include "dlist.h"

int main()
{
    printf("--- 1. INITIALIZATION ---\n");
    node *head = init_list();
    display_forward(head);

    printf("\n--- 2. INSERTIONS ---\n");
    head = insert_front(head, 20);      // [20]
    head = insert_front(head, 10);      // [10, 20]
    head = insert_end(head, 40);        // [10, 20, 40]
    
    // Test insert_after
    head = insert_after(head, 20, 30);  // Middle insertion: [10, 20, 30, 40]
    head = insert_after(head, 40, 50);  // Tail insertion: [10, 20, 30, 40, 50]
    head = insert_after(head, 99, 100); // Not found case

    printf("\nExpected: 10 -> 20 -> 30 -> 40 -> 50 -> NULL\n");
    printf("Forward:  ");
    display_forward(head);
    
    printf("Backward: ");
    display_backward(head); // Crucial test to ensure prev pointers are correct

    printf("\n--- 3. DELETIONS ---\n");
    head = del_front(head);             // Removes 10
    printf("After del_front:   ");
    display_forward(head);

    head = del_end(head);               // Removes 50
    printf("After del_end:     ");
    display_forward(head);

    head = del_val(head, 30);           // Removes middle (30)
    printf("After del_val(30): ");
    display_forward(head);

    head = del_val(head, 20);           // Removes head (20)
    printf("After del_val(20): ");
    display_forward(head);
    
    head = del_val(head, 99);           // Not found case

    printf("\nFinal structure check (Backward):\n");
    display_backward(head);             // Should just be "40 -> NULL"

    printf("\n--- 4. CLEANUP ---\n");
    head = del_list(head);              // Free remaining nodes
    printf("After del_list:    ");
    display_forward(head);

    return 0;
}