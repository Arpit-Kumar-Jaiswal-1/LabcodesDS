#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff, exp;
    struct PolyNode *prev, *next;
};

struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode *newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertEnd(struct PolyNode **head, struct PolyNode **tail, int coeff, int exp) {
    struct PolyNode *newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void display(struct PolyNode *head) {
    struct PolyNode *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL && temp->next->coeff >= 0) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

struct PolyNode* addPolynomials(struct PolyNode *h1, struct PolyNode *h2) {
    struct PolyNode *resHead = NULL, *resTail = NULL;
    while (h1 != NULL && h2 != NULL) {
        if (h1->exp > h2->exp) {
            insertEnd(&resHead, &resTail, h1->coeff, h1->exp);
            h1 = h1->next;
        } else if (h1->exp < h2->exp) {
            insertEnd(&resHead, &resTail, h2->coeff, h2->exp);
            h2 = h2->next;
        } else {
            int sum = h1->coeff + h2->coeff;
            if (sum != 0) insertEnd(&resHead, &resTail, sum, h1->exp);
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    while (h1 != NULL) {
        insertEnd(&resHead, &resTail, h1->coeff, h1->exp);
        h1 = h1->next;
    }
    while (h2 != NULL) {
        insertEnd(&resHead, &resTail, h2->coeff, h2->exp);
        h2 = h2->next;
    }
    return resHead;
}

int main() {
    struct PolyNode *head1 = NULL, *tail1 = NULL;
    struct PolyNode *head2 = NULL, *tail2 = NULL;
    struct PolyNode *sum = NULL;

    int n, coeff, exp;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n);
    printf("Enter terms (coeff exp) in descending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&head1, &tail1, coeff, exp);
    }

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n);
    printf("Enter terms (coeff exp) in descending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&head2, &tail2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    display(head1);
    printf("Polynomial 2: ");
    display(head2);

    sum = addPolynomials(head1, head2);

    printf("Sum: ");
    display(sum);

    return 0;
}
