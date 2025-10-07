#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* createTree() {
    int x;
    scanf("%d", &x);
    if (x == -1) return NULL;
    struct Node* temp = newNode(x);
    temp->left = createTree();
    temp->right = createTree();
    return temp;
}

void printLevelOrder(struct Node* root) {
    if (!root) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* node = queue[front++];
        printf("%d ", node->data);
        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
}

int main() {
    struct Node* root = createTree();
    printLevelOrder(root);
    return 0;
}
