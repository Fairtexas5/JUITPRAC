#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

struct Node* addAfter(struct Node* head, int loc, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int i;
    for (i = 1; i < loc && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp == head) {
        newNode->next = head->next;
        head->next = newNode;
    } else if (temp->next == head) {
        temp->next = newNode;
        newNode->next = head;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    int n, data, i, loc;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    printf("Original List: ");
    printList(head);
    printf("Enter the location after which you want to add a number: ");
    scanf("%d", &loc);
    printf("Enter the number you want to add: ");
    scanf("%d", &data);
    head = addAfter(head, loc, data);
    printf("List after adding %d after location %d: ", data, loc);
    printList(head);
    return 0;
}
