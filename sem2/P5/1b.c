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

void deleteNode(struct Node** head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    // If head Node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        free(temp);             // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous Node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list 
    if (temp == NULL) return;

    // Unlink the Node from linked list
    prev->next = temp->next;

    // Free memory
    free(temp);
}



// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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
    printf("The linked list is: ");
    printList(head);
    printf("Enter the data to be deleted: ");
    scanf("%d", &loc);
    deleteNode(&head, loc);
    printf("After deletion:\n");
    printList(head);

    return 0;
}
 