// WAP to traverse a binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int info;
    struct tree_node *left;
    struct tree_node *right;
} node;

void create(node **);
node *insert(node *, int);
void displayPreorder(node *);
void displayInorder(node *);
void displayPostorder(node *);

void main()
{
    node *root = NULL;
    create(&root);
    printf("\nPreorder : ");
    displayPreorder(root);
    printf("\nInorder  : ");
    displayInorder(root);
    printf("\nPostorder: ");
    displayPostorder(root);
}

void create(node **root)
{
    int s, ele;
    printf("Enter total elements: ");
    scanf("%d", &s);
    printf("Enter bst elements: ");
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &ele);
        *root = insert(*root, ele);
    }
}

node *insert(node *root, int element)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->info = element;
        root->left = NULL;
        root->right = NULL;
    }
    else if (element < root->info)
        root->left = insert(root->left, element);
    else if (element >= root->info)
        root->right = insert(root->right, element);
    return root;
}

void displayPreorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    displayPreorder(root->left);
    displayPreorder(root->right);
}

void displayInorder(node *root)
{
    if (root == NULL)
        return;
    displayInorder(root->left);
    printf("%d ", root->info);
    displayInorder(root->right);
}

void displayPostorder(node *root)
{
    if (root == NULL)
        return;
    displayPostorder(root->left);
    displayPostorder(root->right);
    printf("%d ", root->info);
}

/*
Enter total elements: 5
Enter bst elements: 4 1 5 2 3

Preorder : 4 1 2 3 5
Inorder  : 1 2 3 4 5
Postorder: 3 2 1 5 4
*/