/*
An array contains the elements shown below. Sort the elements by insertion sort in ascending order, what would be the value of the elements in the array after each passes of the straight insertion sort algorithm.
	3  13  7  26  44   23   98  57
*/
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    return 0;
}
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/