#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add new element.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->queue[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue(CircularQueue *q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty. No element to dequeue.\n");
        return -1;
    } else {
        value = q->queue[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Queue is now empty
        } else {
            q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        }
        printf("Dequeued: %d\n", value);
        return value;
    }
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        int i = q->front;
        printf("Queue elements: ");
        while (i != q->rear) {
            printf("%d ", q->queue[i]);
            i = (i + 1) % MAX_QUEUE_SIZE;
        }
        printf("%d\n", q->queue[q->rear]);
    }
}

int main() {
    CircularQueue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
