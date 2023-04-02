#include <stdio.h>
#include <stdlib.h>

// Define the singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the list
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

// Function to calculate the sum of nodes after a particular location
int sumAfterNode(struct Node* head, int loc) {
    int sum = 0;
    struct Node* current = head;
    while (current != NULL && current->data != loc) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Location not found in the list\n");
        return 0;
    }
    else {
        current = current->next;
        while (current != NULL) {
            sum += current->data;
            current = current->next;
        }
    }
    return sum;
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
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }
    printf("The linked list is: ");
    printList(head);
    printf("Enter the location after which you want to calculate the sum: ");
    scanf("%d", &loc);
    int sum = sumAfterNode(head, loc);
    printf("The sum of nodes after location %d is: %d\n", loc, sum);
    return 0;
}
