#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL, *last = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(int data) {
    struct Node *newNode = createNode(data);
    if (first == NULL) {
        first = last = newNode;
        last->next = first;
    } else {
        last->next = newNode;
        newNode->next = first;
        last = newNode;
    }
    printf("Inserted %d at end.\n", data);
}

void deleteBegin() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (first == last) {
        printf("Deleted %d from beginning.\n", first->data);
        free(first);
        first = last = NULL;
    } else {
        struct Node *temp = first;
        printf("Deleted %d from beginning.\n", temp->data);
        first = first->next;
        last->next = first;
        free(temp);
    }
}

void deleteEnd() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (first == last) {
        printf("Deleted %d from end.\n", first->data);
        free(first);
        first = last = NULL;
    } else {
        struct Node *temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }
        printf("Deleted %d from end.\n", last->data);
        free(last);
        last = temp;
        last->next = first;
    }
}

void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = first;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\n=== Circular Singly Linked List Menu ===\n");
        printf("1. Insert at end\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                display();
                break;
            case 2:
                deleteBegin();
                display();
                break;
            case 3:
                deleteEnd();
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
