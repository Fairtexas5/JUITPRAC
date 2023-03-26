#include <stdio.h>

void int_to_bin(int num) {
    // base case: if the number is 0, return
    if (num == 0) {
        return;
    }
    
    // recursive case: divide the number by 2 and call the function with the quotient, then print the remainder
    int quotient = num / 2;
    int remainder = num % 2;
    int_to_bin(quotient);
    printf("%d", remainder);
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    printf("The binary representation of %d is: ", num);
    int_to_bin(num);
    printf("\n");
    
    return 0;
}
