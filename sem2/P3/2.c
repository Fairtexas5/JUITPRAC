#include <stdio.h>

#define MAX_SIZE 50

int isSymmetric(int a[][MAX_SIZE], int n);

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int n, i, j;
    
    // prompt user to enter matrix dimensions
    printf("Enter size of square matrix: ");
    scanf("%d", &n);
    
    // prompt user to enter matrix elements
    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    // check if matrix is symmetric
    if (isSymmetric(a, n)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }
    
    return 0;
}

int isSymmetric(int a[][MAX_SIZE], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                // if any element is not equal to its corresponding symmetric element
                // then matrix is not symmetric
                return 0;
            }
        }
    }
    // if all elements are equal to their corresponding symmetric elements
    // then matrix is symmetric
    return 1;
}
