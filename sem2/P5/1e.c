#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* current = NULL;
    int sum = 0;

    // create linked list
    for (int i = 1; i <= 10; i++) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }

    // calculate sum of numbers at the beginning of the linked list
    current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }

    // print sum
    printf("Sum of numbers at the beginning of the linked list: %d\n", sum);

    return 0;
}
