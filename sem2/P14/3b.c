#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, maxIndex;

    for (i = 0; i < n - 1; i++) {
        maxIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) // Compare with '>' for descending order
                maxIndex = j;
        }

        swap(&arr[i], &arr[maxIndex]);
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    selectionSort(arr, n);

    printf("\nSorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
