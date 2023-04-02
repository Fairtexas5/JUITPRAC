#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int key;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

// Function to insert a new node at the end of linked list
void insertEnd(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* new_node = newNode(key);

    // If the linked list is empty
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = new_node;
}

// Function to delete all nodes whose keys are negative
void Negative(struct Node** head) {
    struct Node *prev = *head, *curr = *head;

    while (curr != NULL) {
        if (curr->key < 0) {
            if (curr == *head) {
                *head = curr->next;
                free(curr);
                curr = *head;
                prev = *head;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->key);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list = NULL;
    int n, num;

    // Input the number of nodes for the linked list
    printf("Enter the number of nodes for the linked list: ");
    scanf("%d", &n);

    // Input the nodes for the linked list
    for (int i = 0; i < n; i++) {
        printf("Enter node value: ");
        scanf("%d", &num);
        insertEnd(&list, num);
    }

    // Print the original linked list
    printf("Original linked list: ");
    printList(list);

    // Delete all nodes whose keys are negative
    Negative(&list);

    // Print the updated linked list
    printf("Updated linked list: ");
    printList(list);

    return 0;
}
