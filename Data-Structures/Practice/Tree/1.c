#include <stdio.h>
#include <Stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

void preorder(struct node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

void postorder(struct node *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

int nodeCount(struct node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = nodeCount(p->left);
        y = nodeCount(p->right);

        return x + y + 1;
    }
}

int twoChildCnt(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }

    int x = twoChildCnt(p->left);
    int y = twoChildCnt(p->right);

    // Count only if both left and right children exist
    if (p->left != NULL && p->right != NULL)
    {
        return x + y + 1;
    }
    else
    {
        return x + y;
    }
}

int leafNodeCnt(struct node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = leafNodeCnt(p->left);
        y = leafNodeCnt(p->right);

        if (p->left == NULL && p->right == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
}

int oneChildNode(struct node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = oneChildNode(p->left);
        y = oneChildNode(p->right);

        if ((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
}

// Function to print nodes at a given level
void printGivenLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// Function to perform level order traversal of the binary tree
void levelOrderTraversal(struct node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

struct node *create()
{
    int x;
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter the value to store. -1 to exit ");
    scanf("%d", &x);
    if (x == -1) 
    {
        return 0;
    }
    newnode->data = x;
    printf("enter left child of %d ", x);
    newnode->left = create();
    printf("enter right child of %d ", x);
    newnode->right = create();
    return newnode;
}

int main()
{
    struct node *root;
    root = create();

    printf("Preorder traversal: ");
    preorder(root);

    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);

    printf("\n");
    printf("Level order traversal of the binary tree: ");
    levelOrderTraversal(root);

    printf("\n");
    printf("Node count is %d ", nodeCount(root));

    printf("\n");
    printf("Node having 2 child count is %d ", twoChildCnt(root));

    printf("\n");
    printf("count of leaf node is %d ", leafNodeCnt(root));

    printf("\n");
    printf("Node having only 1 child count is %d ", oneChildNode(root));
}