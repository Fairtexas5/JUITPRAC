#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

Node* insertAtEnd(Node* head, int data) {
    Node* new_node = createNode(data);
    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return head;
}

void splitList(Node* head, Node** evenList, Node** oddList) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            *evenList = insertAtEnd(*evenList, temp->data);
        } else {
            *oddList = insertAtEnd(*oddList, temp->data);
        }
        temp = temp->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, data;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    Node* evenList = NULL;
    Node* oddList = NULL;
    splitList(head, &evenList, &oddList);
    printf("Original list: ");
    printList(head);
    printf("Even list: ");
    printList(evenList);
    printf("Odd list: ");
    printList(oddList);
    return 0;
}
