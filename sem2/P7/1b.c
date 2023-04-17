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

void insertBefore(Node** headRef, Node* nextNode, int data) {
    Node* newNode = createNode(data);
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;
    if (nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    } else {
        *headRef = newNode;
    }
    nextNode->prev = newNode;
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
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->prev = head;
            head->next = newNode;
            head = newNode;
        }
    }
    printf("Enter the position before which to insert a new element: ");
    scanf("%d", &pos);
    Node* current = head;
    for (int i = 1; i < pos && current != NULL; i++) {
        current = current->prev;
    }
    if (current == NULL) {
        printf("Invalid position\n");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        insertBefore(&head, current, data);
        printf("Doubly linked list: ");
        printList(head);
    }
    return 0;
}
