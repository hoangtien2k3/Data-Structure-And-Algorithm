
//! Dynamic Programing
/*
    + Quy hoạch động (dynamic programing) là phương pháp thường được áp dụng để giải 
    các bài toán toàn cục bằng cách chia chúng thành các bài toán con đơn giản hơn.

    + Đối với dạng bài toán, độ phức tạp thường sẽ là O(n). Tuy nhiên, chúng ta có thể 
    sử dụng một số biện pháp để giảm độ phức tạp, cũng như giảm thời gian chạy.

    + Cách thứ hai đó là lưu trữ lại đáp án của các bài toán con (memoization), 
    nhằm hạn chế việc tính toán.
    Chúng ta sẽ có hai hướng tiếp cận chính:
        + (top-down) là hướng tiếp cận mà chúng ta sẽ bắt đầu từ bài toán phức tạp
        +  (bottom-up) là hướng tiếp cận mà chúng ta sẽ giải các bài toán con cần thiết 
        trước khi tiếp xúc với bài toán phức tạp.

*/

/*
    ! SỰ KHÁC NHAU GIỮA QUY HOẠCH ĐỘNG VÀ CHIA ĐỂ TRỊ:
    - Hai điểm khác nhau khá rõ giữa Quy hoạch động và Chia để trị. 
        + Đầu tiên, chia để trị chỉ xử lý bài toán theo chiều từ trên xuống (top-down) 
        + trong khi quy hoạch động hỗ trợ cả hai chiều (top-down và bottom-up)

*/

#include <iostream>
using namespace std;

int QHD(int n) {
    int a[n + 1];
    a[0] = 0; a[1] = 1; a[2] = 1;
    for(int i = 3; i <= n; i++){
        a[i] = a[i - 1] + a[i - 2];// công thức truy hồi quy hoạch động 
    }
    return a[n]; //Trả về kết quả cho hàm quy hoạch
}

 
int main() {
    int n;
    cout << "Nhap n: "; cin >> n;
    cout << "Fibonacci thu n la: " << QHD(n);
    return 0;
}

