
/*  
    Cho biết số trang sách của 1 quyển sách:
    Hãy tìm số lượng các chữ số dùng để đánh số trang của quyển sách đó
    Ví dụ:
    Với n = 11, thì kết quả pagesNumbering(n) = 13.
    13 chữ số được sử dụng là: 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1
    Đầu vào/đầu ra:
    [Thời gian chạy] 0.5 giây
    [Đầu vào] integer n
    Điều kiện:
    1 ≤ n ≤ 10^8.
    [output] integer
    Gợi ý:
    Do n có thể rất lớn, nên ko thể dùng vòng lặp để tính số các chữ số
    Hãy tính số các chữ số theo công thức toán học (ví dụ như có bao nhiêu số có 1 chữ số, 2 chữ số, 3 chữ số, ...)
*/
#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>

// C1:
// int pagesNumbering(int n)
// {
//     int digits = (int)(log10(n) + 1); // đếm xem n có bao nhiêu chữ số
//     int res = (n - pow(10, digits-1) + 1) * digits;
//     for (int i = 1; i <= digits - 1; i++)
//     {
//         res += (pow(10, i) - pow(10, i-1)) * i;
//     }
//     return res;
// }


// C2:
int pagesNumbering(int n)
{
    int number_of_digits = 0;
    for(int i = 1; i <= n; i *= 10)
        number_of_digits += (n - i + 1);
    return number_of_digits;
}


int main() {
    int n;
    std::cout << "Enter the digit n: ";
    std::cin >> n;

    std::cout << pagesNumbering(n) << std::endl;

    return 0;
}


