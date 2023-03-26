#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end);

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str, 0, strlen(str) - 1)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}

int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1; // base case: single character or empty string
    }
    if (str[start] != str[end]) {
        return 0; // base case: characters don't match
    }
    return isPalindrome(str, start + 1, end - 1); // recursive call with the next characters
}
