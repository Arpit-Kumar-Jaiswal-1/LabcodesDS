#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct PrintJob {
    int id;
    char name[20];
};

struct PrintJob queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    struct PrintJob job;
    printf("Enter Document ID: ");
    scanf("%d", &job.id);
    printf("Enter Document Name: ");
    scanf("%s", job.name);
    if (front == -1) front = 0;
    queue[++rear] = job;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Printing Document ID: %d, Name: %s\n", queue[front].id, queue[front].name);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Current Print Queue:\n");
    for (int i = front; i <= rear; i++)
        printf("[%d] %s  ", queue[i].id, queue[i].name);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add Print Job\n2. Print Next Job\n3. Show Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
