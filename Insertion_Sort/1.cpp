
// Insertion sort : sắp xếp chèn

#include <stdio.h>
#include <math.h>

// giảm dần
void insertionSort(int arr[], int n) {
    int index, value;   
    for (int i = 1; i < n; i++) {   
        index = i;
        value = arr[i];
        while (index > 0 && arr[index - 1] < value) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }
}

/* Hàm xuất mảng */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}


