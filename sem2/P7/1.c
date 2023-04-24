#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insertAtEnd(Node** head, int data) {
    Node* new_node = createNode(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

 void insertAfter(Node* prev_node, int data) {
    if (prev_node == NULL) {
        return;
    }
    Node* new_node = createNode(data);
    new_node->prev = prev_node;
    new_node->next = prev_node->next;
    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;
}

void deleteBefore(Node** headRef, Node* node) {
    Node* prev_node = node->prev;
    if (prev_node != NULL) {
        prev_node->next = node->next;
        if (node->next != NULL) {
            node->next->prev = prev_node;
        } else {
            *headRef = prev_node;
        }
        free(node);
    }
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
    Node* head = NULL;
    int n, data, posins, posdel;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("Doubly linked list: ");
    printList(head);


    printf("\nEnter the position after which to insert a new element: ");
    scanf("%d", &posins);
    Node* currentins = head;
    for (int i = 1; i < posins && currentins != NULL; i++) {
        currentins = currentins->next;
    }
    if (currentins == NULL) {
        printf("Invalid position\n");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        insertAfter(currentins, data);
        printf("Doubly linked list: ");
        printList(head);
    }

    printf("\nEnter the position before which to delete an element: ");
    scanf("%d", &posdel);
    Node* currentdel = head;
    for (int i = 1; i < posdel && currentdel != NULL; i++) {
        currentdel = currentdel->next;
    }
    if (currentdel == NULL) {
        printf("Invalid position\n");
    } else {
        deleteBefore(&head, currentdel);
        printf("Doubly linked list: ");
        printList(head);
    }
    
    printf("\n");
    displayFromHead(head);
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    displayFromTail(tail);
    return 0;
}
