#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    int size;
    int used;
    int* list;
    int front;
    int back;
}Queue;

Queue* queueCreate(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    // The size here is increased by one because the first index is left empty so that the front and the back of th stack may be known.
    queue->size = size + 1;
    queue->front = 0;
    queue->back = 0;
    queue->list = (int*)malloc(size + 1 * sizeof(int));
    return queue;
}


void queueEnqueue(Queue* queue, int value) {
    if (((queue->back + 1) % queue->size) == queue->front) {
        printf("Queue full ! Cannot enqueue %d \n", value);
        return;
    }

    queue->list[queue->back] = value;
    queue->back = (queue->back + 1) % queue->size;
    printf("Queuing element %d\n", value);
}

int queueIsEmpty(Queue* queue) {
    return queue->front == queue->back ? 1 : 0;
}
int queueDequeue(Queue* queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue nothing to dequeue\n");
        return -1;
    }
    int dequeuedElement = queue->list[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    printf("Dequeueing element %d\n", dequeuedElement);
    return dequeuedElement;
}

void queuePrint(Queue* queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue is empty");
        return;
    }
    int used = queue->back > queue->front ? queue->back - queue->front : queue->size - (queue->front - queue->back);
    int arrayIndex = queue->front;

    for (int i = 0; i < used; i++) {
        printf("%d\t", queue->list[arrayIndex]);
        arrayIndex = (arrayIndex + 1) % queue->size;
    }
}
int main() {
    Queue* queue = queueCreate(10);

    queueEnqueue(queue, 1);
    queueEnqueue(queue, 2);
    queueEnqueue(queue, 3);
    queueEnqueue(queue, 4);
    queueEnqueue(queue, 5);
    queueEnqueue(queue, 6);
    queueEnqueue(queue, 7);
    queueEnqueue(queue, 8);
    queueEnqueue(queue, 9);
    queueEnqueue(queue, 10);
    queueEnqueue(queue, 11);


    queuePrint(queue);
    return 0;
}