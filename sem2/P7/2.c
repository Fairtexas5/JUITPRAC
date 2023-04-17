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

void splitList(struct Node* head, struct Node** evenList, struct Node** oddList) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            *evenList = insertAtEnd(*evenList, temp->data);
        } else {
            *oddList = insertAtEnd(*oddList, temp->data);
        }
        temp = temp->next;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    struct Node* evenList = NULL;
    struct Node* oddList = NULL;
    splitList(head, &evenList, &oddList);
    printf("Original list: ");
    displayList(head);
    printf("Even list: ");
    displayList(evenList);
    printf("Odd list: ");
    displayList(oddList);
    return 0;
}
