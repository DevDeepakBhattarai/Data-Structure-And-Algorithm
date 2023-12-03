#include <stdio.h>

#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef enum Boolean {
    false,
    true
}Boolean;

typedef struct Stack {
    Node* top;
    int length;
}Stack;

Stack* stackCreate() {
    Stack* list = (Stack*)malloc(sizeof(Stack));
    list->top = NULL;
    list->length = 0;
    return list;
}

void stackPrint(Stack* list) {
    Node* current = list->top;
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


void append(Stack* list, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    if (list->top == NULL) {
        list->top = node;
        list->length++;
    } else {
        Node* current = list->top;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        list->length++;
    }
}
void linkedListInsert(Stack* list, int value, int position) {
    if (position > list->length) {
        printf("Cannot Insert %d at position %d\n", value, position);
        return;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;

    if (list->top == NULL) {
        list->top = node;
        list->length++;
    } else if (position == 0) {
        node->next = list->top;
        list->top = node;
        list->length++;
    } else {
        Node* current = list->top;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        list->length++;
    }
}


void linkedListDelete(Stack* list, int position) {
    if (list->top == NULL) {
        printf("Operation not allowed \n");
        return;
    }
    if (position == 0) {
        Node* current = list->top;
        list->top = current->next;
        free(current);
        list->length--;
    } else if (position + 1 == list->length) {
        Node* current = list->top;

        for (int i = 0;i < position - 1; i++) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        list->length--;
    } else {
        Node* current = list->top;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node* elementToDelete = current->next;
        current->next = current->next->next;
        free(elementToDelete);
        list->length--;
    }

}

int linkedListGetItem(Stack* stack, int index) {
    if (index < 1 || index > stack->length) {
        printf("Invalid index");
        return -1;
    }

    Node* current = stack->top;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    return current->data;
}

int stackPop(Stack* stack) {
    int value = linkedListGetItem(stack, 0);
    linkedListDelete(stack, 0);
    return value;
}

void stackPush(Stack* stack, int value) {
    linkedListInsert(stack, value, 0);
}

int stackPeek(Stack* stack, int index) {
    int value = linkedListGetItem(stack, index);
    return value;
}

Boolean stackIsEmpty(Stack* stack) {
    if (stack->top == NULL) return true;
    return false;
}
int main() {
    Stack* stack = stackCreate();
    printf("Is Empty: %d\n", stackIsEmpty(stack));
    stackPush(stack, 1);
    stackPush(stack, 2);
    stackPush(stack, 3);
    stackPush(stack, 4);

    stackPush(stack, 5);

    printf("%d\n", stackPeek(stack, 0));
    printf("Is Empty: %d\n", stackIsEmpty(stack));

    // printf("%d\n", stackPop(stack));


    stackPrint(stack);
    return 0;
}