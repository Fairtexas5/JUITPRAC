#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    FILE *fptr;
    FILE *f;
    char str[100];
    char ch;
    fptr = fopen ("test.txt", "r");
    if (fptr == NULL){
        printf("Fucking empty!!!\n");
        exit(0);
    }
    f = fopen ( "test1.txt", "w" ) ; 
    if (f == NULL){
        printf("Fucking empty!!!\n");
        exit(0);
    }
    while ( 1 ) {
        ch = fgetc ( fptr ) ;
        if ( ch == EOF ) 
        break ;
        else
        fputc ( ch, f ) ;
        }
    return 0;
}