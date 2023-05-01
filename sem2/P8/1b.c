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

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    }
    else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.");
    }
    else {
        Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;
    if (*head == NULL) {
        printf("List is empty.");
        return;
    }
    else {
        while (current->data != data) {
            if (current->next == *head) {
                printf("%d not found in the list.", data);
                return;
            }
            prev = current;
            current = current->next;
        }
        if (current->next == *head && prev == NULL) {
            *head = NULL;
            free(current);
            return;
        }
        if (current == *head) {
            prev = *head;
            while (prev->next != *head) {
                prev = prev->next;
            }
            *head = current->next;
            prev->next = *head;
            free(current);
        }
        else if (current->next == *head) {
            prev->next = *head;
            free(current);
        }
        else {
            prev->next = current->next;
            free(current);
        }
    }
}

int main() {
    Node* head = NULL;
    int choice, data;
    do {
        printf("\n1. Insert Node");
        printf("\n2. Delete Node");
        printf("\n3. Display List");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter data to insert: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            printf("\nEnter data to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 3:
            printf("\nThe List is: ");
            displayList(head);
            break;
        case 4:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice.");
        }
    } while (choice != 4);
    return 0;
}
