#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse(char *str)
{
   if (*str)
   {
       reverse(str+1);
       printf("%c", *str);
   }
}

int main()
{
   char s;
   scanf("%[^\n]%*c",&s);
   reverse(&s);
   return 0;
}