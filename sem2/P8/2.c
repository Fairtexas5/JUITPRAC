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

struct Node* removeDuplicates(struct Node* head) {
    struct Node *temp1, *temp2, *dup;
    temp1 = head;
    while (temp1 != NULL && temp1->next != head) {
        temp2 = temp1;
        while (temp2->next != head) {
            if (temp1->data == temp2->next->data) {
                dup = temp2->next;
                temp2->next = temp2->next->next;
                free(dup);
            } else {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
    return head;
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
    printf("Original List: ");
    printList(head);
    head = removeDuplicates(head);
    printf("List after removing duplicates: ");
    printList(head);
    return 0;
}
