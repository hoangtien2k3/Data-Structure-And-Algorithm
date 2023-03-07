
/*
    Cho số tự nhiên n.
    Hãy tính số chữ số 0 tận cùng của n! (n! (hay còn gọi là n giai thừa) là tích các số tự nhiên liên tiếp từ 1 tới n)
    Ví dụ:
    Với n = 5, n! = 1*2*3*4*5 = 120, vì vậy numberZeroDigits(n) = 1
    Đầu ra/Đầu vào:
    Đầu vào: integer n
        1 <= n <= 10^12
    Output:
    Số chữ số 0 tận cùng của n!
    Thời gian chạy: 0.5 giây
! giải thích:
    Tại sao n>=5 bời vì bắt đầu từ 5! ta mới có
    2 số là 2 và 5 nên mới có số 0 tận cùng
    Ý tưởng là : ta lấy n chia cho 5 cho đến khi mà n không chia
    được cho 5 nữa (không quan tâm chia hết hay không chia hết)
    thì tổng kết quả của những lần chia đó sẽ là những số 0 đằng sau
    Vd ta muốn tính 100! thì ta lấy 100/5=20/5=4<5
    Số Những 0 đằng sau sẽ là 20+4;
    VD 5000! thì 5000/5=1000/5=200/5=40/5=8/5=1
    1000+200+40+8+1=1249
*/


#include<iostream>
#include<cmath>
using namespace std;

long long numberZeroDigits(long long n) {
    long long count = 0;
    while(n >= 5) {
        count += n/5;
        n /= 5;
    }
    return count;
}

int main() {
    long long n;
    cin >> n;
    cout << numberZeroDigits(n);
    return 0;
}

