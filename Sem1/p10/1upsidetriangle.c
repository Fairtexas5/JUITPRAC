#include<stdio.h>
int main(){
    int i, j, k ,l, n;
    printf("enter the rows:");
    scanf("%d", &n);

    for (i=1; i<=n; i++){
        for (j=1; j<=i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i=n-1; i>=1; i--){
        for (j=1; j<=i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}