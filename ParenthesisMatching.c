#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int size;
    int top;
    char* array;
}Stack;

Stack* stackCreate(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    // Stack* stack;
    stack->size = size;
    stack->top = -1;
    stack->array = (char*)malloc((size) * sizeof(char));
    return stack;
}

int match(char a, char b) {
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')) return 1;
    return 0;
}
char stackPop(Stack* stack) {
    if (stack->top < 0) {
        return '\0';
    }
    char value = stack->array[stack->top];
    stack->top--;
    return value;
}

void stackPush(Stack* stack, char value) {

    if (stack->top >= stack->size - 1) {
        printf("Stack overflow \n");
        return;
    }
    stack->array[stack->top + 1] = value;
    stack->top = stack->top + 1;
}

void stackPrint(Stack* stack) {
    for (char i = 0;i <= stack->top;i++) {
        printf("%c\t", stack->array[i]);
    }
}

int stackIsFull(Stack* stack) {
    return stack->top == stack->size - 1 ? 1 : 0;
}
int stackIsEmpty(Stack* stack) {
    return stack->top == -1 ? 1 : 0;
}

char stackPeek(Stack* stack, char position) {
    char index = stack->top - position + 1;
    if (index < 0 || position < 1) {
        printf("Invalid stack position : ");
        return -1;
    }
    return stack->array[index];

}



int main() {
    Stack* stack = stackCreate(10);
    char expression[1024], element;
    printf("Enter a expression : ");
    gets(expression);
    printf("%s\n", expression);
    int i = 0;
    element = expression[i];

    while (element != '\0') {
        if (element == '(' || element == '{' || element == '[') {
            stackPush(stack, element);
        }
        if (element == ')' || element == '}' || element == ']') {
            char popped_element = stackPop(stack);
            printf("%c", popped_element);
            if (!match(popped_element, element)) {
                printf("Not balanced");
                goto end;
            }
        }
        i++;
        element = expression[i];
    }
    if (stackIsEmpty(stack) == 1) {
        printf("Balanced");
    } else {
        printf("Not balanced");
    }

    end:

    return 0;
}