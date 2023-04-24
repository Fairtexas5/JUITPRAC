#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

void initStack(Stack *s) {
  s->top = -1;
}

int isStackEmpty(Stack *s) {
  return (s->top == -1);
}

int isStackFull(Stack *s) {
  return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, int data) {
  if (isStackFull(s)) {
    printf("Error: stack is full\n");
    return;
  }
  s->arr[++s->top] = data;
}

int pop(Stack *s) {
  if (isStackEmpty(s)) {
    printf("Error: stack is empty\n");
    return -1;
  }
  return s->arr[s->top--];
}

int main() {
  Stack s;
  initStack(&s);

  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  printf("%d\n", pop(&s)); // output: 30
  printf("%d\n", pop(&s)); // output: 20
  printf("%d\n", pop(&s)); // output: 10
  printf("%d\n", pop(&s)); // output: Error: stack is empty

  return 0;
}
