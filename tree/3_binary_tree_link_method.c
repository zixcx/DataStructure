#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main()
{
    // printf("트리 구조:\n");
    // printf("        15\n");
    // printf("       /  \\\n");
    // printf("      4    20\n");
    // printf("     /    /  \\\n");
    // printf("    1    16   25\n\n");

    printf("전위 순회 (Preorder): ");
    preorder(root);
    printf("\n");

    printf("중위 순회 (Inorder): ");
    inorder(root);
    printf("\n");

    printf("후위 순회 (Postorder): ");
    postorder(root);
    printf("\n\n");

    return 0;
} 