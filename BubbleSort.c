#include <stdio.h>

int main() {
    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int temp;
    int isSorted = 0; // To make the algorithm adaptive we use the isSorted flag
    for (int i = 0; i < 9; i++) {
        isSorted = 1; // We assume the array is sorted in each iteration
        printf("Working on index %d\n", i + 1);
        for (int j = i + 1; j < 10; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                isSorted = 0; // Flagging that the array is not sorted 
            }
        }
        if (isSorted)
            break;
    }
    for (int i = 0;i < 10;i++) {
        printf("%d ", a[i]);
    }
    return 0;
}