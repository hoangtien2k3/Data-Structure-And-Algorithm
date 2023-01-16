
//! Bubble Sort: thuật toán sắp xếp nổi bọt: O(n^2)

#include<bits/stdc++.h>
using namespace std;

int * SortArray(int *arr, int n) { // O(n^2)
    for(int i = 0; i < n-1; i++) {
        bool check = false;
        for(int j = n-1; j > i; j--) {
            if (arr[j-1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                check = true;
            }
        }
        if (!check) break;
    }
    return arr;
}

int main() {
    int arr[] = {3, 7, -5, 8, 10, 2, 0, -30, 25, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    SortArray(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


