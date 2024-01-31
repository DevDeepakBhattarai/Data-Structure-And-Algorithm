#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef enum {
    true,
    false
}boolean;

typedef struct Node {
    int data;
    struct Node* left;  // Points to the next node in the list
    struct Node* right;
}Node;


typedef struct Queue {
    int size;
    int used;
    Node* list;
    int front;
    int back;
}Queue;

Queue* queueCreate(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = size;
    queue->front = -1;
    queue->back = -1;
    queue->list = (Node*)malloc(size * sizeof(Node));
    return queue;
}


void queueEnqueue(Queue* queue, Node* value) {
    if ((queue->back + 1) >= queue->size) {
        printf("Queue full ! Cannot enqueue %d \n", value->data);
        return;
    }


    queue->back++;
    queue->list[queue->back] = *(value);
}

int queueIsEmpty(Queue* queue) {
    return queue->front == queue->back ? 1 : 0;
}
Node* queueDequeue(Queue* queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue nothing to dequeue\n");
        return NULL;
    }
    queue->front++;
    Node* dequeuedElement = &(queue->list[queue->front]);
    return dequeuedElement;
}


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

typedef struct {
    int size;
    int used;
    int* list;  // Change the list to store integers instead of Nodes
    int front;
    int back;
} NumberQueue;

NumberQueue* numberQueueCreate(int size) {
    NumberQueue* queue = (NumberQueue*)malloc(sizeof(NumberQueue));
    queue->size = size;
    queue->front = -1;
    queue->back = -1;
    queue->list = (int*)malloc(size * sizeof(int));  // Allocate memory for integers
    return queue;
}

void numberQueueEnqueue(NumberQueue* queue, int value) {
    if ((queue->back + 1) >= queue->size) {
        printf("NumberQueue full! Cannot enqueue %d \n", value);
        return;
    }

    queue->back++;
    queue->list[queue->back] = value;
}

int numberQueueIsEmpty(NumberQueue* queue) {
    return queue->front == queue->back ? 1 : 0;
}

int numberQueueDequeue(NumberQueue* queue) {
    if (queueIsEmpty(queue)) {
        printf("NumberQueue is empty! Nothing to dequeue\n");
        return -1;  // Assuming -1 is an invalid value for your use case
    }

    queue->front++;
    int dequeuedElement = queue->list[queue->front];
    return dequeuedElement;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int searchBST(Node* root, int data) {
    if (root == NULL) {
        return INT_MIN;
    }
    if (root->data == data) {
        return root->data;
    }
    if (root->data > data) {
        return searchBST(root->left, data);
    }
    if (root->data < data) {
        return  searchBST(root->right, data);
    }
}



int treeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}
void addSpace(char* string, int size) {
    for (int i = 0; i < size; i++) {
        strcat(string, "  ");
    }
}
void printSpace(int size) {

    for (int i = 0; i < size; i++) {
        printf("  ");
    }
}

void printBST(Node* root) {
    static Queue* q1 = NULL;
    static Queue* q2 = NULL;
    static NumberQueue* nq1 = NULL;
    static NumberQueue* nq2 = NULL;
    char arrowLine[200] = "";
    char dataLine[200] = "";
    Node* prev = NULL;
    char temp[20] = "";
    if (q1 == NULL) {
        q1 = queueCreate(100);
    }

    if (nq1 == NULL) {
        nq1 = numberQueueCreate(100);
    }
    if (nq2 == NULL) {
        nq2 = numberQueueCreate(100);
    }
    if (q2 == NULL) {
        q2 = queueCreate(100);
    }
    int height = 15;
    queueEnqueue(q1, root);
    addSpace(dataLine, height + 1);
    addSpace(arrowLine, height);
    while (!queueIsEmpty(q1) || !queueIsEmpty(q2)) {
        while (!queueIsEmpty(q1)) {
            root = queueDequeue(q1);
            int number;
            do {
                number = numberQueueDequeue(nq1);
                if (number == 0) {
                    addSpace(dataLine, 2);
                }
            } while (number == 0);

            sprintf(temp, "%d", root->data);
            strcat(dataLine, temp);
            addSpace(dataLine, 5);
            if (root->left != NULL) {
                numberQueueEnqueue(nq2, 1);
                strcat(arrowLine, "/");
                addSpace(arrowLine, 5);
                queueEnqueue(q2, root->left);
            }

            if (root->right != NULL) {
                numberQueueEnqueue(nq2, 1);
                strcat(arrowLine, "\\");
                queueEnqueue(q2, root->right);
            }

            if (root->left == NULL) {
                numberQueueEnqueue(nq2, 0);
                addSpace(arrowLine, 2);

            }
            if (root->right == NULL) {
                numberQueueEnqueue(nq2, 0);
                addSpace(arrowLine, 2);
            }
        }
        printf("%s", dataLine);
        printf("\n");
        printf("%s", arrowLine);
        printf("\n");
        strcpy(arrowLine, "");
        strcpy(dataLine, "");
        addSpace(dataLine, height);
        addSpace(arrowLine, --height);


        while (!queueIsEmpty(q2)) {
            root = queueDequeue(q2);

            int number;
            do {
                number = numberQueueDequeue(nq2);
                if (number == 0) {
                    addSpace(dataLine, 2);
                }
            } while (number == 0);




            sprintf(temp, "%d", root->data);
            strcat(dataLine, temp);
            addSpace(dataLine, 5);
            if (root->left != NULL) {
                numberQueueEnqueue(nq1, 1);
                strcat(arrowLine, "/");
                queueEnqueue(q1, root->left);
            }
            if (root->right != NULL) {
                numberQueueEnqueue(nq1, 1);

                addSpace(arrowLine, 5);
                strcat(arrowLine, "\\");
                queueEnqueue(q1, root->right);
            }
            if (root->left == NULL) {
                numberQueueEnqueue(nq1, 0);

                addSpace(arrowLine, 2);
            }
            if (root->right == NULL) {
                numberQueueEnqueue(nq1, 0);

                addSpace(arrowLine, 2);
            }

        }

        printf("%s", dataLine);
        printf("\n");
        printf("%s", arrowLine);
        printf("\n");
        strcpy(arrowLine, "");
        strcpy(dataLine, "");
        addSpace(dataLine, height);
        addSpace(arrowLine, --height);
    }
}


int iterativeSearchOfBST(Node* node, int data) {
    while (node != NULL) {
        if (node->data == data) {
            return node->data;
        } else if (node->data > data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return NULL;
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
    Node* n10 = createNode(21);

    root->left = n2;
    root->right = n3;

    n2->left = n4;
    n2->right = n5;

    n5->left = n6;
    n5->right = n7;

    n3->right = n8;
    n8->left = n9;
    n8->right = n10;
    // printBST(root);

    printf("%d", iterativeSearchOfBST(root, 14));
    // printNodeView(root, 0);
    // printTreeSideways(root, 0, '|');
    // printTreeVertically(root, 5, treeHeight(root) * 3);
    return 0;

}


