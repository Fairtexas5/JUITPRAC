#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

typedef struct node {
    char data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void push(Stack* stack, char data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

char pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

char peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->top->data;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void postfixToInfix(char postfix[], char infix[]) {
    Stack stack;
    stack.top = NULL;
    int len = strlen(postfix);
    int i;
    for (i = 0; i < len; i++) {
        char c = postfix[i];
        if (isOperator(c)) {
            char op1 = pop(&stack);
            char op2 = pop(&stack);
            sprintf(infix, "(%c%c%c)", op2, c, op1);
            push(&stack, infix[0]);
        } else if (isalnum(c)) {
            infix[0] = c;
            push(&stack, c);
        } else {
            printf("Invalid Expression\n");
            exit(1);
        }
    }
    if (!isEmpty(&stack)) {
        printf("Invalid Expression\n");
        exit(1);
    }
}

int main() {
    char postfix[MAX_EXPR_LEN], infix[MAX_EXPR_LEN];
    printf("Enter a postfix expression: ");
    fgets(postfix, MAX_EXPR_LEN, stdin);
    postfix[strlen(postfix)-1] = '\0';
    postfixToInfix(postfix, infix);
    printf("Infix expression: %s\n", infix);
    return 0;
}
