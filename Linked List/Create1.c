#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void display() {
    struct node *ptr = head;
    printf("[head] ->");
    while(ptr != NULL) {
        printf(" %d ->",ptr->data);
        ptr = ptr->next;
    }
    printf(" [null]\n");
}

int main() {
    int n, num, i;

    printf("Enter the number of Nodes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &num);
        insert(num);
    }

    display();
    return 0;
}