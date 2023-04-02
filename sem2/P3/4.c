#include <stdio.h>
#include <string.h>

void concat(char str1[], char str2[], int n) {
    strncat(str1, str2, n); // concatenate first n characters of str1 to str2
}

int main() {
    char str1[100], str2[100];
    int n;

    printf("Enter first string: ");
    scanf("%[^\n]s", str1);
    getchar(); // consume newline character

    printf("Enter second string: ");
    scanf("%[^\n]s", str2);
    getchar(); // consume newline character

    printf("Enter the value of n: ");
    scanf("%d", &n);

    concat(str1, str2, n);

    printf("Concatenated string: %s\n", str1);

    return 0;
}
