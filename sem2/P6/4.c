#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to separate positive and negative elements into two different linked lists
void separate(struct Node* head, struct Node** pos_head, struct Node** neg_head) {
    struct Node *curr = head, *pos_tail = NULL, *neg_tail = NULL;
    while (curr != NULL) {
        if (curr->data >= 0) {
            if (*pos_head == NULL)
                *pos_head = curr;
            else
                pos_tail->next = curr;
            pos_tail = curr;
        }
        else {
            if (*neg_head == NULL)
                *neg_head = curr;
            else
                neg_tail->next = curr;
            neg_tail = curr;
        }
        curr = curr->next;
    }
    if (pos_tail != NULL)
        pos_tail->next = NULL;
    if (neg_tail != NULL)
        neg_tail->next = NULL;
}

int main() {
    struct Node *head = NULL, *pos_head = NULL, *neg_head = NULL;
    int n, x;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&head, x);
    }
    separate(head, &pos_head, &neg_head);
    printf("Original linked list: ");
    printList(head);
    printf("Positive elements linked list: ");
    printList(pos_head);
    printf("Negative elements linked list: ");
    printList(neg_head);
    return 0;
}
