#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int search(int*, int, int, int);
int main() {
    srand(time(0));
    int array[] = { 2, 8, 17, 37, 98, 220, 550, 667 }, usedSize = 0;
    int element;

    printf("Enter the number you want to search: ");
    scanf("%d", &element);
    int index = search(array, 7, 0, element);
    // printf("%d", index);
    return 0;
}

int search(int* arr, int maxSize, int minSize, int element) {
    int indexOfTheMiddle = (maxSize + minSize) / 2;
    int midValue = arr[indexOfTheMiddle];

    if (midValue == element) {
        return indexOfTheMiddle;
    } else if (midValue < element) {
        minSize = indexOfTheMiddle;
        indexOfTheMiddle = search(arr, maxSize, minSize, element);
    } else if (midValue > element) {
        maxSize = indexOfTheMiddle;
        indexOfTheMiddle = search(arr, maxSize, minSize, element);
    } else if (maxSize == minSize && (arr[indexOfTheMiddle] != element)) {
        printf("Cannot find the element in the array");
    }
}