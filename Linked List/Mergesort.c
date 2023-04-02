#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* merge_lists(Node* list1, Node* list2);
void insert_node(Node** head_ref, int new_data);
void sort_list(Node** head_ref);
void print_list(Node* head);

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* merged_list = NULL;
    int num_nodes, data;
    
    // Create the first linked list
    printf("Enter the number of nodes for linked list 1: ");
    scanf("%d", &num_nodes);
    
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the data for node %d in linked list 1: ", i+1);
        scanf("%d", &data);
        insert_node(&list1, data);
    }
    // Sort list1
    sort_list(&list1);
    printf("Linked list 1: ");
    print_list(list1);
    printf("\n");
    
    // Create the second linked list
    printf("Enter the number of nodes for linked list 2: ");
    scanf("%d", &num_nodes);
    
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the data for node %d in linked list 2: ", i+1);
        scanf("%d", &data);
        insert_node(&list2, data);
    }
    // Sort list2
    sort_list(&list2);
    printf("Linked list 2: ");
    print_list(list2);
    printf("\n");
    
    // Merge the two sorted lists
    merged_list = merge_lists(list1, list2);
    
    // Print the merged and sorted list
    while (merged_list != NULL) {
        printf("%d ", merged_list->data);
        merged_list = merged_list->next;
    }
    
    return 0;
}

Node* merge_lists(Node* list1, Node* list2) {
    Node* merged_list = NULL;
    Node** last_ptr_ref = &merged_list;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            *last_ptr_ref = list1;
            list1 = list1->next;
        }
        else {
            *last_ptr_ref = list2;
            list2 = list2->next;
        }
        
        last_ptr_ref = &((*last_ptr_ref)->next);
    }
    
    *last_ptr_ref = (list1 == NULL) ? list2 : list1;
    
    return merged_list;
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

void sort_list(Node** head_ref) {
    Node *i, *j;
    int temp;
    
    for (i = *head_ref; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}