#include <stdio.h>
#include <stdlib.h>

// Define the singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    int count=0;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        count++;
    }
    printf("NULL\nNumber of nodes = %d", count);
}

// Main function
int main() {
    struct Node* head = NULL;
    int loc, n, data;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }
    printf("The linked list is: ");
    printList(head);
    return 0;
}
