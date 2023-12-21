#include <stdio.h>
#include <stdlib.h>

int partition(int* A, int low, int high) {
    int i = low + 1, j = high, temp;
    int pivot = A[low];

    do {

        // This i <=high is so that we don't go out of array index .
        //if we don't want to use this i<=high we have make n+1 length array and put infinity as the last element there
        while (i <= high && A[i] <= pivot) {
            i++;
        }

        // Here we are finding element <=pivot so if we have the smallest element in the first . j will just stop there. as we have equal and not go outside of the array.
        while (A[j] > pivot) {
            j--;
        }



        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (j >= i);

    temp = A[j];
    A[j] = A[low];
    A[low] = temp;

    return j;
}


void QuickSort(int* A, int low, int high) {
    if (low < high) {
        int position = partition(A, low, high);
        QuickSort(A, position + 1, high);
        QuickSort(A, low, position - 1);
    }
}
int main() {
    int A[5] = { 2,1,5,0,3 };
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
