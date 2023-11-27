#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array {
    int* array;
    int size, used;
};


struct Array* newArray() {
    struct Array* array;
    int size = 5;
    array->array = (int*)malloc(size * sizeof(int));
    array->size = size;
    array->used = 0;
    return array;
}

int* copy_to_array(struct Array* arr1, struct Array* arr2) {
    for (int i = 0; i < arr1->size; i++) {
        arr2->array[i] = arr1->array[i];
        arr2->used = arr1->used;
    }
}


int append(struct Array* array, int value) {
    if (array->used < array->size) {
        array->array[array->used] = value;
        array->used++;
    }

    else {
        array->array = (int*)realloc(array->array, (array->used + 8) * sizeof(int));
        array->array[array->used] = value;
        array->size = array->used + 8;
        array->used++;
    }
}

int len(struct Array* array) {
    return array->used;
}


int main() {
    struct Array* array = newArray();
    append(array, 1);
    append(array, 2);
    append(array, 3);
    append(array, 4);
    append(array, 5);
    append(array, 6);
    int length = len(array);
    printf("%d\n", length);
    printf("%d\n", array->size);
    printf("%d\n", array->array[0]);
    printf("%d\n", array->array[1]);
    printf("%d\n", array->array[5]);
    return 0;
}
