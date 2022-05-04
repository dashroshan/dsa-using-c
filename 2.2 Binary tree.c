#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int info;
    struct tree_node *left;
    struct tree_node *right;
} node;

int count = 1;

node *insert(node *root, int element);
void displayPreorder(node *root);
void displayInorder(node *root);
void displayPostorder(node *root);
void displayDiagram(node *root, int level);

void main()
{
    node *root = NULL;
    int choice, element;
loop:
    printf("\n1: Insert\n2: Display pre-order\n3: Display in-order\n4: Display post-order\n5: Display diagram\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        printf("Enter element: ");
        scanf("%d", &element);
        root = insert(root, element);
        printf("Element inserted\n");
        goto loop;
    case 2:
        displayPreorder(root);
        goto loop;
    case 3:
        displayInorder(root);
        goto loop;
    case 4:
        displayPostorder(root);
        goto loop;
    case 5:
        displayDiagram(root, 0);
        goto loop;
    default:
        goto loop;
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
        count++;
    }
    else
    {
        if (count % 2 == 0)
            root->left = insert(root->left, element);
        else
            root->right = insert(root->right, element);
    }
    return root;
}

void displayPreorder(node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->info);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

void displayInorder(node *root)
{
    if (root != NULL)
    {
        displayInorder(root->left);
        printf("%d\n", root->info);
        displayInorder(root->right);
    }
}

void displayPostorder(node *root)
{
    if (root != NULL)
    {
        displayPostorder(root->left);
        displayPostorder(root->right);
        printf("%d\n", root->info);
    }
}

void displayDiagram(node *root, int level)
{
    if (root != NULL)
    {
        for (int i = 0; i < level; i++)
            printf(i == level - 1 ? "|-" : "  ");
        printf("%d\n", root->info);
        displayDiagram(root->left, level + 1);
        displayDiagram(root->right, level + 1);
    }
}