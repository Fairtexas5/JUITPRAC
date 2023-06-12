/*
. An array contains the elements shown below. 
Using the binary search algorithm, trace the steps followed to find 88.
  At each loop iteration, including the last, show the contents of first, last and mid.
18	13  17  26  44  56  88  97
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int binary_search(int arr[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {18,13,17,26,44,56,88,97};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 88;
    int index = binary_search(arr, 0, n-1, key);
    if(index == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d\n", index);
    }
    return 0;
}