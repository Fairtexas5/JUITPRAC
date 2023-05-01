#include <stdio.h>
#include <stdlib.h>

// Define the structure of each node in the doubly linked list
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Function to create a new node with given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct node** headRef, int data) {
    struct node* newNode = createNode(data);

    if (*headRef == NULL) {
        // If the list is empty, make the new node the head of the list
        *headRef = newNode;
    } else {
        // Traverse the list to the end and insert the new node
        struct node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to add a new node at the beginning of the linked list
void addAtBeginning(struct node** headRef, int data) {
    struct node* newNode = createNode(data);

    if (*headRef == NULL) {
        // If the list is empty, make the new node the head of the list
        *headRef = newNode;
    } else {
        // Insert the new node at the beginning of the list
        (*headRef)->prev = newNode;
        newNode->next = *headRef;
        *headRef = newNode;
    }
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    // Take input from the user and insert at the end of the list
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // Print the original list
    printList(head);

    // Add additional numbers at the beginning of the list
    int m;
    printf("Enter the number of nodes to add at the beginning: ");
    scanf("%d", &m);
    printf("Enter the data for each node:\n");
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        addAtBeginning(&head, data);
    }

    // Print the modified list
    printList(head);

    return 0;
}
