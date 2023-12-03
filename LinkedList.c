#include <stdio.h>

#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
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
            printf("%d\t", current->data);
            current = current->next;
        }


    }
}

void append(LinkedList* list, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->length++;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
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
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->length++;
    } else if (position == 0) {
        node->next = list->head;
        list->head = node;
    } else {
        Node* current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        list->length++;
    }
}


void linkedListDelete(LinkedList* list, int position) {
    if (list->head == NULL) {
        printf("Operation not allowed \n");
        return;
    }
    if (position == 0) {
        Node* current = list->head;
        list->head = current->next;
        free(current);
        list->length--;
    } else if (position + 1 == list->length) {
        Node* current = list->head;

        for (int i = 0;i < position - 1; i++) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        list->length--;
    } else {
        Node* current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node* elementToDelete = current->next;
        current->next = current->next->next;
        free(elementToDelete);
        list->length--;
    }

}


int main() {
    LinkedList* list = linkedListCreate();
    append(list, 5);
    append(list, 4);
    append(list, 6);
    append(list, 7);
    linkedListInsert(list, 8, 4);
    // printf("\nLength is : %d\n", list->length);
    // linkedListDelete(list, 3);
    linkedListPrint(list);
    printf("\nLength is : %d\n", list->length);
    free(list);
    return 0;
}