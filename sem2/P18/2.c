// Write a function to delete an item at index i from Heap

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
void deleteAtIndex(int arr[], int* n, int i) {
    if(i >= *n)
        return;
    swap(&arr[0], &arr[i]);
    *n -= 1;
    heapify(arr, *n, 0);
}
void printHeap(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printHeap(arr, n);
    deleteAtIndex(arr, &n, 0);
    printHeap(arr, n);
    return 0;
}
// Time Complexity: O(n)

