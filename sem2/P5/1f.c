#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void print_list(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    int num, count;
    printf("How many numbers would you like to append?\n");
    scanf("%d", &count);
    printf("Enter the numbers:\n");
    for (int i = 0; i < count; i++) {
        scanf("%d", &num);
        append(&head, num);
    }
    printf("The linked list is:\n");
    print_list(head);
    return 0;
}
