#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void createStack(struct Stack* s) {
    s->top = NULL;
}

int isEmpty(struct Stack* s) {
    return (s->top == NULL);
}

void push(struct Stack* s, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = s->top;
    s->top = newNode;
    printf("%d pushed to stack.\n", element);
}

void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
    } else {
        struct Node* temp = s->top;
        printf("%d popped from stack.\n", temp->data);
        s->top = s->top->next;
        free(temp);
    }
}

void peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element of stack: %d\n", s->top->data);
    }
}

int isFull(struct Stack* s) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        free(newNode);
        return 1;
    } else {
        free(newNode);
        return 0;
    }
}

void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = s->top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Stack s;
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
