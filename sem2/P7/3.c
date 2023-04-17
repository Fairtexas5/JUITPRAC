#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* reverseList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* rest = reverseList(head->next);
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
    return rest;
}

int main() {
    struct Node* head = NULL;
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    printf("Original List: ");
    printList(head);
    head = reverseList(head);
    printf("Reversed List: ");
    printList(head);
    return 0;
}
