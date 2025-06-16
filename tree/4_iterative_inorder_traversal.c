#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { 
    int data; 
    struct TreeNode *left, *right; 
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p) {
    if (top < SIZE - 1) {
        stack[++top] = p;
    } else {
        printf("Stack overflow!\n");
    }
}

TreeNode *pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow!\n");
        return NULL;
    }
}

void inorder_iter(TreeNode *root) {
    while(1) {
        for(;root;root=root->left) push(root);
        root = pop();
        if(!root) break;
        printf("[%d] ", root->data);
        root = root->right;
    }
}

// 재귀적 중위순회 (비교용)
void inorder_recursive(TreeNode *root) {
    if (root != NULL) {
        inorder_recursive(root->left);
        printf("[%d] ", root->data);
        inorder_recursive(root->right);
    }
}
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main() {
    // printf("트리 구조:\n");
    // printf("        15\n");
    // printf("       /  \\\n");
    // printf("      4    20\n");
    // printf("     /    /  \\\n");
    // printf("    1    16   25\n\n");

    printf("반복적 중위순회 결과: ");
    inorder_iter(root);
    printf("\n");

    printf("재귀적 중위순회 결과: ");
    inorder_recursive(root);
    printf("\n\n");

    printf("=== 스택 상태 확인 ===\n");
    printf("현재 스택 top: %d\n", top);
    
    // 스택이 비어있는지 확인
    if (top == -1) {
        printf("스택이 비어있습니다.\n");
    } else {
        printf("스택에 남은 요소가 있습니다.\n");
    }

    return 0;
} 