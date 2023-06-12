/*
. Write a program that creates an array of 100 random integers in the range 1 to 200 and then,
 using the sequential search, searches the array 100 times using randomly generated targets
 in the same range at the end of the program, display the following statistics;
a.	the number of searches completed
b.	the number of successful searches
c.	the percentage of successful searches
d.	the average number of tests per search
to determine the average number of test per search, you need to count the number of tests for each search.
*/
#include <stdio.h>

int main(){
    int arr[100];
    int target;
    int count = 0;
    int success = 0;
    int i;

    for(i = 0; i < 100; i++){
        arr[i] = (rand() % 200) + 1;
    }

    printf("The array is: ");
    for(i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(i = 0; i < 100; i++){
        target = (rand() % 200) + 1;
        count++;
        if(arr[i] == target){
            success++;
        }
    }

    printf("The number of searches completed is: %d\n", count);
    printf("The number of successful searches is: %d\n", success);
    printf("The percentage of successful searches is: %f\n", (float)success/count);
    printf("The average number of tests per search is: %f\n", (float)count/success);
    return 0;
}