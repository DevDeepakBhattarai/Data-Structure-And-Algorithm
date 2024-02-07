#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;  // Points to the next node in the list
    struct Node* right;
    int height;
}Node;

void printTreeSideways(Node* root, int level, char arrow) {
    if (root == NULL)
        return;

    level += 5;

    printTreeSideways(root->right, level, '/');

    for (int i = 5; i < level; i++)
        printf(" ");
    printf("%c- %d\n", arrow, root->data);

    printTreeSideways(root->left, level, '\\');
}
int max(int a, int b) {
    return a > b ? a : b;
}
int getHeight(Node* root) {
    if (root == NULL)
        return 0;
    return root->height;
}


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Something went wrong");
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    newNode->data = data;
    return newNode;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return x;
}

int getBalanceFactor(Node* node) {
    if (node == NULL) return 0;
    return  getHeight(node->left) - getHeight(node->right);
}
Node* insertInAVL(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (root->data == data) {
        printf("%d already exits in the tree. Cannot insert it again\n", data);
        return root;
    }
    if (data > root->data) {
        root->right = insertInAVL(root->right, data);
    } else if (data < root->data) {
        root->left = insertInAVL(root->left, data);
    } else {
        printf("Duplicate data; Cannot enter in the AVL");
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balanceFactor = getBalanceFactor(root);

    // Left Left Case:
    if (balanceFactor > 1 && data < root->left->data) {
        return rightRotate(root);
    }
    // Right Right Case:
    if (balanceFactor < -1 && data > root->right->data) {
        return   leftRotate(root);
    }
    // Left Right Case:
    if (balanceFactor > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return   rightRotate(root);
    }
    // Right Left Case:
    if (balanceFactor < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return   leftRotate(root);
    }

    return root;


}
void inOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf("%d \t", node->data);
    inOrderTraversal(node->right);

}

Node* insertLogger(Node* root, int data) {
    root = insertInAVL(root, data);
    printTreeSideways(root, 0, '|');
    printf("\n\n");
    return root;
}

int main() {
    root = Node * root = NULL;
    root = insertLogger(root, 45);
    root = insertLogger(root, 9);
    root = insertLogger(root, 4);
    root = insertLogger(root, 3);
    root = insertLogger(root, 400);
    return 0;
}
