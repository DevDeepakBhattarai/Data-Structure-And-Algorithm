
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Graph {
    int numVertices;
    Node** adjacencyLists;
} Graph;

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
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyLists = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyLists[i] = NULL;
    }


    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyLists[src];
    graph->adjacencyLists[src] = newNode;
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

void BFS(Graph* graph, int startNode) {
    Queue* explorationQueue = queueCreate();
    int node;
    int visited[7] = { 0,0,0,0,0,0,0 };
    visited[startNode] = 1;
    queueEnqueue(explorationQueue, startNode);
    printf("%d ", startNode);

    while (queueIsEmpty(explorationQueue) == 0) {
        node = queueDequeue(explorationQueue);
        Node* adjacencyList = graph->adjacencyLists[node];
        while (adjacencyList != NULL) {
            if (visited[adjacencyList->data] == 0) {
                printf("%d ", adjacencyList->data);
                visited[adjacencyList->data] = 1;
                queueEnqueue(explorationQueue, adjacencyList->data);
            }
            adjacencyList = adjacencyList->next;
        }

    }
}

int main() {
    Graph* graph = createGraph(100);
    // Node* node = createNode(0);
    // graph->adjacencyLists[0] = node;
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 0);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 0);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 2);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 4);
    addEdge(graph, 6, 4);

    BFS(graph, 5);

    return 0;
}