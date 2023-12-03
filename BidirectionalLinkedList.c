#include <stdio.h>  
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct LinkedList {
    Node* head;
    int length;
}LinkedList;


LinkedList* linkedListCreate() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->length = 0;
    return list;
}


void linkedListPrint(LinkedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("The List is empty\n");
        return;
    }
    while (current != NULL) {
        {
            if (current->prev != NULL && current->next != NULL)
                printf("Current Data : %d \t Prev Data : %d \t Next Data : %d \n", current->data, current->prev->data, current->next->data);
                // printf("%d\t", current->data);/
            current = current->next;
        }

    }

}
void append(LinkedList* list, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->length++;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        node->prev = current;
        list->length++;
    }
}

void linkedListInsert(LinkedList* list, int value, int position) {
    if (position > list->length) {
        printf("Cannot Insert %d at position %d\n", value, position);
        return;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->prev = NULL;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->length++;
        //* Fro insertion in first position
    } else if (position == 0) {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
        //* For insertion in last position
    } else if (position == list->length) {
        Node* current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        node->prev = current;
        current->next = node;
        list->length++;
    } else {
        Node* current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        current->next->prev = node;
        node->next = current->next;
        node->prev = current;
        current->next = node;
        list->length++;
    }
}

int main() {
    LinkedList* list = linkedListCreate();
    append(list, 5);
    append(list, 4);
    append(list, 6);
    append(list, 7);
    linkedListInsert(list, 8, 4);
    printf("\nLength is : %d\n", list->length);
    linkedListPrint(list);
    printf("\nLength is : %d\n", list->length);
    free(list);
    return 0;

    return 0;
}