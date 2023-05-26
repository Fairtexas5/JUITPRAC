#include <stdio.h>

#define MAX_SIZE 30

typedef struct Stack {
    int arr[MAX_SIZE];
    int top;
}Stack;

void push(Stack *s, int item) {
    if (s->top >= MAX_SIZE) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = item;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(Stack *s) {
    if (s->top < 0) {
        printf("Empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack s;
    s.top = -1;

    int choice, item;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                item = pop(&s);
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                item = peek(&s);
                if (item != -1) {
                    printf("Top item: %d\n", item);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
