#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
    int size;
    int top;
    int* array;
}Stack;

Stack* stackCreate(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (int*)malloc(size  * sizeof(int));
    return stack;
}

int stackPop(Stack* stack) {
    if (stack->top < 0) {
        printf("Nothing to pop\n");
        return -1;
    }
    int value = stack->array[stack->top];
    stack->top--;
    return value;
}

void stackPush(Stack* stack, int value) {

    if (stack->top >= stack->size - 1) {
        printf("Stack overflow \n");
        return;
    }
    stack->array[stack->top + 1] = value;
    stack->top = stack->top + 1;
}

void stackPrint(Stack* stack) {
    for (int i = 0;i <= stack->top;i++) {
        printf("%d\t", stack->array[i]);
    }
}

int stackIsFull(Stack* stack) {
    return stack->top == stack->size - 1 ? 1 : 0;
}
int stackIsEmpty(Stack* stack) {
    return stack->top == -1 ? 1 : 0;
}

int stackPeek(Stack* stack, int position) {
    int index = stack->top - position + 1;
    if (index < 0 || position < 1) {
        printf("Invalid stack position : ");
        return -1;
    }

    return stack->array[index];

}

int main() {
    Stack* stack = stackCreate(10);
    stackPush(stack, 1);
    stackPush(stack, 2);
    stackPush(stack, 3);
    stackPush(stack, 4);
    stackPush(stack, 5);
    stackPush(stack, 6);

    // printf("%d\n", stackPop(stack));

    // printf("%d\n", stackIsEmpty(stack));
    // printf("%d\n", stackIsFull(stack));
    printf("%d\n", stackPeek(stack, 5));
    stackPrint(stack);
    return 0;
}