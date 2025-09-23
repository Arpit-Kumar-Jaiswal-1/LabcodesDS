#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void traverse() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertBefore(int data, int beforeData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        printf("List is empty. Cannot insert.\n");
        free(newNode);
        return;
    }

    if (head->data == beforeData) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != beforeData) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element %d not found.\n", beforeData);
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(int data, int afterData) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterData) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", afterData);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    if (head->data == key) {
        head = head->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void reverseList() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void sortList() {
    if (head == NULL || head->next == NULL)
        return;

    struct Node* i, *j;
    int tempData;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                tempData = j->data;
                j->data = j->next->data;
                j->next->data = tempData;
            }
        }
    }
}

void deleteAlternate() {
    if (head == NULL) return;

    struct Node* curr = head;
    struct Node* temp;

    while (curr != NULL && curr->next != NULL) {
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
        curr = curr->next;
    }
}

void sortedInsert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL || head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


int main() {
    int choice, data, ref;

    while (1) {
        printf("\n===== Singly Linked List Menu =====\n");
        printf("1. Insert before an element\n");
        printf("2. Insert after an element\n");
        printf("3. Delete an element\n");
        printf("4. Traverse and display\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete alternate nodes\n");
        printf("8. Insert into sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Insert before which element? ");
                scanf("%d", &ref);
                insertBefore(data, ref);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Insert after which element? ");
                scanf("%d", &ref);
                insertAfter(data, ref);
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 4:
                traverse();
                break;

            case 5:
                reverseList();
                printf("List reversed successfully.\n");
                break;

            case 6:
                sortList();
                printf("List sorted in ascending order.\n");
                break;

            case 7:
                deleteAlternate();
                printf("Alternate nodes deleted.\n");
                break;

            case 8:
                printf("Enter data to insert (sorted list): ");
                scanf("%d", &data);
                sortedInsert(data);
                break;

            case 9:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
