#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct Queue {
    int items[MAXSIZE];
    int front, rear;
};

void createQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue* q) {
    if (q->front == 0 && q->rear == MAXSIZE - 1) {
        return 1;
    }
    if (q->front == q->rear + 1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q, int element) {
    if (isFull(q)) {
        printf("Queue is full.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAXSIZE;
        q->items[q->rear] = element;
        printf("%d enqueued to queue.\n", element);
    }
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("%d dequeued from queue.\n", q->items[q->front]);
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAXSIZE;
        }
    }
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        int i;
        printf("Queue elements: ");
        for (i = q->front; i != q->rear; i = (i + 1) % MAXSIZE) {
            printf("%d ", q->items[i]);
        }
        printf("%d", q->items[i]);
        printf("\n");
    }
}

int main() {
    struct Queue q;
    createQueue(&q);
    int choice, element;
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Queue is full\n");
        printf("5. Check if Queue is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                if (isFull(&q)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                if (isEmpty(&q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 
