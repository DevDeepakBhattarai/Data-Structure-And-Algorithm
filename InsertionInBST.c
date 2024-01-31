#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;  // Points to the next node in the list
    struct Node* right;
}Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Something went wrong");
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

void printTreeSideways(Node* root, int level, char arrow) {
    if (root == NULL)
        return;

    // Increase the indentation for better visualization
    level += 5;

    // Print the right subtree first
    printTreeSideways(root->right, level, '/');

    // Print the current node
    // printf("\n");
    for (int i = 5; i < level; i++)
        printf(" ");
    printf("%c- %d\n", arrow, root->data);

    // Print the left subtree
    printTreeSideways(root->left, level, '\\');
}

void insertInBST(Node* root, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    void insertHelper(Node * root, Node * newNode) {
        if (root == NULL) {
            printf("%d cannot be inserted in the tree\n", newNode->data);
            return;
        }
        if (root->data == newNode->data) {
            printf("%d already exits in the tree. Cannot insert it again\n", newNode->data);
        }
        if (newNode->data > root->data && root->right != NULL) {
            insertHelper(root->right, newNode);
        } else if (newNode->data < root->data && root->left != NULL) {
            insertHelper(root->left, newNode);
        } else if (newNode->data > root->data && root->right == NULL) {
            root->right = newNode;
            printf("Insertion Successful\n");
            return;
        } else if (newNode->data < root->data && root->left == NULL) {
            root->left = newNode;
            printf("Insertion Successful\n");
            return;
        }
    }
    insertHelper(root, newNode);

}
int main() {
    Node* root = createNode(7);

    Node* n2 = createNode(6);
    Node* n3 = createNode(8);

    Node* n4 = createNode(2);
    Node* n5 = createNode(9);
    Node* n6 = createNode(5);
    Node* n7 = createNode(18);

    Node* n8 = createNode(19);
    Node* n9 = createNode(14);

    root->left = n2;
    root->right = n3;

    n2->left = n4;
    // n2->right = n5;

    n5->left = n6;
    n5->right = n7;

    n3->right = n8;
    n8->left = n9;
    printTreeSideways(root, 0, '|');
    insertInBST(root, 21);
    insertInBST(root, 5);
    insertInBST(root, 6);
    printTreeSideways(root, 0, '|');


    return 0;
}