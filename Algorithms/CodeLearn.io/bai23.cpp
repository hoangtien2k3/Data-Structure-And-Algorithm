
/*
    Cho một xâu kí tự, tìm số lượng xâu con khác nhau của xâu đó (không tính xâu rỗng)
Ví dụ
Với inputString = "abac", thì kết quả differentSubstringsTrie(inputString) = 9.
9 xâu con khác nhau của xâu đầu vào là:
"a", "b", "c", "ab", "ac", "ba", "aba", "bac", "abac"
Đầu vào/Đầu ra:
[Thời gian chạy] 0.5 giây
[Đầu vào] string inputString
Xâu kí tự chỉ chứa kí tự chữ cái in thường
Điều kiện:
3 ≤ inputString.length ≤ 15.
[Đầu ra] integer
*/

#include<bits/stdc++.h>
using namespace std;

int differentSubstringsTrie(string inputString)
{
    set<string> set;
    for (int i = 0; i < inputString.length(); i++) {
        for (int j = i; j < inputString.length(); j++)
            set.insert(inputString.substr(i, j - i + 1));
    }
    return set.size();
}

int main() {
    string inputString;
    cin >> inputString;
    cout << differentSubstringsTrie(inputString);
    return 0;
}