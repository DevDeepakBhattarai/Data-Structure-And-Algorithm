#include <stdio.h>
#include <stdlib.h>

typedef enum {
    true,
    false
}boolean;


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

boolean isBST(Node* node) {
    if (node == NULL) return true;
    static Node* prev = NULL; // ! This static keyword makes it so that the value of prev is same across all the function call. For intuition -> If recursion is a loop then it is like declaring a variable outside the loop.

    if (isBST(node->left) == false) {
        return false;
    }

    if (prev != NULL && node->data <= prev->data) {
        return false;
    }
    prev = node;

    return isBST(node->right);
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

    printf("\nPreOrder \n");
    preOrderTraversal(root);
    printf("\nPost Order \n");
    postOrderTraversal(root);
    printf("\nIn Order \n");
    inOrderTraversal(root);


    boolean binarySearchTree = isBST(root);
    if (binarySearchTree == true) {
        printf("\nBinary Search Tree Woo!\n");
    } else {
        printf("\nNot a BST\n");
    }
    return 0;

}
