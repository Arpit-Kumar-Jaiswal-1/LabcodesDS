#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void push(struct Stack *s, char c) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(struct Stack *s) {
    if (s->top == NULL) return '\0';
    struct Node *temp = s->top;
    char c = temp->data;
    s->top = s->top->next;
    free(temp);
    return c;
}

char peek(struct Stack *s) {
    if (s->top == NULL) return '\0';
    return s->top->data;
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    s.top = NULL;
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) postfix[k++] = c;
        else if (c == '(') push(&s, c);
        else if (c == ')') {
            while (peek(&s) != '(') postfix[k++] = pop(&s);
            pop(&s);
        } else {
            while (s.top != NULL && precedence(peek(&s)) >= precedence(c))
                postfix[k++] = pop(&s);
            push(&s, c);
        }
    }
    while (s.top != NULL) postfix[k++] = pop(&s);
    postfix[k] = '\0';
}

int evalPostfix(char postfix[]) {
    struct Node *top = NULL;
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = c - '0';
            newNode->next = top;
            top = newNode;
        } else {
            int b = top->data; struct Node *temp = top; top = top->next; free(temp);
            int a = top->data; temp = top; top = top->next; free(temp);
            int res;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = res;
            newNode->next = top;
            top = newNode;
        }
    }
    int result = top->data;
    free(top);
    return result;
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression (single char operands): ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Enter numeric postfix expression to evaluate (single digit operands): ");
    scanf("%s", postfix);
    printf("Evaluation result: %d\n", evalPostfix(postfix));
    return 0;
}
