//Part a

#include<stdio.h>
int main(){
    int n, i, j;

    scanf("%d", &n);

    for (i=1; i<=n;i++){
        for (j=1; j<=i;j++){
            printf("%d ", i);
        }
        printf("\n");
    }

}


//Part b
#include<stdio.h>
int main()  
{  
 
    int x, space, rows, y ;  
    scanf ("%d", &rows); 
    
    if (rows>=1 && rows<=10){
    for ( x =1; x <= rows; x++)  
    {
        for ( space = 1; space <= rows - x; space++)  
        {  
            printf (" "); 
        }  
        for ( y = 1; y <=x; y++)  
        {  
            printf ("%d ",x);
        }  
        printf ("\n");  
    }
    }
    else printf("Outside the range");
    return 0;  
} 
