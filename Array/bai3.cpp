
/*
    Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a.
Hãy thay đổi giá trị của mỗi phần tử thành bình phương của chính nó, sau đó in mảng đó ra màn hình (mỗi phần tử cách nhau bởi một khoảng trắng).

Test mẫu 2:

Input	Input
4
1 2 3 4

1 4 9 16 
Với n = 4 và a = [1, 2, 3, 4] thì kết quả mong muốn là: "1 4 9 16 ".

*/

#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int *binhPhuong(int n, int *arr) {
    for(int i=0; i<n; i++) {
        *(arr + i) = pow(*(arr + i), 2);
    }
    return arr;
}

int main() {
    int n;
    cout << "Nhap vao n = ";
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cout << "arr["<<i<<"] = ";
        cin >> arr[i];
    }

    int *ptr = binhPhuong(n, arr);
    for(int i=0; i<n; i++) {
        cout << *(ptr + i) << " ";
    }

    return 0;
}