#include<stdio.h>
int main(){
    int n, t, od=0, ev=0, i, j;
    scanf("  %d", &n);
    printf("ODD               EVEN\n");
    i=1;
    while (i<=n){
        if (i%2==0){
            printf("  %d                 %d\n", i-1, i);
            i=i+2;
        }
        else
        i=i+1;
    }

    printf("  --------------------\n");
    while (n>0){
        if (n%2==0){
            ev = ev + n;
        }
        else {
            od = od + n;
        }
        n--;
    }
    printf("  %d                %d", od, ev);
}