#include <stdio.h>
#include <stdlib.h>

// Define the linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to recursively reverse the linked list
void reverseList(struct Node** head_ref) {
    struct Node* first;
    struct Node* rest;
    if (*head_ref == NULL) {
        return;
    }
    first = *head_ref;
    rest = first->next;
    if (rest == NULL) {
        return;
    }
    reverseList(&rest);
    first->next->next = first;
    first->next = NULL;
    *head_ref = rest;
}

int main() {
    // Initialize the linked list
    struct Node* head = NULL;

    // Take input from user for linked list elements
    int n, val;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&head, val);
    }

    // Print the original linked list
    printf("Original linked list: ");
    printList(head);

    // Reverse the linked list
    reverseList(&head);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    printList(head);

    return 0;
}
