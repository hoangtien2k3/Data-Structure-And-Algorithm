
/*
    Một xâu được gọi là palindrome nếu viết xuôi hay viết ngược xâu đó đều cho ra kết quả giống nhau
    Cho một xâu kí tự, kiểm tra nó có phải xâu palindrome không.
    Ví dụ
    Với inputString = "aabaa", kết quả checkPalindrome(inputString) = true;
    Với inputString = "abac", kết quả checkPalindrome(inputString) = false;
    Với inputString = "a", kết quả checkPalindrome(inputString) = true.
    Đầu vào/Đầu ra
    [Thời gian chạy] 0.5 giây
    [Đầu vào] string inputString.
    Xâu không rỗng chứa các kí tự chữ cái in thường
    Điều kiện:
    1 ≤ inputString.length ≤ 105.
    [Đầu ra] boolean
    true nếu inputString là xâu palindrome, false nếu không.
*/

#include<iostream>
#include<string>
#include<stdbool.h>
using namespace std;

// c1
bool palindromeString(string inputString) {
    string s = "";
    for(int i=inputString.length() - 1; i >= 0; i--) 
        s += inputString[i];
    return s == inputString;
}

// c2
// bool palindromeString(string inputString) {
//     for (int i = 0; i < inputString.length() / 2; i++)
//     if (inputString[i] != inputString[inputString.length() - 1 - i])
//         return false;
//     return true;
// }

int main() {
    string inputString;
    cin >> inputString;

    cout << palindromeString(inputString) << endl;

    return 0;
}