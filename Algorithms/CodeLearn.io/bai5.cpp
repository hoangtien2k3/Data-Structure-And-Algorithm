
/*
    Tìm chữ số khác không cuối cùng của n!(giai thừa)
    Ví dụ:
    Với n = 5, kết quả lastDigitDiffZero(n) = 2.
    5! = 1 · 2 · 3 · 4 · 5 = 120.
    Với n = 6, kết quả lastDigitDiffZero(n) = 2.
    6! =1 · 2 · 3 · 4 · 5 · 6 = 720.
    Với n = 10, kết quả lastDigitDiffZero(n) = 8.
    10! = 3628800.
    Đầu vào/Đầu ra
    [Thời gian chạy] 0.5 giây
    [input] integer n
    Điều kiện:
    1 ≤ n ≤ 10^6.
    [output] integer
    Chữ số cuối cùng khác 0 của n!
*/

#include<iostream>
#include<cmath>

int giaithua(int n) {
    if (!n || n == 1) return 1;
    return n * giaithua(n-1);
}

int lastDigitDiffZero(int n) {
    int result = giaithua(n);
    while(result % 10 == 0) 
        result /= 10;
    return result % 10;
}

// int lastDigitDiffZero(int n)
// { 
//     int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
//     int i = (int) n;

//     if (n < 10)
//         return dig[i]; 

//     if (((n/10)%10)%2 == 0)
//         return (6*lastDigitDiffZero(n/5)*dig[(int)n%10]) % 10;
//     else
//         return (4*lastDigitDiffZero(n/5)*dig[(int)n%10]) % 10;
// }

int main() {
    int n;
    std::cin >> n;
    std::cout << lastDigitDiffZero(n);
    return 0;
}