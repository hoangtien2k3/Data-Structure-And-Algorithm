
/*
    Cho xâu kí tự. Hãy đếm số lượng kí tự khác nhau trong xâu đó
    Ví dụ:
    Với s = "cabca", thì kết quả differentSymbolsNaive(s) = 3.
    Có 3 kí tự khác nhau là a, b và c.
    Đầu vào/Đầu ra:
    [Thời gian chạy] 0.5 seconds
    [Đầu vào] string s
    Xâu kí tự chứa các chữ cái in thường.
    Guaranteed constraints:
    3 ≤ s.length ≤ 1000.
    [Đầu ra] integer.
*/

#include<bits/stdc++.h>
using namespace std;

// C1
int differentSymbolsNaive(string s)
{
    set<char> setArray;
    for(int i=0; i<s.length(); i++) {
        setArray.insert(s[i]);
    }
    return setArray.size();
}

// C2
// int differentSymbolsNaive(string s)
// {
//     vector <bool> b;
//     for (int i = 0; i < s.length(); i++)
//         b[s[i]] = true;
//     int d = 0;
//     for (int i = 0; i < s.length(); i++)
//     if (b[s[i]]){
//         d++;
//         b[s[i]] = false;
//     }
//     return d;
// }


int main() {
    string s;
    cin >> s;
    cout << differentSymbolsNaive(s);
    return 0;
}