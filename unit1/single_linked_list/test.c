#include <stdio.h>
#include <stdlib.h>

/* 
 * ============================================================================
 * STRUCT DEFINITION
 * ============================================================================
 * A node contains two parts:
 * 1. info: Stores the actual data element.
 * 2. next: Pointer storing the memory address of the next node in the list.
 */
typedef struct node {
    int info;
    struct node *next;
} Node;


/* 
 * ============================================================================
 * MEMORY MANAGEMENT PRIMITIVE OPERATIONS
 * ============================================================================
 */

/* 
 * Operation: getnode()
 * Purpose: Allocates memory dynamically for a new node.
 * Returns: A pointer to the newly allocated node.
 */
Node* getnode(void) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Error: Dynamic memory allocation failed!\n");
        exit(1);
    }
    return p;
}

/* 
 * Operation: freenode(p)
 * Purpose: Releases/destroys the memory allocated for the node pointed to by p.
 */
void freenode(Node *p) {
    if (p != NULL) {
        free(p);
    }
}


/* 
 * ============================================================================
 * CORE LINKED LIST OPERATIONS
 * ============================================================================
 */

/* 
 * Operation: Initializing an Empty List
 * Sets the external list pointer to NULL to indicate zero nodes.
 */
void init_list(Node **list) {
    *list = NULL;
}

/* 
 * Operation: Insert / Add Node to Front of List
 * Sequence shown in the text:
 *   p = getnode();
 *   info(p) = x;
 *   next(p) = list;
 *   list = p;
 */
void insert_front(Node **list, int value) {
    // 1. Obtain an empty node and assign its address to auxiliary variable p
    Node *p = getnode();

    // 2. Set the info field of node(p) to the input value
    p->info = value;

    // 3. Set the next field of node(p) to point to the current first node
    p->next = *list;

    // 4. Update the external list pointer to point to the new node p
    *list = p;

    printf("Inserted %d at the front of the list.\n", value);
}

/* 
 * Operation: Remove / Delete Node from Front of List
 * Sequence shown in the text:
 *   p = list;
 *   list = next(p);
 *   x = info(p);
 *   freenode(p);
 */
int remove_front(Node **list) {
    // Check if list is empty
    if (*list == NULL) {
        printf("List is empty! Cannot perform remove operation.\n");
        return -1;
    }

    // 1. Store pointer to current head node in auxiliary variable p
    Node *p = *list;

    // 2. Advance external list pointer to point to the next node
    *list = p->next;

    // 3. Extract the info value from node(p) into variable x
    int x = p->info;

    // 4. Free the unlinked node to return its memory area
    freenode(p);

    printf("Removed %d from the front of the list.\n", x);
    return x;
}

/* 
 * Utility Operation: Display / Traverse List
 * Traverses from head through nodes until next pointer reaches NULL.
 */
void display_list(Node *list) {
    if (list == NULL) {
        printf("List is empty: [ NULL ]\n");
        return;
    }

    printf("Current List: ");
    Node *curr = list;
    while (curr != NULL) {
        printf("[ %d | next ] -> ", curr->info);
        curr = curr->next;
    }
    printf("NULL\n");
}


/* 
 * ============================================================================
 * DRIVER PROGRAM (CLIENT CODE TO TEST ALL OPERATIONS)
 * ============================================================================
 */
int main(void) {
    // Declare head pointer
    Node *list;

    // 1. Initialize empty list (list = null)
    init_list(&list);
    display_list(list);
    printf("\n");

    // 2. Add elements to front of the list
    insert_front(&list, 8);
    insert_front(&list, 3);
    insert_front(&list, 5);
    insert_front(&list, 6);
    display_list(list);
    printf("\n");

    // 3. Remove elements from front of the list
    remove_front(&list);
    display_list(list);
    printf("\n");

    remove_front(&list);
    display_list(list);
    printf("\n");

    // 4. Clean up remaining nodes
    remove_front(&list);
    remove_front(&list);
    display_list(list);

    return 0;
}