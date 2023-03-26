#include<stdio.h>
int main()
{
	int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("HOT");
			break;
			case 2:
			printf("LUKE WARM");
			break;
			case 3:
			printf("COLD");
			break;
			default:
			printf("OUT OF RANGE");
		}
	return 0;
}