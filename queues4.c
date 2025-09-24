#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char name[20];
    int age;
    int priority;
    struct Patient* next;
};

struct Patient* front = NULL;
struct Patient* rear = NULL;

void enqueue() {
    char name[20];
    int age, priority;
    printf("Enter Patient Name: ");
    scanf("%s", name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Priority: ");
    scanf("%d", &priority);

    struct Patient* newNode = (struct Patient*)malloc(sizeof(struct Patient));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->priority = priority;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Patient* temp = front;
    printf("Patient served: %s (Age: %d, Priority: %d)\n", temp->name, temp->age, temp->priority);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Patient* temp = front;
    printf("Patient Queue:\n");
    while (temp != NULL) {
        printf("%s (Age %d, Priority %d)\n", temp->name, temp->age, temp->priority);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Patient Queue Menu ---\n");
        printf("1. Add Patient\n2. Serve Patient\n3. Display Queue\n4. Exit\n");
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
