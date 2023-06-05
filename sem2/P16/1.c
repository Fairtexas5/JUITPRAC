/*
An array contains the elements shown below.  What would be the value of the elements in the array after each pass of the quick sort algorithm? Also mention the pivot.
5  3  8  9  1  7  0  2  6  4 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int *arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    return;

}
int main(){
    int arr[10] = {5, 3, 8, 9, 1, 7, 0, 2, 6, 4 };
    quickSort(arr, 0, 9);
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
