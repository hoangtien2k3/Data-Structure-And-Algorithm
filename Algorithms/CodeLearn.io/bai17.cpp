
/*
    Một hệ thống hỏi đáp trực tuyến cần chuẩn hóa câu hỏi của người dùng
Một câu hỏi đã được chuẩn hóa cần tuân thủ các luật sau:
Luật chung: 
Câu hỏi chỉ chứa kí tự chữ cái (a-zA-Z), chữ số (0-9), dấu phẩy (,), dấu cách (' '), dấu hỏi (?). Các kí tự khác đều được thay thế bằng dấu cách
Luật dấu cách:
Không có dấu cách ở đầu hay ở cuối câu. Giữa các từ chỉ có 1 dấu cách duy nhất. Sau mỗi dấu cách là 1 chữ cái hoặc chữ số?
Luật dấu phẩy:
Trước dấu phẩy luôn là 1 chữ cái hoặc chữ số. Sau dấu phẩy luôn là một dấu cách
Trường hợp đứng trước dấu phẩy là dấu cách, hãy xóa dấu cách này đi.
Luật chữ hoa/chữ thường:
Chữ cái bắt đầu câu luôn được viết hoa. Các chữ cái khác đều viết thường
Luật dấu hỏi:
Luôn có 1 dấu ? kết thúc câu. Trước dấu ? luôn là kí tự chữ cái hoặc chữ số
Trường hợp có các dấu ? xuất hiện khi chưa kết thúc câu, hãy thay thế nó bằng dấu cách
Trường hợp trước dấu cách là dấu phẩy và dấu cách, hãy xóa dấu cách và dấu phẩy
Ví dụ:
Với đầu vào s="this is not a relevant question , is it???", thì kết quả questionCorrection(s) = "This is not a relevant question, is it?"
Với đầu vào s="who are you,,???", thì kết quả questionCorrection(s) = "Who are you?"
Đầu vào/đầu ra:
[Thời gian chạy] 0.5 giây
[Đầu vào] string s
Xâu kí tự chứa ít nhất 1 kí tự chữ cái (a-zA-Z)
1 <= x.length <= 1000
[Đầu ra] string
Xâu kí tự được chuẩn hóa theo các luật trên.
*/

#include<bits/stdc++.h>
using namespace std;

string xoa_Ky_Tu_Khong_Hop_Le(string s) {
    string check = "0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm,? ";
    for (auto ch : s) {
        if (check.find(ch) == -1) 
            s[s.find(ch)] = ' ';
    }
    return s;
}

string chuyen(string s) {
    while (s.find("?") != -1) s[s.find("?")] = ' ';
    while (s.find(",,") != -1) s.erase(s.find(",,"), 1);   
    while (s.find(" ,") != -1) s.erase(s.find(" ,"), 1);
    return s;
}

string chuanHoa(string s) {
    while (s[0] == ' ') s.erase(0, 1);
    while (s[s.length() - 1] == ' ') s.erase(s.length() - 1, 1);
    while (s.find("  ") != -1) s.erase(s.find("  "), 1);
    return s;
}

string chuHoa(string s) {
    if (s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        if (s[i] == ',' && i != s.length() - 1) {
            if (s[i + 1] != ' ') 
                s.insert(i + 1, " ");
        }
    }
    s += '?';
    while (s[s.length() - 2] == ' ' || s[s.length() - 2] == ',')
        s.erase(s.length() - 2, 1);
    return s;
}

string questionCorrection(string s) {   
    s = xoa_Ky_Tu_Khong_Hop_Le(s);
    s = chuyen(s);
    s = chuanHoa(s);
    s = chuHoa(s);
    return s;
}

int main() {
    string s;
    getline(cin, s);
    cout << questionCorrection(s);
    return 0;
}