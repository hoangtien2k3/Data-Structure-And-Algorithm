
/*
    Nhập vào một số nguyên dương n, và n số nguyên lần lượt là các phần tử trong dãy a. Tiếp theo nhập vào hai số nguyên là k và x (0 ≤ k ≤ n).

Hãy chèn phần tử có giá trị x vào dãy a, ở trước phần tử có chỉ số k và sau phần tử có chỉ số k-1. In mảng kết quả ra màn hình, mỗi số cách nhau bởi một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
4
1 2 3 4
1 10

1 10 2 3 4 
Với n = 4, a = [1, 2, 3, 4], k = 1, x = 10 thì kết quả mong muốn là: "1 10 2 3 4 ".

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int *insert_Array(int n, int *arr, int k, int x) {
    for(int i = n; i >= k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    return arr;
}
/*
    giải thích: bắt đầu từ n chứ không phải n - 1
        arr[i] = arr[i - 1]
        arr[4] = arr[3] = 4
        arr[3] = arr[2] = 3
        arr[2] = arr[1] = 2
        arr[1] = arr[0] = 1
        arr[0] = 1
    nên khi ta gán arr[k] = x (cũng chính là gán arr[1] = 10)
*/


// hoặc dùng vector<int> v, dùng v.insert(v.begin() + k, x);


int main() {    
    int n;
    int k, x;

    cout << "Nhap vao n = ";
    cin  >> n;
    int arr[n + 1];
    for(int i=0; i<n; i++) {
        cout << "arr["<<i<<"] = ";
        cin >> arr[i];
    }

    do {
        cout << "Nhap vao k, x (0 <= k <= n): ";
        cin >> k >> x;
    } while(k > n);

    int *ptr = insert_Array(n, arr, k, x);
    for(int i = 0; i < n + 1; i++) {
        cout << *(ptr + i) << " ";
    }


    return 0;
}