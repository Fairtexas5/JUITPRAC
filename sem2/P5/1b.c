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




/*#include <stdio.h>
#include <stdlib.h>

// Define the singly linked list Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a Node at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(struct Node** head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    // If head Node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        free(temp);             // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous Node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the Node from linked list
    prev->next = temp->next;

    // Free memory
    free(temp);
}



// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int loc, n, data;
    printf("Enter the number of Nodes in the linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for Node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }
    printf("The linked list is: ");
    printList(head);
    printf("Enter the data to be deleted: ");
    scanf("%d", &loc);
    deleteNode(&head, loc);
    printf("After deletion:\n");
    printList(head);

    return 0;
}
*/