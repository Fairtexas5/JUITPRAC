#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *f1, *f2, *fp;
	char ch1 = 'a', ch2 = 'a';
	f1 = fopen("File (e)1.txt", "r");
	f2 = fopen("File (e)2.txt", "r");
	fp = fopen("File (e)3.txt", "w");

	if (f1 == NULL)
	{
		printf("Can't open the file1\n");
		exit(1);
	}
	if (f2 == NULL)
	{
		printf("Can't open the file1\n");
		exit(2);
	}

	puts("\nWork on progress\n.\n.\n.\n.\n");
	
	while (1)
	{
		if (ch1 != EOF)
		{
			ch1 = fgetc(f1);
			/*A line is ends when a . is encounter*/
			while (ch1 != '.')
			{
				if (ch1 == EOF)
					break;
				fputc(ch1, fp);
				ch1 = fgetc(f1);
			}
			if (ch1 != EOF)
				fputc('.', fp);
		}
		if (ch2 != EOF)
		{
			ch2 = fgetc(f2);
			/*A line is ends when a . is encounter*/
			while (ch2 != '.')
			{
				if (ch2 == EOF)
					break;
				fputc(ch2, fp);
				ch2 = fgetc(f2);
			}
			if (ch2 != EOF)
				fputc('.', fp);
		}
		/*Getting out of the loop after end of both files*/
		if (ch1 == EOF && ch2 == EOF)
			break;
	}
	printf("\nTask completed.\nExiting . . . \n");
	return 0;
}