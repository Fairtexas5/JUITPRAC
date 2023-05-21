#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure representing a queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to add an element to the rear of the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->arr[queue->rear] = data;
}

// Function to remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int data = queue->arr[queue->front];

    if (queue->front == queue->rear)
        initializeQueue(queue);
    else
        queue->front++;

    return data;
}

// Function to reverse the elements of a queue
void reverseQueue(Queue *queue) {
    if (isEmpty(queue))
        return;

    int data = dequeue(queue);
    reverseQueue(queue);
    enqueue(queue, data);
}

// Function to display the elements of the queue
void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->arr[i]);
    printf("\n");
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    // Enqueue elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    printf("Original ");
    displayQueue(&queue);

    reverseQueue(&queue);

    printf("Reversed ");
    displayQueue(&queue);

    return 0;
}
