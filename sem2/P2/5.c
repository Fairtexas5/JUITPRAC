#include <stdio.h>
#include <string.h>

void remove_char(char *str, char ch) {
    // base case: if the string is empty, return
    if (*str == '\0') {
        return;
    }
    
    // recursive case: if the current character is the specified character, shift the rest of the string to the left by one position and call the function with the new string and the same character, else call the function with the next character and the same character
    if (*str == ch) {
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            str[i] = str[i+1];
        }
        remove_char(str, ch);
    } else {
        remove_char(str+1, ch);
    }
}

int main() {
    char str[100];
    char ch;
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter a character to remove: ");
    scanf(" %c", &ch);
    
    remove_char(str, ch);
    printf("The new string with all occurrences of '%c' removed is: %s\n", ch, str);
    
    return 0;
}
