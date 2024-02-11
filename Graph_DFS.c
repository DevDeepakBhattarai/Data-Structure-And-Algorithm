#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Graph {
    int numVertices;
    Node** adjacencyLists;
    int size;
} Graph;


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
    graph->size = 0;
    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    if (graph->adjacencyLists[src] == NULL) {
        graph->size++;
    }

    newNode->next = graph->adjacencyLists[src];
    graph->adjacencyLists[src] = newNode;
}

void printGraph(Graph* graph) {
    Node* current;
    for (int i = 0; i < graph->size; i++) {
        printf("%d : ", i);
        current = graph->adjacencyLists[i];
        if (current == NULL) {
            printf("The List is empty\n");
            return;
        }
        while (current != NULL) {
            {
                printf("%d ", current->data);
                current = current->next;
                if (current != NULL) {
                    printf("-> ");
                }
            }
        }
        printf("\n");
    }
}

void DFS(Graph* graph, int start) {
    int* visited = (int*)calloc(graph->size, sizeof(int));
    void  DFSHelper(Graph * graph, int start) {
        if (visited[start] == 0) {
            printf("%d ", start);
            visited[start] = 1;
            Node* node = graph->adjacencyLists[start];
            while (node != NULL) {
                if (visited[node->data] == 0)
                    DFSHelper(graph, node->data);

                node = node->next;
            }
        }
    }
    DFSHelper(graph, start);
    printf("\n");
}

int main() {
    Graph* graph = createGraph(100);
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
    printGraph(graph);
    DFS(graph, 0);

    // printf("Size: %d\n ", graph->size);
    return 0;
}