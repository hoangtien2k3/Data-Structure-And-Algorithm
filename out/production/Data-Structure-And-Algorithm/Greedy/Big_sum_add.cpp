
//! Cộng 2 số lớn trong C++

#include<iostream>
#include<string>
using namespace std;
 
string add(string a, string b)
{
    string res = ""; // dùng để chứa kết quả

    while(a.length() < b.length()) a = "0" + a; //! cộng thêm các ký tự '0' vào string
    while(a.length() > b.length()) b = "0" + b; //! cộng thêm các ký tự '0' vào string

    int carry = 0; // biến nhớ

    for(int i = a.length() - 1; i >= 0; i--)
    {    
        int tmp = a[i] - 48 + b[i] - 48 + carry;
        res = (char)(tmp % 10 + 48) + res;
        carry = tmp / 10; //! lấy ra phần nguyên
    }

    if(carry > 0) res = "1" + res;

    return res;
}

int main() {
    string a, b;
    std::cin >> a >> b;
    std::cout << add(a, b) << std::endl;  

    return 0;
}



