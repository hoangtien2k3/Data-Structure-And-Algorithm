
//! LinearSearch : thuật toán tìm kiếm tuyến tính: O(n)
/*
    Ex: 
        4
        1 2 3 4
        4

    => solution = 1;

*/
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int LinearSearch(int arr[], int n, int x) { // O(n)
    for(int i=0; i<n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int x; cin >> x;

    int k = LinearSearch(arr, n, x);
    if (k == -1)
        cout << "Khong tim thay gia tri " << x << " trong mang!" << endl;
    else
        cout << "Tim thay gia tri " << x << " o chi so " << k << endl;

    return 0;
}