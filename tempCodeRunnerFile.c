int main() {
    int A[10] = { 55,5,3,4,9,8,7 ,1,3,55 };
    int n = 10;

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
