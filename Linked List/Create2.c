#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert_node(Node** head_ref, int new_data);
void print_list(Node* head);

int main() {
    Node* list1_head = NULL;
    Node* list2_head = NULL;
    int num_nodes, data;
    
    // Create the first linked list
    printf("Enter the number of nodes for linked list 1: ");
    scanf("%d", &num_nodes);
    
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the data for node %d in linked list 1: ", i+1);
        scanf("%d", &data);
        insert_node(&list1_head, data);
    }
    
    printf("Linked list 1: ");
    print_list(list1_head);
    printf("\n");
    
    // Create the second linked list
    printf("Enter the number of nodes for linked list 2: ");
    scanf("%d", &num_nodes);
    
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the data for node %d in linked list 2: ", i+1);
        scanf("%d", &data);
        insert_node(&list2_head, data);
    }
    
    printf("Linked list 2: ");
    print_list(list2_head);
    printf("\n");
    
    return 0;
}

void insert_node(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(Node* head) {
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
}