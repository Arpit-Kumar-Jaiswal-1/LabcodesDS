#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int doc_id;
    char doc_name[50];
} PrintJob;

typedef struct {
    PrintJob queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, PrintJob job) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add new print job.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->queue[q->rear] = job;
        printf("Enqueued: %s (Document ID: %d)\n", job.doc_name, job.doc_id);
    }
}

PrintJob dequeue(Queue *q) {
    PrintJob job;
    if (isEmpty(q)) {
        printf("Queue is empty. No print jobs to dequeue.\n");
        job.doc_id = -1;
    } else {
        job = q->queue[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        printf("Dequeued: %s (Document ID: %d) - Printing...\n", job.doc_name, job.doc_id);
    }
    return job;
}

PrintJob generateRandomJob(int id) {
    PrintJob job;
    job.doc_id = id;
    sprintf(job.doc_name, "Document_%d", id);
    return job;
}

int main() {
    Queue q;
    initQueue(&q);

    srand(time(0));

    int jobCount = 1;
    int choice;

    while (1) {
        printf("\n1. Add Print Job\n2. Print Job (Dequeue)\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            PrintJob newJob = generateRandomJob(jobCount);
            enqueue(&q, newJob);
            jobCount++;
        } else if (choice == 2) {
            dequeue(&q);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}








