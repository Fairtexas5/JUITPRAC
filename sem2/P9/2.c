#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}NODE;

typedef struct stack {
    struct node* top;
}Stack;

void createStack(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack* s) {
    return (s->top == NULL);
}

void push(Stack* s, int element) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = element;
    new_node->next = s->top;
    s->top = new_node;
    printf("%d pushed to stack.\n", element);
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
    } else {
        NODE* temp = s->top;
        printf("%d popped from stack.\n", temp->data);
        s->top = s->top->next;
        free(temp);
    }
}

void peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element of stack: %d\n", s->top->data);
    }
}

int isFull(Stack* s) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (new_node == NULL) {
        free(new_node);
        return 1;
    } else {
        free(new_node);
        return 0;
    }
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        NODE* temp = s->top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Stack s;
    createStack(&s);
    int choice, element;
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Stack is full\n");
        printf("6. Check if Stack is empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(&s, element);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                if (isFull(&s)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 6:
                if (isEmpty(&s)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}
