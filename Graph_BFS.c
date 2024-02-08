
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Queue {
    Node* front;
    Node* back;
    int size;
}Queue;

Queue* queueCreate() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
    return queue;
}

void queuePrint(Queue* queue) {
    Node* current = queue->front;
    if (current == NULL) {
        printf("The List is empty\n");
        return;
    }
    while (current != NULL) {
        {
            printf("%d\t", current->data);
            current = current->next;
        }
    }
}

void queueEnqueue(Queue* queue, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    if (queue->front == NULL) {
        queue->front = node;
        queue->back = node;
        queue->size++;
    } else {
        Node* current = queue->back;
        current->next = node;
        queue->back = node;
        queue->size++;
    }
}
int queueIsEmpty(Queue* queue) {
    return queue->front == queue->back && queue->front == NULL && queue->back == NULL ? 1 : 0;
}
int queueDequeue(Queue* queue) {
    Node* current = queue->front;
    if (current == NULL) {
        printf("Queue is empty, cannot dequeue anything\n");
        return -1;
    }

    int dequeuedElement = current->data;
    Node* node = queue->front->next;
    free(current);
    queue->front = node;
    if (queue->size <= 1) {
        queue->back = node;
    }
    queue->size--;
    return dequeuedElement;
}

void BFS(int(*graph)[7], int startNode) {
    Queue* explorationQueue = queueCreate();
    int node;
    int visited[7] = { 0,0,0,0,0,0,0 };
    visited[startNode] = 1;
    queueEnqueue(explorationQueue, startNode);
    printf("%d ", startNode);

    while (queueIsEmpty(explorationQueue) == 0) {
        node = queueDequeue(explorationQueue);
        for (int j = 0; j < 7; j++) {
            if (graph[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                queueEnqueue(explorationQueue, j);
            }
        }
    }
}

int main() {
    int graph[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0}
    };

    Queue* queue = queueCreate();


    BFS(graph, 0);

    return 0;
}