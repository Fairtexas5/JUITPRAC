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

struct Node* selectAlternateNodes(struct Node* head) {
    struct Node* newHead = NULL;
    struct Node* temp = head;
    int count = 1;
    do {
        if (count % 2 != 0) {
            newHead = insertAtEnd(newHead, temp->data);
        }
        temp = temp->next;
        count++;
    } while (temp != head);
    return newHead;
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
    printf("Original Circular List: ");
    printList(head);
    struct Node* newHead = selectAlternateNodes(head);
    printf("New Circular List with Alternate Nodes: ");
    printList(newHead);
    return 0;
}
