#include <stdio.h>


int main() {
    int a[] = { 7,1,3,2,4,6 };
    int size = 6;
    int key, j;
    for (int i = 1; i < size; i++) { 
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }


    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }


    return 0;
}