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

Node* inOrderPredecessorForDeletion(Node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;

}

struct Node* inOrderPredecessorForAny(struct Node* root, int key) {
    struct Node* pred = NULL;
    while (root != NULL) {
        if (root->data < key) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}
Node* deletionInBST(Node* root, int data) {
    if (root == NULL) {
        printf("Data not available to delete\n");
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("Data deleted  successfully\n");
        free(root);
        return NULL;
    }
    if (data > root->data) {
        root->right = deletionInBST(root->right, data);
    } else if (data < root->data) {
        root->left = deletionInBST(root->left, data);
    } else {
        printf("Data deleted  successfully\n");
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL && root->left != NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        } else {
            Node* predecessor = inOrderPredecessorForDeletion(root);
            root->data = predecessor->data;
            root->left = deletionInBST(root->left, predecessor->data);
        }
    }
    return root;
}



int main() {
    Node* root = createNode(7);

    root->left = createNode(5);
    root->right = createNode(19);


    root->left->left = createNode(2);
    root->left->right = createNode(6);

    root->right->right = createNode(19);
    root->right->right->left = createNode(14);

    printTreeSideways(root, 0, '|');
    insertInBST(root, 21);
    printTreeSideways(root, 0, '|');
    deletionInBST(root, 21);
    printTreeSideways(root, 0, '|');
    deletionInBST(root, 8);
    printTreeSideways(root, 0, '|');




    return 0;
}