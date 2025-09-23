#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertRear(struct Node **head, struct Node **tail, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void traverse(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void concatenate(struct Node **head1, struct Node **tail1, struct Node *head2, struct Node *tail2) {
    if (*head1 == NULL) {  
        *head1 = head2;
        *tail1 = tail2;
    } else if (head2 != NULL) {  
        (*tail1)->next = head2;
        head2->prev = *tail1;
        *tail1 = tail2;
    }
}

int main() {
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    int n1, n2, val;

    printf("Enter number of elements in list X1: ");
    scanf("%d", &n1);
    printf("Enter elements of X1: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertRear(&head1, &tail1, val);
    }

    printf("Enter number of elements in list X2: ");
    scanf("%d", &n2);
    printf("Enter elements of X2: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        insertRear(&head2, &tail2, val);
    }

    printf("\nList X1 before concatenation: ");
    traverse(head1);
    printf("List X2 before concatenation: ");
    traverse(head2);

    concatenate(&head1, &tail1, head2, tail2);

    printf("\nAfter concatenation, List X1: ");
    traverse(head1);

    return 0;
}
