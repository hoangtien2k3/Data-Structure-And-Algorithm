
/*
    Cho số nguyên dương n, tiếp theo là n số nguyên dương của một dãy a, cuối cùng là một số s.
    Hãy đưa ra dãy con liên tiếp đầu tiên của dãy a sao cho tổng của dãy đó bằng s. In dãy đó ra màn hình, sau mỗi phần tử có một khoảng trắng. Nếu không tồn tại dãy đó thì in ra "-1".

    Ví dụ:

    Test mẫu 1:

    Input	Output
    5
    1 2 3 4 5
    5

    2 3
    Với a = [1, 2, 3, 4, 5] và s = 5 thì kết quả mong muốn là: "2 3 ".

    Test mẫu 2:

    Input	Output
    3
    1 2 3
    4

    -1
    Với a = [1, 2, 3] và s = 4 thì kết quả mong muốn là: "-1"
*/

//! CÁCH 2: ÁP DỤNG Prefix Sum
#include<bits/stdc++.h>
using namespace std;

int Binary_Search(int *brr, int n, int x) {
    int l = 0, r = n - 1; // chỉ số phần tử đầu và cuối
    while(l < r) {
        int mid = (l + r)/2;
        if (brr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (brr[l] == x) return l;
    return -1;
}

void PrintResult(int *arr, int n, int l, int r) {
    for(int i=l; i<=r; i++) {
        cout << arr[i] << " ";
    }
}

bool solution(int *arr, int *brr, int n, int s) {

    brr[0] = arr[0]; // phần tử đầu tiên brr[0] = arr[0]
    for(int i = 1; i <= n; i++)
        brr[i] = brr[i-1] + arr[i];

    for(int i = 0; i < n; i++) {
        if (brr[i] == s) {
            PrintResult(arr, n, 0, i);
            return true;
        } else if (brr[i] > s) {
            int l = Binary_Search(brr, n, brr[i] - s); 
            /*
                ! vì sao lại là ( brr[i] - s )
                ! VD: 1 + 2 + 3 = 6 mà số cân tìm lại là 5
                    thì ta lấy 6 - 5 = 1, nếu trong Prefix Sum của mảng brr có phần tử bằng 1
                    thì ta chỉ cần in ra kết quả từ chỉ số đó + 1 đến i
            */

            if (l != -1) {
                PrintResult(arr, n, l + 1, i);
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, s;
    cin >> n;
    int arr[n], brr[n] = {0}
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> s;
    if (!solution(arr, brr, n, s)) cout << "-1";

    return 0;
}




//! /////////////////////////


// #include <bits/stdc++.h>
// using namespace std;

// //! CÁCH 1: giải thông thường
// void Search(int arr[], int n, int s) {
//     int sum = 0;
//     bool check = false;
//     for (int i = 0; i < n; i++) {
//         sum = arr[i];
//         for (int j = i + 1; j < n; j++) {
//             sum += arr[j];
//             if (sum == s) {
//                 for (int k = i; k <= j; k++) {
//                     cout << arr[k] << " ";
//                     check = true;
//                 }
//                 break;
//             }
//         }
//         if (check) break;
//     }
//     if (!check) cout << -1;
// }

// int main()
// {
//     int s, n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     cin >> s;
//     Search(arr, n, s);
//     return 0;
// }






