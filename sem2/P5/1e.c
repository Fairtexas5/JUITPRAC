#include<stdio.h>
#include<stdlib.h>

// define a structure for linked list node
struct node {
    int data;
    struct node* next;
};

// function to insert a node at the beginning of the list
void insertNodeAtBeginning(struct node** head_ref, int new_data) {
    // create a new node and allocate memory
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    // assign the data to new node
    new_node->data = new_data;
    // assign the next pointer of new node to the head of the list
    new_node->next = (*head_ref);
    // update the head to point to the new node
    (*head_ref) = new_node;
}

// function to print the linked list
void printList(struct node* node) {
    while(node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; // initialize an empty list
    int n, num;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &num);
        insertNodeAtBeginning(&head, num);
    }
    printf("The linked list is: ");
    printList(head);
    return 0;
}
