#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10] = { 5,6,7,3,9,8,1,6,2,0 };
    int i = 0, j = 0;
    int smallest = 0;
    int temp;
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10;j++) {
            if (arr[smallest] > arr[j]) {
                smallest = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }



    return 0;
}