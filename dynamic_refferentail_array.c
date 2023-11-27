#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    INT,
    STRING,
    FLOAT,
    DOUBLE,
} Datatypes;

typedef struct Array {
    void** array;
    int size, used;

    int* integer;
    float* floatingPoint;
    double* longFloatingPoint;
    char* string;
}Array;


Array* newArray() {
    Array* array;
    int size = 5;
    array->array = malloc(size * sizeof(void*));
    array->size = size;
    array->integer = NULL;
    array->floatingPoint = NULL;
    array->longFloatingPoint = NULL;
    array->string = NULL;
    array->used = 0;
    return array;
}

int* copy_to_array(Array* arr1, Array* arr2) {
    for (int i = 0; i < arr1->size; i++) {
        arr2->array[i] = arr1->array[i];
        arr2->used = arr1->used;
    }
}

void initialize_array(void* array, int size, Datatypes type) {
    int effective_size = 0;
    switch (type) {
        {
        case INT:
            effective_size = size * sizeof(int);
            array = (int*)malloc(effective_size);
            break;
        case DOUBLE:
            effective_size = size * sizeof(DOUBLE);
            array = (double*)malloc(effective_size);
            break;

        case STRING:
            effective_size = size * sizeof(char);
            array = (char*)malloc(effective_size);
            break;
        case FLOAT:
            effective_size = size * sizeof(float);
            array = (float*)malloc(effective_size);
            break;
        default:
            break;
            printf("No such datatypes");
        }
    }

    void append(Array * array, void* value, Datatypes type) {
        if (array->used < array->size) {
            switch (type) {
                case INT:
                    initialize_array(array->integer, 4, INT);
                    break;
                case DOUBLE:
                    initialize_array(array->longFloatingPoint, 4, DOUBLE);
                    break;
                case FLOAT:
                    initialize_array(array->floatingPoint, 4, FLOAT);
                    break;
                case STRING:
                    initialize_array(array->string, 4, STRING);
                    break;
                default:
                    break;
            }

        }

        if (array->used < array->size) {
            array->integer[array->used] = value;
            array->array[array->used] = &array->integer[array->used];
            array->used++;
        }

        else {
            array->array = realloc(array->array, (array->used + 8) * sizeof(int));
            array->integer = (int*)realloc(array->integer, (array->used + 8) * sizeof(int));
            array->integer[array->used] = value;
            array->array[array->used] = &array->integer[array->used];
            array->size = array->used + 8;
            array->used++;
        }
    }

    int len(Array * array) {
        return array->used;
    }


    int main() {
        Array* array = newArray();
        printf("%d", sizeof(array));
        // append(array, "Hello");
        int a = 3;
        append(array, &a, INT);
        // append(array, 4);
        // append(array, 5);
        // append(array, 6);
        printf("%d\n", len(array));
        printf("%d\n", array->size);
        printf("%d\n", *(int*)array->array[0]);
        printf("%d", sizeof(array));

        // printf("%d\n", array->array[1]);
        // printf("%d\n", array->array[5]);
        return 0;
    }
