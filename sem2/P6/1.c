#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert node at the end of a linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to combine two linked lists in alternating order
struct Node* combineLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        insertAtEnd(&result, temp1->data);
        insertAtEnd(&result, temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL) {
        insertAtEnd(&result, temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        insertAtEnd(&result, temp2->data);
        temp2 = temp2->next;
    }
    return result;
}

int main() {
    struct Node* A = NULL;
    struct Node* B = NULL;

    // Insert nodes in linked list A
    insertAtEnd(&A, 1);
    insertAtEnd(&A, 2);
    insertAtEnd(&A, 3);
    insertAtEnd(&A, 4);
    insertAtEnd(&A, 5);
    insertAtEnd(&A, 6);

    // Insert nodes in linked list B
    insertAtEnd(&B, 7);
    insertAtEnd(&B, 8);
    insertAtEnd(&B, 9);
    insertAtEnd(&B, 10);
    insertAtEnd(&B, 11);
    insertAtEnd(&B, 12);

    // Combine the linked lists A and B in alternating order to create C
    struct Node* C = combineLists(A, B);

    // Print the final linked list C
    printf("Combined linked list C: ");
    printList(C);
    return 0;
}
