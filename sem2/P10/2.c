#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int top;
    int items[100];
} Stack;

void push(Stack* stack, int item) {
    if (stack->top == 100 - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack->items[stack->top--];
}

int Eval_Post(char* Exp) {
    Stack stack;
    stack.top = -1;

    int length = strlen(Exp);
    int i;

    for (i = 0; i < length; i++) {
        if (Exp[i] >= '0' && Exp[i] <= '9'){
            int num = 0;
            while (Exp[i] >= '0' && Exp[i] <= '9') {
                num = num * 10 + (Exp[i] - '0');
                i++;
            }
            push(&stack, num);
        }
         else if (Exp[i] == ' ') {
            continue;
        }
        else if (Exp[i] == '(') {
            push(&stack, Exp[i]);
        }
        else if (Exp[i] == ')') {
            while (stack.items[stack.top]!= '(') {
                int num = pop(&stack);
                push(&stack, num);
            }
            pop(&stack);
        }
        else if (Exp[i] == '+' || Exp[i] == '-' || Exp[i] == '*' || Exp[i] == '/') {
            int num2 = pop(&stack);
            int num1 = pop(&stack);
            if (Exp[i] == '+') {
                push(&stack, num1 + num2);
            }
            else if (Exp[i] == '-') {
                push(&stack, num1 - num2);
            }
            else if (Exp[i] == '*') {
                push(&stack, num1 * num2);
            }
            else if (Exp[i] == '/') {
                push(&stack, num1 / num2);
            }
            else {
                printf("Error\n");
                exit(0);
            }
        }
        else {
            printf("Error\n");
            exit(0);
        }

    }


    return pop(&stack);
}

int main() {
    char Exp[100];
    int result;

        printf("Enter a postfix Exp : ");
        fgets(Exp, sizeof(Exp), stdin);
        Exp[strcspn(Exp, "\n")] = '\0';

        result = Eval_Post(Exp);
        printf("Result: %d", result);

    return 0;
}