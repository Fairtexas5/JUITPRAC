#include <stdio.h>
#include <stdlib.h>

// Define the singly linked list Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a Node at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


// Main function
int main() {
    struct Node* head = NULL;
    int loc, n, data;
    printf("Enter the number of Nodes in the linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for Node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    return 0;
}
