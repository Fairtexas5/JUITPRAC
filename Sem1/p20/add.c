#include <stdio.h>
   
int main()
{

    char str1[100] = "Geeks", str2[100] = "World";
    char str3[100];
   
    int i = 0, j = 0, n=3;
   
    printf("\nFirst string: %s", str1);
    printf("\nSecond string: %s", str2);
    for(i=0;str2[i] != '\0'; i++){
        str3[j] = str2[i];
        j++;
    } 
    i=0;
    for(i=0; str1[i] != str1[n]; i++){
        str3[j] = str1[i];
        j++;
        }
    
    str3[j] = '\0';
   
    printf("\nConcatenated string: %s", str3);
   
    return 0;
}