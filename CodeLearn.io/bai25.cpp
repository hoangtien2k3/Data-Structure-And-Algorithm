
/*
    Một pangram là một câu mà mỗi kí tự chữ cái (a-z) được sử dụng ít nhất một lần
Cho một xâu kí tự, kiểm tra xem nó có phải là một pangram hay không?
Ví dụ:
Với sentence = "The quick brown fox jumps over the lazy dog.", thì kết quả isPangram(sentence) = true;
Với sentence = "abcdefghijklmnopqrstuvwxya", thì kết quả isPangram(sentence) = false.
Đầu vào/Đầu ra:
[Thời gian chạy] 0.5 giây
[Đầu vào] string sentence
Xâu kí tự chứa các kí tự ASCII có mã nằm trong khoảng [32, 126].
Điều kiện:
1 ≤ sentence.length ≤ 100.
[Đầu ra] boolean
true nếu sentence là một câu pangram, false nếu ngược lại.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPangram(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z') 
            s[i] += 32;
    for (char i = 'a'; i <= 'z'; i++){
        if (s.find(i) == -1)
            return false;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    if (isPangram(s)) 
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    return 0;
}