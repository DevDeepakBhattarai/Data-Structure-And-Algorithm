#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Graph {
    int numVertices;
    int** adjacencyMatrix;
    int size;
    // Max node keeps track of the  maximum node/vertex which is used while printing the graph adjacency Matrix
    int maxNode;
} Graph;

typedef struct Index {
    int i;
    int j;
    int weight;
} Index;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->size = 0;
    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*)calloc(numVertices, sizeof(int));
    }
    graph->maxNode = 0;
    graph->maxNode = -1;
    return graph;
}

int isConnectToOtherNode(int* array, int size) {
    for (int i = 0; i <= size;i++) {
        if (array[i] != 0)
            return 1;
    }
    return 0;
}
void printGraph(Graph* graph) {
    for (int i = 0; i <= graph->maxNode; i++) {
        for (int j = 0; j <= graph->maxNode; j++) {
            printf("%d   ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");

    }

}

Index findSmallestWeightedConnection(int** array, int size) {
    Index index;
    index.weight = INT_MAX;
    for (int i = 0;i <= size;i++) {
        for (int j = i; j <= size; j++) {
            if (array[i][j] != 0 && array[i][j] < index.weight) {
                index.weight = array[i][j];
                index.i = i;
                index.j = j;
            }
        }
    }
    return index;
}


void addEdge(Graph* graph, int src, int dest, int weight) {

    graph->maxNode = graph->maxNode < src ? src : graph->maxNode;
    graph->maxNode = graph->maxNode < dest ? dest : graph->maxNode;

    if (!(isConnectToOtherNode(graph->adjacencyMatrix[src], graph->maxNode))) {
        graph->size++;
    }
    if (!(isConnectToOtherNode(graph->adjacencyMatrix[dest], graph->maxNode))) {
        graph->size++;
    }

    graph->adjacencyMatrix[src][dest] = weight;
    graph->adjacencyMatrix[dest][src] = weight;
}



Graph* PrimsAlgorithm(Graph* graph) {
    Graph* minimumSpanningTree = createGraph(graph->maxNode + 1);
    int* included = (int*)calloc(graph->size + 1, sizeof(int));
    Index smallestConnectionInTheGraph = findSmallestWeightedConnection(graph->adjacencyMatrix, graph->maxNode);
    addEdge(minimumSpanningTree, smallestConnectionInTheGraph.i, smallestConnectionInTheGraph.j, smallestConnectionInTheGraph.weight);
    included[smallestConnectionInTheGraph.i] = 1;
    included[smallestConnectionInTheGraph.j] = 1;
    int totalVerticesInMST = 2;

    while (totalVerticesInMST < graph->size) {
        Index smallestEdge;
        smallestEdge.weight = INT_MAX;
        for (int i = 0;i <= graph->size; i++) {
            if (included[i] == 1) {
                for (int j = 0; j <= graph->size; j++) {
                    if (graph->adjacencyMatrix[i][j] != 0 && graph->adjacencyMatrix[i][j] < smallestEdge.weight
                    && included[j] == 0) {
                        smallestEdge.weight = graph->adjacencyMatrix[i][j];
                        smallestEdge.i = i;
                        smallestEdge.j = j;
                    }
                }
            }
        }
        addEdge(minimumSpanningTree, smallestEdge.i, smallestEdge.j, smallestEdge.weight);
        included[smallestEdge.j] = 1;
        totalVerticesInMST++;
    }
    return minimumSpanningTree;
}

int minimumCost(Graph* MST) {
    int sum = 0;
    for (int i = 0; i <= MST->maxNode;i++) {
        for (int j = i; j <= MST->maxNode;j++) {
            sum += MST->adjacencyMatrix[i][j];
        }
    }
    return sum;
}
int main() {
    Graph* graph = createGraph(100);
    addEdge(graph, 1, 2, 28);
    addEdge(graph, 1, 6, 10);
    addEdge(graph, 2, 3, 16);
    addEdge(graph, 2, 7, 14);
    addEdge(graph, 6, 5, 25);
    addEdge(graph, 5, 4, 22);
    addEdge(graph, 4, 3, 12);
    addEdge(graph, 4, 7, 18);
    addEdge(graph, 5, 7, 24);

    printGraph(graph);
    printf("\n\n");

    Graph* tree = PrimsAlgorithm(graph);
    printGraph(tree);
    printf("\n%d ", minimumCost(tree));
    return 0;
}

