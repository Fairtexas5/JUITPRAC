#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    FILE *fptr;
    char str[100];
    char fame[20] = "test.txt";
    fptr = fopen (fame, "w");
    if (fptr == NULL){
        printf("Fucking empty!!!\n");
        exit(0);
    }
    printf ("Input: ");
    scanf("%[^\n]%*c", str);
    fprintf(fptr, "%s", str);
    fclose(fptr);
    return 0;
}
