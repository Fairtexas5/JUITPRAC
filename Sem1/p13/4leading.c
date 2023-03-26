#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void leading_digit(int x) {
    int d=0;
    while (x > 0) {
        d = x % 10;
        x /= 10;
    }
    printf("The leading digit is %d", d);
}


int main() {
    int x, d;
    printf("Enter a positive number: ");
    scanf("%d", &x);
    leading_digit(x);
    
    return 0;
}