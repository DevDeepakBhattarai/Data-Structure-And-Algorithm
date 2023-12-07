#include <stdio.h>

#include <stdlib.h>
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

int queueDequeue(Queue* queue) {

    Node* current = queue->front;
    if (current == NULL) {
        printf("Queue is empty cannot dequeue anything\n");
        return -1;
    }

    int dequeuedElement = current->data;
    Node* node = queue->front->next;
    free(current);
    queue->front = node;
    return dequeuedElement;
}


int main() {
    Queue* queue = queueCreate();
    queueEnqueue(queue, 1);
    queueEnqueue(queue, 2);
    queueEnqueue(queue, 3);

    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);


    queueEnqueue(queue, 3);
    queueEnqueue(queue, 2);
    queueEnqueue(queue, 1);

    printf("Dequeued %d \n", queueDequeue(queue));

    queuePrint(queue);
    return 0;
}