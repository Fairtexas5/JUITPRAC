#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a Node after a particular location
void insertAfterLocation(struct Node *head, int loc, int num) {
    struct Node *temp = head;
    int i;
    // Traverse to the desired location
    for(i = 1; i < loc && temp != NULL; i++) {
        temp = temp->next;
    }
    // Check if the location is valid
    if(temp == NULL) {
        printf("Invalid location\n");
        return;
    }
    // Create a new Node
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *temp = head;
    printf("List: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int n, i, num, loc;
    // Create the head Node
    struct Node *head = NULL;
    head = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter element 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    // Insert the remaining Nodes
    for(i = 2; i <= n; i++) {
        struct Node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter element %d: ", i);
        scanf("%d", &num);
        newNode->data = num;
        newNode->next = NULL;
        temp->next = newNode;
    }
    // Display the original list
    printf("Original ");
    displayList(head);
    // Take input for location and number to be inserted
    printf("Enter the location to insert after: ");
    scanf("%d", &loc);
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    // Call the insert function
    insertAfterLocation(head, loc, num);
    // Display the updated list
    printf("Updated ");
    displayList(head);
    return 0;
}
