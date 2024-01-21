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

void preOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }

    printf("%d \t", node->data);

    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void postOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);

    printf("%d \t", node->data);
}
void inOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf("%d \t", node->data);
    inOrderTraversal(node->right);

}


int main() {
    Node* root = createNode(7);
    Node* n2 = createNode(2);
    Node* n3 = createNode(3);
    Node* n4 = createNode(1);
    Node* n5 = createNode(4);
    root->left = n2;
    root->right = n3;

    n2->left = n4;
    n3->right = n5;
    printf("\nPreOrder \n");
    preOrderTraversal(root);
    printf("\nPost Order \n");
    postOrderTraversal(root);
    printf("\nIn Order \n");
    inOrderTraversal(root);

    return 0;

}
