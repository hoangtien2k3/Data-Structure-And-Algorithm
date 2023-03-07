
//! SelectionSort: sap xep chon: O(n^2)
#include<bits/stdc++.h>
using namespace std;

int * SelectionSort(int *arr, int n) {
    int indexMin;
    for(int i = 0; i < n - 1; i++) {
        indexMin = i;
        for(int j = i + 1; j < n; j++) {
            if (arr[indexMin] > arr[j]) {
                indexMin = j;
            }
        }
        if (i != indexMin) {
            int temp = arr[i];
            arr[i] = arr[indexMin];
            arr[indexMin] = temp;
        }
    }
    return arr;
}

int main() {
    int arr[] = {3, 7, -5, 8, 10, 2, 0, -30, 25, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}


