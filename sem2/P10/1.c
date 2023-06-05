#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPrefix(char *infix, char *prefix) {
    struct Stack stack;
    initialize(&stack);
    int i, j = 0;
    int len = strlen(infix);

    // Reverse the infix expression
    for (i = len - 1; i >= 0; i--) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
        prefix[j++] = infix[i];
    }
    prefix[j] = '\0';

    for (i = 0; i < len; i++) {
        if (isOperand(prefix[i])) {
            prefix[j++] = prefix[i];
        } else if (prefix[i] == '(') {
            push(&stack, prefix[i]);
        } else if (prefix[i] == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                prefix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(&stack);  // Discard the '(' from the stack
            }
        } else {
            while (!isEmpty(&stack) && precedence(prefix[i]) <= precedence(stack.items[stack.top])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, prefix[i]);
        }
    }

    while (!isEmpty(&stack)) {
        if (stack.items[stack.top] == '(') {
            printf("Invalid Expression\n");
            return;
        }
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    len = strlen(prefix);
    for (i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an Infix Expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0';  // Remove newline character

    infixToPrefix(infix, prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
