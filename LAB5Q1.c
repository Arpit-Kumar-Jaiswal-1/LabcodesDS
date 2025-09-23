#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL, *tail = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertRear(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteRear() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

void insertAtPos(int data, int pos) {
    struct Node *newNode = createNode(data);
    if (pos == 1) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
        if (tail == NULL) tail = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    if (newNode->next == NULL) tail = newNode;
}

void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (pos == 1) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp == tail) tail = temp->prev;
    free(temp);
}

void insertAfterValue(int data, int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    if (temp == tail) tail = newNode;
}

void insertBeforeValue(int data, int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = newNode;
    else head = newNode;
    temp->prev = newNode;
}

void traverseForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = tail;
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, data, pos, val;

    while (1) {
        printf("\n===== Doubly Linked List Menu =====\n");
        printf("1. Insert at rear\n");
        printf("2. Delete from rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete from position\n");
        printf("5. Insert after value\n");
        printf("6. Insert before value\n");
        printf("7. Traverse forward\n");
        printf("8. Traverse backward\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 2:
                deleteRear();
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(data, pos);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Insert after which value? ");
                scanf("%d", &val);
                insertAfterValue(data, val);
                break;
            case 6:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Insert before which value? ");
                scanf("%d", &val);
                insertBeforeValue(data, val);
                break;
            case 7:
                traverseForward();
                break;
            case 8:
                traverseBackward();
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
