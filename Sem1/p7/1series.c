#include<stdio.h>
int main()
{
	int j;
	float i,fact, sum=0, term;
	for(i=1;i<=7;i++)
	{
		fact=i;
		for(j=1;j<i;j++)
			fact=fact*j;
			
		term=i/fact;
		sum=sum+term;
	}
    printf("sum of the terms is %f", sum);
}