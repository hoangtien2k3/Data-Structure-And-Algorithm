/*
Cho một xâu kí tự, viết hàm mã hóa xâu đó theo các luật sau:
Đầu tiên, cắt xâu ban đầu thành các xâu con mà mỗi xâu con chỉ chứa các kí tự giống nhau và xâu con tạo ra có độ dài là lớn nhất
Ví dụ, xâu "aabbbc" được tách thành ["aa", "bbb", "c"]
Tiếp theo, với mỗi xâu con có chiều dài lớn hơn 1, hãy thay thế xâu đó bằng việc viết liền độ dài của xâu với kí tự lặp lại
Ví dụ, xâu con "bbb" được thay thế bằng "3b"
Cuối cùng, viết liên tiếp các xâu con vừa được mã hóa theo thứ tự ban đầu để tạo ra xâu kết quả
Ví dụ:
Với s = "aabbbc", thì kết quả lineEncoding(s) = "2a3bc".
Đầu vào/Đầu ra:
[Thời gian chạy] 0.5 seconds 
[Đầu vào] string s
Xâu kí tự chứa các kí tự chữ cái in thường.
Điều kiện:
4 ≤ s.length ≤ 100.
[Đầu ra] string
Xâu kí tự mã hóa.
*/

#include<iostream>
using namespace std;

string lineEncoding(string s)
{
    string k = "";
    int count = 1;
    for(int i=0; i<s.length(); i++) {
        if (s[i] == s[i + 1]) {
            count++;
        } else {
            if (count > 1) {
                k += to_string(count);
            }
            k += s[i];
            count = 1;
        }
    }
    return k;
} 

int main() {
    string a = "";
    cin >> a;
    cout << lineEncoding(a) << endl;
    return 0;
}