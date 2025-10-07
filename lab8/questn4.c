#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    char name[50];
    int age;
    int priority;
} Patient;

typedef struct {
    Patient queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Patient p) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add new patient.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->queue[q->rear] = p;
        printf("Enqueued: %s, Age: %d, Priority: %d\n", p.name, p.age, p.priority);
    }
}

Patient dequeue(Queue* q) {
    Patient p;
    if (isEmpty(q)) {
        printf("Queue is empty. No patient to dequeue.\n");
        p.age = -1; // Indicating no patient
    } else {
        p = q->queue[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Queue is now empty
        } else {
            q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        }
        printf("Dequeued: %s, Age: %d, Priority: %d\n", p.name, p.age, p.priority);
    }
    return p;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    printf("Queue elements:\n");
    while (i != q->rear) {
        printf("Name: %s, Age: %d, Priority: %d\n", q->queue[i].name, q->queue[i].age, q->queue[i].priority);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("Name: %s, Age: %d, Priority: %d\n", q->queue[q->rear].name, q->queue[q->rear].age, q->queue[q->rear].priority);
}

int main() {
    Queue q;
    initQueue(&q);

    int choice;
    Patient p;

    while (1) {
        printf("\n1. Enqueue Patient\n2. Dequeue Patient\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter patient's name: ");
                fgets(p.name, 50, stdin);
                p.name[strcspn(p.name, "\n")] = '\0';
                printf("Enter patient's age: ");
                scanf("%d", &p.age);
                printf("Enter patient's priority (1=High, 2=Medium, 3=Low): ");
                scanf("%d", &p.priority);
                enqueue(&q, p);
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
