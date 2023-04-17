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

void displayFromHead(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List from head: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

void displayFromTail(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List from tail: ");
        while (tail != NULL) {
            printf("%d ", tail->data);
            tail = tail->prev;
        }
        printf("\n");
    }
}

int main() {
    struct Node* head = NULL;
    int data, n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    displayFromHead(head);
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    displayFromTail(tail);
    return 0;
}
