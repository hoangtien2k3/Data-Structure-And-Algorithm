
//! Binary Search: thuật toán tìm kiếm nhị phân. O(log(n))
/*
    bắt buộc phải cần mảng sắp xếp tăng dần thì mới tìm kiếm được bằng BinarySearch

    6 
    5
    1 2 3 4 5 
    
    solution() => true 
*/ 


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//! dùng hàm thông thương
int BinarySearch(int arr[], int left, int right, int x) { // O(log N)
    while(left <= right) {
        int mid = (left + right) / 2; // mid = left + (left + right) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

//! dùng đệ quy
// bool BinarySearch(int arr[], int left, int right, int x) {
//     if (left >= right)
//         return false;
//     int mid = (left + right) / 2;
//     if (arr[mid] == x)
//         return true;
//     else if (arr[mid] < x)
//         return BinarySearch(arr, mid + 1, right, x);
//     else 
//         return BinarySearch(arr, left, mid - 1, x);
// }  


int main() {
    int n; cin >> n; // n phần tử
    int arr[100];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int x; cin >> x;

    int k = BinarySearch(arr, 0, n, x);
    if (k == -1) 
        cout << "Khong tim thay gia tri " << x << " trong mang!";
    else 
        cout << "Gia tri " << x << " o chi so " << k;


    return 0;
}