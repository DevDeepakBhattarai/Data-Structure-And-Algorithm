#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv[]) {
    int* ptr = (int*)malloc(sizeof(int));
    int i = 7;
    ptr = &i;
    int* temp = ptr;
    free(ptr);
    printf("%d", *temp);
    // printf("%d", sizeof("HEllo"));
    return 0;
}