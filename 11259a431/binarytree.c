#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void freeTree(struct Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    struct Node *root = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter %d values: ", n);

    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input.\n");
            freeTree(root);
            return 1;
        }

        root = insert(root, value);
    }

    printf("\nIn-order traversal: ");
    inorder(root);

    printf("\nPre-order traversal: ");
    preorder(root);

    printf("\nPost-order traversal: ");
    postorder(root);

    printf("\n");

    freeTree(root);

    return 0;
}