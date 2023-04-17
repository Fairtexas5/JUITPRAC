#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        return;
    }
    Node* newNode = createNode(data);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, data, pos;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAfter(head, data);
        if (i == 0) {
            head = createNode(data);
        }
    }
    printf("Enter the position after which to insert a new element: ");
    scanf("%d", &pos);
    Node* current = head;
    for (int i = 1; i < pos && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position\n");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        insertAfter(current, data);
        printf("Doubly linked list: ");
        printList(head);
    }
    return 0;
}