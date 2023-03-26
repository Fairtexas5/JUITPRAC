#include<stdio.h>
int main()
{
    int a=0, num, res, n, flag=0, i;
    while(a!=4)
    {
        printf("\n1. Factorial of a number\n2. Prime or not\n3. Odd or even\n4. Exit\n");

        printf("\nEnter your choice:");
        scanf("%d", &a);

        switch(a)
        {
            //Facorial 
            case 1:
     
                printf("Enter an integer: ");
                scanf("%d", &num);
                n=num;
                res=num;
                while(num>1)
                {
                    res = res*(num-1);
                    num = num-1;
                }
                printf("\nFactorial of %d is %d. \n\n",n, res);
                break;

            //prime
            case 2:

                printf("Enter an integer: ");
                scanf("%d", &num);
                n=num;

                for(i=2;i<=n/2;i++)
                {
                    if(num%i==0)
                    {
                        flag=1;
                        break;
                    }
                }

                //Prime
                if(num==1)
                    printf("\n1 is neither prime nor composite");
                else
                {
                        if(flag==0)
                            printf("\n%d is Prime Number.\n\n", n);
                        else
                            printf("\n%d is not a Prime Number.\n\n", n);
                }
                break;

            //Odd||Even
            case 3:

                printf("Enter an integer: ");
                scanf("%d", &num);
                n=num;

                if(num%2==0)
                    printf("\n%d is Even Number.\n\n",n);
                else
                    printf("\n%d is Odd Number.\n\n",n);
                break;

            case 4:
                printf("\nExit");
                break;
        }
    }
}