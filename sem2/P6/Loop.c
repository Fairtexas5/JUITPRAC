#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertNode(struct Node** headRef, int data) {
    struct Node* node = createNode(data);
    if (*headRef == NULL) {
        *headRef = node;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

int detectLoop(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0;
    }
    struct Node* slow = head;
    struct Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return 1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data for each node: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }
    printf("The linked list is: ");
    printList(head);
    if (detectLoop(head)) {
        printf("\nThe linked list contains a loop.");
    } else {
        printf("\nThe linked list does not contain a loop.");
    }
    return 0;
}
