#include <stdio.h>

void mergeArrays(int arr1[], int arr2[], int size1, int size2) {
    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k] = arr1[i];
            i++;
        } else {
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        mergedArray[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        mergedArray[k] = arr2[j];
        j++;
        k++;
    }

    // Display the result after each merge phase
    printf("Result after each merge phase:\n");
    for (int m = 0; m < mergedSize; m++) {
        printf("%d ", mergedArray[m]);
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Perform the merge
    mergeArrays(arr1, arr2, size1, size2);

    return 0;
}
