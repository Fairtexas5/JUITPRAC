#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void displayList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void addNumbersAfterLocation(Node** head, int loc) {
    Node* curr = *head;
    int count = 0;
    while (curr != NULL && count != loc) {
        curr = curr->next;
        count++;
    }
    if (curr == NULL) {
        printf("Invalid location.\n");
        return;
    }
    int sum = 0;
    while (curr != NULL) {
        sum += curr->data;
        curr = curr->next;
    }
    Node* newNode = createNode(sum);
    newNode->next = curr;
    curr = *head;
    count = 0;
    while (curr != NULL && count != loc) {
        curr = curr->next;
        count++;
    }
    if (count == 0) {
        *head = newNode;
    } else {
        Node* prev = *head;
        while (prev->next != curr) {
            prev = prev->next;
        }
        prev->next = newNode;
    }
    printf("Numbers added successfully.\n");
}

int main() {
    Node* head = NULL;
    int n, loc, data;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    displayList(head);
    printf("Enter the location after which you want to add the numbers: ");
    scanf("%d", &loc);
    addNumbersAfterLocation(&head, loc);
    displayList(head);
    return 0;
}


