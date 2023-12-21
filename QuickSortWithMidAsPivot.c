
#include <stdio.h>
#include <stdlib.h>

int partition(int* A, int low, int high) {
    int mid = low + (high - low) / 2; // We are using this formula to get mid value because ,if the length is big. low+high will exceed the integer limit

    int pivot = A[mid];
    int i = low - 1;
    int j = high + 1;
    int temp;

    do {
        do {
            i++;
        } while (pivot > A[i] && i <= high);

        do {
            j--;
        } while (pivot < A[j]);

        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        printf("Index: %d:%d\t", i, j);
    } while (i < j);
    return j;
}

void QuickSort(int* A, int low, int high) {
    if (low < high) {
        int position = partition(A, low, high);
        QuickSort(A, position + 1, high);
        QuickSort(A, low, position);
    }
}

int main() {
    int A[5] = { 2,1,5,4,3 };
    int n = 5;

    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }


    QuickSort(A, 0, n - 1);
    printf("Sorted Array\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }


    return 0;
}
