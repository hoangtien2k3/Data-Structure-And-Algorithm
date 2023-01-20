
//! Interchange Sort: sap xep doi cho truc tiep: O(n^2)

#include<bits/stdc++.h>
using namespace std;

int * InterchangeSort(int *arr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {3, 7, -5, 8, 10, 2, 0, -30, 25, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    InterchangeSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

