#include <stdio.h>

int string_to_int(char *str, int len) {
    // base case: if the string is empty, return 0
    if (len == 0) {
        return 0;
    }
    
    // recursive case: convert the last digit to an integer and add it to the integer value of the rest of the string
    int digit = str[len-1] - '0';
    return digit + 10 * string_to_int(str, len-1);
}

int main() {
    char str[100];
    printf("Enter a string of numerals: ");
    scanf("%s", str);
    
    int len = strlen(str);
    int num = string_to_int(str, len);
    printf("The string \"%s\" converted to an integer is %d.\n", str, num);
    
    return 0;
}
