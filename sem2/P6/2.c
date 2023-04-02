#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void findCommonElements(struct Node* list1, struct Node* list2) {
    printf("Common Elements: ");
    while(list1 != NULL && list2 != NULL) {
        if(list1->data == list2->data) {
            printf("%d ", list1->data);
            list1 = list1->next;
            list2 = list2->next;
        }
        else if(list1->data < list2->data)
            list1 = list1->next;
        else
            list2 = list2->next;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, m, data;

    printf("Enter number of nodes for list 1: ");
    scanf("%d", &n);

    printf("Enter nodes for list 1: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &data);
        insertNode(&list1, data);
    }

    printf("Enter number of nodes for list 2: ");
    scanf("%d", &m);

    printf("Enter nodes for list 2: ");
    for(int i=0; i<m; i++) {
        scanf("%d", &data);
        insertNode(&list2, data);
    }

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    findCommonElements(list1, list2);

    return 0;
}
