#include <stdio.h>

#define MAX_ROWS 50
#define MAX_COLS 50

int main() {
    int m, n;
    int matrix[MAX_ROWS][MAX_COLS];
    int i, j, k;
    int min_in_row, max_in_col;
    int saddle_point_exists = 0; // assume saddle point does not exist initially
    
    // prompt user to enter matrix dimensions
    printf("Enter number of rows and columns of matrix (m x n): ");
    scanf("%d %d", &m, &n);
    
    // prompt user to enter matrix elements
    printf("Enter the matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // check for saddle point in each row
    for (i = 0; i < m; i++) {
        min_in_row = matrix[i][0];
        for (j = 1; j < n; j++) {
            if (matrix[i][j] < min_in_row) {
                min_in_row = matrix[i][j];
            }
        }
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == min_in_row) {
                // check if min_in_row is also the max in the column
                max_in_col = matrix[0][j];
                for (k = 1; k < m; k++) {
                    if (matrix[k][j] > max_in_col) {
                        max_in_col = matrix[k][j];
                    }
                }
                if (matrix[i][j] == max_in_col) {
                    printf("Saddle point found at (%d,%d): %d\n", i, j, matrix[i][j]);
                    saddle_point_exists = 1; // saddle point found
                }
            }
        }
    }
    
    if (!saddle_point_exists) {
        printf("Saddle point does not exist in the matrix.\n");
    }
    
    return 0;
}
