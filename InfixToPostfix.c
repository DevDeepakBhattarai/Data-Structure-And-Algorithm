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

int isOperator(char element) {
    if (element == '+' || element == '-' || element == '*' || element == '/') return 1;
    return 0;
}
int checkOperatorPrecedence(char a, char b) {
    if (a == '+' && (b == '-' || b == '+')) return 0;
    if (a == '+' && (b == '*' || b == '/')) return 0;

    if (a == '-' && (b == '-' || b == '+')) return 0;
    if (a == '-' && (b == '*' || b == '/')) return 0;

    if (a == '*' && (b == '-' || b == '+')) return 1;
    if (a == '*' && (b == '*' || b == '/')) return 0;

    if (a == '/' && (b == '-' || b == '+')) return 1;
    if (a == '/' && (b == '*' || b == '/')) return 0;

}
int main() {
    char infixExpression[100], postfixExpression[100] = "";
    int index = 0, i = 0;

    Stack* stack = stackCreate(10);
    printf("Enter the infix expression : ");
    gets(infixExpression);
    char element = infixExpression[0];
    while (element != '\0') {
        recheck:
        if (isOperator(element) && stackIsEmpty(stack)) {
            stackPush(stack, element);
        } else if (isOperator(element) && !stackIsEmpty(stack) && checkOperatorPrecedence(element, stackPeek(stack, 1))) {
            stackPush(stack, element);
        } else if (isOperator(element) && !stackIsEmpty(stack) && !checkOperatorPrecedence(element, stackPeek(stack, 1))) {
            char popped_element = stackPop(stack);
            postfixExpression[index] = popped_element;
            index++;
            goto recheck;
        } else {
            postfixExpression[index] = element;
            index++;
        }
        i++;
        element = infixExpression[i];
    }
    do {
        char operator=stackPop(stack);
        postfixExpression[index] = operator;
        index++;
    } while (!stackIsEmpty(stack));

    printf("%s\n", postfixExpression);
    return 0;
}