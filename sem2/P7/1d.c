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

void deleteBefore(Node** headRef, Node* node) {
    Node* prevNode = node->prev;
    if (prevNode != NULL) {
        prevNode->next = node->next;
        if (node->next != NULL) {
            node->next->prev = prevNode;
        } else {
            *headRef = prevNode;
        }
        free(node);
    }
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
    printf("Enter the position before which to delete an element: ");
    scanf("%d", &pos);
    Node* current = head;
    for (int i = 1; i < pos && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position\n");
    } else {
        deleteBefore(&head, current);
        printf("Doubly linked list: ");
        printList(head);
    }
    return 0;
}
