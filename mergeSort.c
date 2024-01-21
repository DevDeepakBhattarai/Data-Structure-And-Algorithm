#include <stdio.h>
#include <stdlib.h>

void merge(int* A, int low, int high, int mid) {
    int* B = (int*)malloc(((high - low) + 1) * sizeof(int)); // High - low +1 makes the minimum size array.

    int i, j, k = 0; // if k = low; then we dont have to use A[i]= B[i-low] when copying element back to array A.
    i = low;
    j = mid + 1;

    while ((i <= mid) && (j <= high)) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            k++;
            i++;
        } else {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high) {
        B[k] = A[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++) {
        A[i] = B[i - low]; // We use B[i-low] because. When we have for example low=3 and high=4 , during the second last step of the tree i.e we combine |3| & |0| to make |0,3| ( <--this is B) we wont have the index 3 available to us. So we need to offset it . 
    }

    free(B);
}


void MergeSort(int* A, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        merge(A, low, high, mid);
    }
}

int main() {
    int A[5] = { 2,1,5,0,3 };
    int n = 5;

    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }


    MergeSort(A, 0, n - 1);
    printf("Sorted Array\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}