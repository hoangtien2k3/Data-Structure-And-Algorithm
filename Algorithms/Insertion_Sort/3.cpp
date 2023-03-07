
#include<stdio.h>
#include<math.h>

void insertionSort(int arr[], int length) {
    int i, j, temp;
    for (int i=1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}


int main() {
    int arr[] = {4, 2, 8, 3, 9, 5, 10, 6, 1, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, length);
    for(int i=0; i<length; i++) {
        printf ("%d ", arr[i]);
    }
}

