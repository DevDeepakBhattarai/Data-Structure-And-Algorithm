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
    queue->size = size;
    queue->front = -1;
    queue->back = -1;
    queue->list = (int*)malloc(size * sizeof(int));
    return queue;
}


void queueEnqueue(Queue* queue, int value) {
    if ((queue->back + 1) >= queue->size) {
        printf("Queue full ! Cannot enqueue %d \n", value);
        return;
    }


    queue->back++;
    queue->list[queue->back] = value;
}

int queueIsEmpty(Queue* queue) {
    return queue->front == queue->back ? 1 : 0;
}
int queueDequeue(Queue* queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue nothing to dequeue\n");
        return -1;
    }
    queue->front++;
    int dequeuedElement = queue->list[queue->front];
    return dequeuedElement;
}

void queuePrint(Queue* queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue is empty");
        return;
    }
    for (int i = (queue->front + 1); i <= queue->back; i++) {
        printf("%d\t", queue->list[i]);
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


    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);
    queueDequeue(queue);

    queuePrint(queue);
    return 0;
}