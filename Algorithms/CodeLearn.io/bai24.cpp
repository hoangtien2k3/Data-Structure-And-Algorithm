
/*
    Cho hai xâu kí tự, hãy kiểm tra xem có tồn tại phương án đổi chỗ các kí tự ở trong xâu thứ nhất để trở thành xâu thứ hai được hay không? 
Ví dụ
Với string1 = "abcd" và string2 = "cbad" thì kết quả charactersRearrangement(string1, string2) = true;
Với string1 = "a" và string2 = "b" thì kết quả charactersRearrangement(string1, string2) = false.
Đầu vào/Đầu ra
[Thời gian chạy] 0.5 giây
[Đầu vào] string s1, s2
Xâu kí tự chứa các kí tự chữ cái in thường
Điều kiện:
1 ≤ string1.length ≤ 105.
[Đầu ra] boolean
true nếu tồn tại phương án đổi chỗ, false nếu ngược lại.
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<stdbool.h>
using namespace std;

#define true 1
#define false 0

// C1
bool charactersRearrangement(string string1, string string2)
{
    sort(string1.begin(), string1.end());
    sort(string2.begin(), string2.end());

    if (string1.length() != string2.length()) {
        return false;
    } else {
        for(int i=0; i<string1.length(); i++) {
            if (string1[i] != string2[i])
                return false;
        }
    }
    return true;
}

// C2
// bool charactersRearrangement(std::string string1, std::string string2)
// {
//     vector <int> a(256, 0);
//     for (int i = 0; i < string1.length(); i++)
//         a[string1[i]]++;
//     for (int i = 0; i  <string2.length(); i++)
//         a[string2[i]]--;
//     for (int i = 0; i <= 255; i++)
//         if (a[i] != 0)
//             return false;
//     return true;
// }

int main() {
    string string1 = "";
    string string2 = "";
    cin >> string1 >> string2;

    if (charactersRearrangement(string1, string2)) 
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}