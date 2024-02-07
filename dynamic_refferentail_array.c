#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    INT,
    STRING,
    FLOAT,
    DOUBLE,
    CHAR,
} Datatype;

typedef struct {
    Datatype type;
    union {
        int integer;
        float floatingPoint;
        double longFloatingPoint;
        char character;
        char* string;
    };
} pointers;

typedef struct Array {
    int size, used;
    pointers* data;
}Array;



Array* newArray() {
    int size = 5;
    Array* array = (Array*)(malloc(sizeof(Array)));
    array->data = (pointers*)(malloc(size * sizeof(pointers)));
    array->size = size;
    array->used = -1;
    return array;
}


void append(Array* array, void* value, Datatype type) {
    int intValue;
    char charValue;
    double doubleValue;
    float floatValue;
    char* string;

    if (array->used < array->size) {
        switch (type) {
            case INT:
                intValue = *(int*)(value);
                array->data[array->used + 1].integer = intValue;
                array->data[array->used + 1].type = type;
                array->used++;
                break;
            case DOUBLE:
                doubleValue = *(double*)(value);
                array->data[array->used + 1].longFloatingPoint = doubleValue;
                array->data[array->used + 1].type = type;

                array->used++;
                break;
            case FLOAT:
                floatValue = *(float*)(value);
                array->data[array->used + 1].floatingPoint = floatValue;
                array->data[array->used + 1].type = type;
                array->used++;
                break;
            case CHAR:
                charValue = *(char*)(value);
                array->data[array->used + 1].character = charValue;
                array->data[array->used + 1].type = type;
                array->used++;
                break;
            case STRING:
                string = (char*)value;
                array->data[array->used + 1].type = type;
                array->data[array->used + 1].string = string;
                array->used++;
                break;
            default:
                break;
        }
    } else {
        array->data = (pointers*)realloc((void*)array->data, (array->used + 8) * sizeof(pointers));
        array->size = array->used + 8;
        array->used++;
    }
}

int len(Array* array) {
    return array->used + 1;
}

void print(Array* array) {
    printf("[");
    for (int i = 0; i <= array->used; i++) {
        switch (array->data[i].type) {
            case INT:
                printf("%d", array->data[i].integer);
                break;
            case DOUBLE:
                printf("%lf", array->data[i].longFloatingPoint);
                break;
            case FLOAT:
                printf("%f", array->data[i].floatingPoint);
                break;
            case CHAR:
                printf("'%c'", array->data[i].character);
                break;
            case STRING:
                printf("\"%s\"", array->data[i].string);
                break;
            default:
                break;
        }
        if (i + 1 <= array->used) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main() {
    Array* array = newArray();
    int a = 5;
    char string[] = "Hello";
    char string2[] = "Deepak";
    double  dbl = 3.14159;
    char choice = 'Y';
    append(array, &string, STRING);
    append(array, &a, INT);
    append(array, &string2, STRING);
    append(array, &dbl, DOUBLE);
    append(array, &choice, CHAR);
    print(array);
    printf("Length: %d", len(array));
    return 0;
}
