#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
int main() {
    int rows = 5;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j % 2 == 0) {
                printf("%d ", (1 + (j * rows - ((j - 1) * j / 2) + i - j)));
            } else {
                printf("%d ", (1 + (j * rows - ((j - 1) * j / 2) + rows - 1 - i)));
            }
        }
        printf("\n");
    }
    return 0;
}

