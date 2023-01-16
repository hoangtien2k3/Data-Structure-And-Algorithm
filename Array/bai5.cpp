
/*
    Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Tiếp theo nhập vào số nguyên là k (0 ≤ k < n).

Hãy xóa phần tử có chỉ số k ở trong dãy đó. In mảng kết quả ra màn hình, sau mỗi phần tử có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
4
1 2 3 4
1

1 3 4
Với n = 4, a = [1, 2, 3, 4], k = 1, thì kết quả mong muốn là: "1 3 4 ".


*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int *pop_Array(int n, int *arr, int k) {
    for(int i=k; i<n; i++) {
        arr[i] = arr[i + 1];
    }
    return arr;
}

// vector<int> v, v.erase(v.begin() + k, 1);

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    int *ptr = pop_Array(n, arr, k);
    for(int i=0; i< n - 1; i++) {
        cout << ptr[i] << " ";
    }
}
