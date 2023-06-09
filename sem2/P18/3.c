/*
Write a c program to sort the following sequence by using heap sort.
     10, 5, 70, 15, 12, 35, 50
*/
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] > arr[largest])
        largest = l;
    if(r < n && arr[r] > arr[largest])
        largest = r;
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = n - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int arr[] = {10, 5, 70, 15, 12, 35, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
/*
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/