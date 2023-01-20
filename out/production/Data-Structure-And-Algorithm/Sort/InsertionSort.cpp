
//! Insertion Sort: thuat toan sap xep chen: O(n^2)

#include<bits/stdc++.h>
using namespace std;

int *InsertionSort(int *arr, int n) {
    int index, value;
    for(int i = 1; i < n; i++) {
        index = i;
        value = arr[i];
        while(index > 0 && value < arr[index - 1]) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }
    return arr;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) 
        cin >> a[i];
    InsertionSort(a, n);
    for(int i=0; i<n; i++) 
        cout << a[i] << " ";

    return 0;
}

