#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n;
    printf("Enter the number of linked lists to create: ");
    scanf("%d", &n);

    struct node* heads[n]; // array of pointers to heads of linked lists

    // create n linked lists
    for (int i = 0; i < n; i++) {
        int num_nodes;
        printf("Enter the number of nodes for linked list %d: ", i+1);
        scanf("%d", &num_nodes);

        struct node* head = NULL; // head of the linked list

        // create nodes and add to linked list
        for (int j = 0; j < num_nodes; j++) {
            int val;
            printf("Enter the value of node %d: ", j+1);
            scanf("%d", &val);

            // create new node
            struct node* new_node = (struct node*) malloc(sizeof(struct node));
            new_node->data = val;
            new_node->next = NULL;

            // add new node to linked list
            if (head == NULL) { // first node in list
                head = new_node;
            } else { // add to end of list
                struct node* curr_node = head;
                while (curr_node->next != NULL) {
                    curr_node = curr_node->next;
                }
                curr_node->next = new_node;
            }
        }

        heads[i] = head; // add head of linked list to array
    }

    // print each linked list
    for (int i = 0; i < n; i++) {
        printf("Linked List %d: ", i+1);
        struct node* curr_node = heads[i];
        while (curr_node != NULL) {
            printf("%d -> ", curr_node->data);
            curr_node = curr_node->next;
        }
        printf("NULL\n");
    }

    return 0;
}