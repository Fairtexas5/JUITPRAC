#include <stdio.h>
#include <stdlib.h>
int main(){
    int s, a, b, sum, sub, mul;
    float rem, div;
    printf("1. addition \n2. subtraction \n3. multiplication \n4. division \n5. remainder \n6. larger out of two\n");
    scanf("%d", &s);
    
    printf("Enter numbers (A and B): ");
    scanf("%d%d", &a, &b);

    switch(s){
        case 1:
        sum = a+b;
        printf("Addition value is %d", sum);
        break;

        case 2:
        sub = a-b;
        printf("Subtraction value is %d", abs(sub));
        break;

        case 3:
        mul = a*b;
        printf("Multilication value is %d", mul);
        break;

        case 4:
        div = a/b;
        printf("Division value is %g", div);
        break;

        case 5:
        rem = a%b;
        printf("Remainder value is %g", rem);
        break;

        case 6:
        if (a>b)
        printf("A is greater than B");

        else printf("B is greater than A");

        break;
    }
}
