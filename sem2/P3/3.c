#include <stdio.h>
#include <string.h>

char *removeLeadingSpaces(char *str) {
    int i, j;
    for (i = 0; str[i] == ' '; i++) {} // Traverse the string until a non-space character is encountered
    if (i > 0) { // If leading spaces were found
        j = 0;
        while (str[i] != '\0') { // Copy the rest of the string to the beginning of the array
            str[j] = str[i];
            i++;
            j++;
        }
        str[j] = '\0'; // Add null terminator to the end of the new string
    }
    return str;
}

int main() {
    char str[100];
    printf("Enter a string with leading spaces: ");
    fgets(str, sizeof(str), stdin);
    printf("Original string: %s", str);
    removeLeadingSpaces(str);
    printf("String after removing leading spaces: %s", str);
    return 0;
}
