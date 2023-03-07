
/*
    Xóa các khoảng trắng thừa (kí tự cách) trong xâu kí tự cho trước, sao cho giữa các từ chỉ cách nhau bởi 1 khoảng trống. Cũng không có khoảng trống ở đầu và cuối của xâu
    Ví dụ
    Với input = " abc   a aa  a a ", kết quả formatString(input) = "abc a aa a a".
    Đầu vào/Đầu ra:
    [Thời gian chạy] 0.5 seconds
    [Đầu vào] string input
    xâu kí tự chứa kí tự chữ số và chữ cái in hoa hoặc in thường,
    Điều kiện:
    4 ≤ input.length ≤ 50.
    [Đầu ra] string
    Xâu kí tự sau khi đã xóa các kí tự space thừa.
*/

#include<iostream>
#include<string>
using namespace std;

string formatString(string input)
{
    // xóa khoảng trắng ở đầu chuỗi
    while (input[0] == ' ')
        input.erase(0, 1);

    //c1: xóa khoảng trắng ở thân chuỗi
    // for(int i=0; i < input.length(); i++) {
    //     while(input[i] == ' ' && input[i+1] == ' ') {
    //         input.erase(i, 1);
    //     }
    // }
    
    //c2: xóa khoảng trắng ở thân chuỗi
    while (s.find("  ") != -1)
        s.erase(s.find("  "), 1);

    // xóa khoảng trắng ở cuối chuỗi
	while (input[input.length()-1] == ' ')
        input.erase(input.length() - 1, 1); 
    return input;
}

int main() {
    string input;
    getline(cin, input);
    cout << formatString(input) << endl;
    return 0;
}