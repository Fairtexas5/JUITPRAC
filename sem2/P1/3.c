#include <stdio.h>

void primeFactors(int n, int factor) {
    if (n <= 1) {
        return;
    } else if (n % factor == 0) {
        printf("%d ", factor);
        primeFactors(n / factor, factor);
    } else {
        primeFactors(n, factor+1);
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    printf("The prime factors of %d are: ", n);
    primeFactors(n, 2);
    printf("\n");
    
    return 0;
}
