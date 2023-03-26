#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    int as;
    char c;
    printf("Enter character ");
    scanf("%c", &c);
    as = c;

    if (as >=65 && as<=90)
    {
        printf("%c is an UPPER case letter", c);
    }
    if (as >=97 && as<=122)
    {
        printf("%c is a lower case letter", c);
    }if (as >=48 && as<=57)
    {
        printf("%c is a digit", c);
    }if (as >=0 && as<=47 || as >=58 && as<=64 || as >=91 && as<=96 || as >=123 && as<=127)
    {
        printf("%c is a special character", c);
    }

    return 0;
}