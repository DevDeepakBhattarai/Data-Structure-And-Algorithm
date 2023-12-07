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


void queueEnqueueR(Queue* queue, int value) {
    if ((queue->back + 1) >= queue->size) {
        printf("Queue full ! Cannot enqueue %d \n", value);
        return;
    }
    queue->back++;
    queue->list[queue->back] = value;
}


void queueEnqueueF(Queue* queue, int value) {

    if (queue->front == -1) {
        printf("Queue full ! Cannot enqueue %d \n", value);
        return;
    }
    queue->list[queue->front] = value;
    queue->front--;

}

int queueIsEmpty(Queue* queue) {
    return queue->front == queue->back ? 1 : 0;
}
int queueDequeueF(Queue* queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue nothing to dequeue\n");
        return -1;
    }
    queue->front++;
    int dequeuedElement = queue->list[queue->front];
    return dequeuedElement;
}

int queueDequeueR(Queue* queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue nothing to dequeue\n");
        return -1;
    }
    int dequeuedElement = queue->list[queue->back];
    queue->back--;
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

    queueEnqueueR(queue, 2);
    queueEnqueueR(queue, 3);
    queueEnqueueR(queue, 1);
    queueEnqueueR(queue, 4);
    queueEnqueueR(queue, 5);
    queueEnqueueR(queue, 6);
    queueEnqueueR(queue, 7);
    queueEnqueueR(queue, 8);
    queueEnqueueR(queue, 9);
    queueEnqueueR(queue, 10);

    queueDequeueF(queue);
    queueEnqueueF(queue, 10);

    queueDequeueR(queue);
    queueDequeueR(queue);

    // queueDequeueF(queue);
    // queueDequeueF(queue);
    // queueDequeueF(queue);
    // queueDequeueF(queue);
    // queueDequeueF(queue);
    // queueDequeueF(queue);
    // queueDequeueF(queue);
    // queueDequeueF(queue);
    // queueDequeueF(queue);

    queuePrint(queue);
    return 0;
}