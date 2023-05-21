#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued: %d\n", data);
}

void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    
    if (queue->front == NULL)
        queue->rear = NULL;
        
    free(temp);
    
    printf("Dequeued: %d\n", data);
}

void printFront(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Front: %d\n", queue->front->data);
}

void printRear(struct Queue* queue) {
    if (queue->rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Rear: %d\n", queue->rear->data);
}

void printQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue: ");
    struct Node* current = queue->front;
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printEmptyStatus(struct Queue* queue) {
    if (queue->front == NULL)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}

void printFullStatus() {
    printf("Queue implemented using a linked list cannot be full.\n");
}

int countElements(struct Queue* queue) {
    int count = 0;
    struct Node* current = queue->front;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;
    
    do {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Front\n");
        printf("4. Print Rear\n");
        printf("5. Print Queue\n");
        printf("6. Print Empty Status\n");
        printf("7. Print Full Status\n");
        printf("8. Print Number of Elements\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter
