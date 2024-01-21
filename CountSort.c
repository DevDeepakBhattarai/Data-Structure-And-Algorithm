// This is an algo which is very impractical but is the fastest one of them all.
// Steps:
// Find the largest element
// Make an array whose length is equal to the largest element and initialize it as zeros
// Iterate through the main array and increment the value in the made array at the index which is equal to the current element in the main array.
// Iterate through the made array and copy the index of it to the main array if value > 0 . To get sorted array.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ArrayMax(int A[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n;i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[], int n) {
    int max = ArrayMax(A, n);
    int j = 0;
    int* B = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) {
        B[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        B[A[i]]++;
    }

    int i = 0;
    while (j <= max) {
        if (B[j] > 0) {
            A[i] = j;
            i++;
            B[j]--;
        }
        if (B[j] == 0) {
            j++;
        }
    }



}

int main() {
    int A[] = { 2,1,5,1,0,3 };
    int n = 6;

    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }


    CountSort(A, n);
    printf("Sorted Array\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}