#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) { // Compare with '<' for descending order
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
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

    insertionSort(arr, n);

    printf("\nSorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
