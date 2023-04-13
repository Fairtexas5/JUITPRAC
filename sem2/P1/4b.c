#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}

// Function to calculate the sum of the series using recursion
double sum(int n) {
    if (n == 1) {
        return 1.0;
    }
    return sum(n-1) + ((double)n/factorial(n));
}

int main() {
    int n;
    scanf("%d", &n);

    // Calculate the sum of the series
    double result = sum(n);

    // Display the result
    printf("%.2lf\n", result);

    return 0;
}
