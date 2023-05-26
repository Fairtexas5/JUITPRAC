#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main() {
    
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    // Perform three more passes of bubble sort
    for (int pass = 0; pass < 3; pass++) {
        for (int i = n - 1; i > pass; i--) {
            if (arr[i] < arr[i - 1]) {
                // Swap the elements
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
