#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    FILE *fp;
    char ch;
    int size = 0;
 
    fp = fopen("test1.txt", "r");
    if (fp == NULL)
        printf("\nFile unable to open ");
    else 
        printf("\nFile opened ");
    fseek(fp, 0, 2);    /* file pointer at the end of file */
    size = ftell(fp);   /* take a position of file pointer un size variable */
    printf("The size of given file is : %d\n", size);    
    fclose(fp);
    
    return 0;
}