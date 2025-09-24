#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void enqueue() {
    int val;
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Circular Queue is full!\n");
        return;
    }
    printf("Enter value to enqueue: ");
    scanf("%d", &val);
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    cq[rear] = val;
}

void dequeue() {
    if (front == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", cq[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
