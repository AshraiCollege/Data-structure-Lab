#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int arr[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insert elements into the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    printf("recent value : %d\n",root->data);

    // Perform inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}
