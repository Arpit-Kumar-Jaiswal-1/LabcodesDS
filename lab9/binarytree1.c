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

void inorderIterative(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;
    while (curr || top != -1) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorderIterative(struct Node* root) {
    if (!root) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

void postorderIterative(struct Node* root) {
    if (!root) return;
    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

void printParent(struct Node* root, int val) {
    if (!root) return;
    if ((root->left && root->left->data == val) || (root->right && root->right->data == val)) {
        printf("Parent of %d is %d\n", val, root->data);
        return;
    }
    printParent(root->left, val);
    printParent(root->right, val);
}

int height(struct Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int printAncestors(struct Node* root, int val) {
    if (!root) return 0;
    if (root->data == val) return 1;
    if (printAncestors(root->left, val) || printAncestors(root->right, val)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int countLeaves(struct Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder: "); inorderIterative(root); printf("\n");
    printf("Preorder: "); preorderIterative(root); printf("\n");
    printf("Postorder: "); postorderIterative(root); printf("\n");
    printParent(root, 5);
    printf("Height: %d\n", height(root));
    printf("Ancestors of 5: "); printAncestors(root, 5); printf("\n");
    printf("Leaf count: %d\n", countLeaves(root));
    return 0;
}
