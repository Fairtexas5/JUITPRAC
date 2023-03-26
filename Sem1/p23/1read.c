#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int i = 1;
	char ch;
	fp = fopen("test1.txt", "r+");
	if (fp == NULL)
	{
		puts("\nFile can't be open");
		exit(1);
	}
	printf("%d. ", i);
	i++;
	do
	{
		ch = fgetc(fp);
		if (ch == '.')
		{
			printf("%c", ch);
			

			
			printf("\n%d.", i);

			i++;
			continue;
		}
		printf("%c", ch);
	} while (ch != EOF);
	fclose(fp);

	return 0;
}