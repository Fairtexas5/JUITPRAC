#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_palindrome(char *str, int start, int end) {
    // base case: if the start index is greater than the end index, the string is a palindrome
    if (start >= end) {
        return 1;
    }
    
    // recursive case: compare the characters at the start and end indices, ignoring case and spacing
    char c1 = tolower(str[start]);
    char c2 = tolower(str[end]);
    if (!isalnum(c1)) {
        return is_palindrome(str, start+1, end);
    } else if (!isalnum(c2)) {
        return is_palindrome(str, start, end-1);
    } else if (c1 == c2) {
        return is_palindrome(str, start+1, end-1);
    } else {
        return 0;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // remove the newline character
    
    if (is_palindrome(str, 0, strlen(str)-1)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }
    
    return 0;
}
