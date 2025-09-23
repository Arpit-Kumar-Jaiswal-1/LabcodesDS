#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX-1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int isPalindrome(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }
    for (int i = 0; i < n; i++) {
        if (pop() != str[i]) return 0;
    }
    return 1;
}

int checkParentheses(char expr[]) {
    top = -1;
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) return 0;
            char open = pop();
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) return 0;
        }
    }
    return top == -1;
}

int main() {
    char str[MAX], expr[MAX];
    printf("Enter a string to check palindrome: ");
    scanf("%s", str);
    if (isPalindrome(str)) printf("Palindrome\n");
    else printf("Not a palindrome\n");

    printf("Enter an expression to check parentheses: ");
    scanf("%s", expr);
    if (checkParentheses(expr)) printf("Parentheses are balanced\n");
    else printf("Parentheses are not balanced\n");

    return 0;
}
