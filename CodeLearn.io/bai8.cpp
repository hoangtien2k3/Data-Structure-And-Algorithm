
/*
    Cho số nguyên n, hãy tính tổng các số nguyên tố nhỏ hơn hoặc bằng n
    Bởi vì tổng các số nguyên tố nhỏ hơn hoặc bằng n có thể rất lớn, nên hãy trả ra kết quả của tổng trên dưới dạng là số dư trong phép chia của tổng trên cho 22082018.
    Example
    Với n = 2 thì primeSum(n) = 2
    Với n = 3 thì primeSum(n) = 5
    Đầu vào/Đầu ra:
    [Thời gian chạy] 0.5 giây
    [Đầu vào] integer n
    -10^7 < n < 10^7 
    [Đầu ra] integer
    Gợi ý:
    Kiểm tra và tính tổng các số nguyên tố từ 1 tới n có thể tốn nhiều thời gian
    Để tăng tốc tìm các số nguyên tố, có thể sử dụng sàng Eratosthenes
*/

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

#define max 100000001
bool arr[max];

void sangnguyento(int n){
    for (int i = 2; i <= n; i++) {
        arr[i] = 1;
    }
    arr[0] = arr[1] = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (arr[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }
}

int primeSum(int n)
{
    int mod = 22082018;
    int sum = 0;
    sangnguyento(n);
    for (int i = 2; i <= n; i++)
        if (arr[i]) 
            sum = (sum + i % mod) % mod;
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << primeSum(n);
    return 0;
}