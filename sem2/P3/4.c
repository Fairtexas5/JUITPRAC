#include <stdio.h>
#include <string.h>

void concatN(char dest[], char src[], int n);

int main() {
    char dest[100] = "Hello";
    char src[100] = "World";
    int n = 3;
    
    concatN(dest, src, n);
    printf("Result: %s\n", dest);
    
    return 0;
}

void concatN(char dest[], char src[], int n) {
    strncat(dest, src, n);
}
