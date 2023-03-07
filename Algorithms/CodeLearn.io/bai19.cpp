
/*
    Cho hai xâu kí tự, tìm số lượng kí tự chung giữa chúng.
Ví dụ:
Với s1 = "aabcc" và s2 = "adcaa", thì kết quả commonCharacterCount(s1, s2) = 3.
2 xâu s1 và s2 có 3 kí tự chung: 2 kí tự 'a' và 1 kí tự 'c'.
Đầu vào/Đầu ra:
[Thời gian chạy] 0.5 giây
[Đầu vào] string s1, s2
Xâu kí tự chỉ chứa các kí tự chữ cái in thường, in hoa
Điều kiện:
1 ≤ s1.length, s2.length < 15.
[output] integer
*/

#include<bits/stdc++.h>
using namespace std;

int commonCharacterCount(string s1, string s2)
{
    // C1:
    // int res = 0;
    // for (int i = 0; i < s1.length(); i++) {
    //     if (s2.find(s1[i]) != -1)
    //     {
    //         res++;
    //         s2.erase(s2.find(s1[i]), 1);
    //     }
    // }

    // C2:
    int res = 0;
    for(int i=0; i<s1.length(); i++) {
        for(int j=0; j<s2.length(); j++) {
            if (s1[i] == s2[j]) {
                res++;
                s2.erase(j, 1);
                break;
            }
        }
    }

    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << commonCharacterCount(s1, s2) << endl;
    return 0;
}