
//! Merge Sort: xắp xếp trộn: O(n long(n))
#include<bits/stdc++.h>
using namespace std;

int * merge(int *arr, int mid, int left, int right) {
    vector<int> x(arr + left, arr + mid + 1); // copy từ mảng sang vector từ vị trí arr + left -> arr + mid + 1
    vector<int> y(arr + mid + 1, arr + right + 1); // copy từ mảng sang vector
    int i = 0, j = 0;
    while(i < x.size()) {
        if (x[i] < y[j]) 
            arr[left++] = x[i++];
        else 
            arr[left++] = y[j++];
    }
    while(i < x.size())
        arr[left++] = x[i++];
    while(j < y.size())
        arr[left++] = y[j++];
    return arr;
}

int * mergeSort(int *arr, int left, int right) {
    if (left >= right) return arr;
    int mid = (left + right) / 2; // left + (right - left)/2;
    mergeSort(arr, left, mid);  
    mergeSort(arr, mid + 1, right); // recurtion
    return merge(arr, mid, left, right); 
} 

int main() {
    int arr[] = {3, 7, -5, 8, 10, 2, 0, -30, 25, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for(int x : arr) {
        cout << x << " ";
    }
    return 0;
}


