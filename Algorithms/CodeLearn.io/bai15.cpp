
/*
    Cho một xâu kí tự chứa các chữ số từ 0 tới 9
Người ta áp dụng phép biển đổi xâu dựa trên các nguyên tắc sau:
nếu chữ số ngoài cùng bên trái chia hết cho 3, xóa nó khỏi xâu kí tự
nếu không thỏa mãn điều kiện trên, và nếu chữ số ngoài cùng bên tay phải chia hết cho 3, xóa nó khỏi xâu kí tự
nếu không thỏa mãn 2 điều kiện trên, và nếu tổng chữ số ngoài cùng bên trái và ngoài cùng bên phải chia hết cho 3, xóa cả hai chữ số trên khỏi xâu
Các phép toán trên được áp dụng vào xâu ban đầu cho tới khi xâu trở thành rỗng, hoặc ko đáp ứng cả 3 điều kiện trên
Cho một xâu kí tự, hãy tìm xâu kết quả cuối cùng khi áp dụng liên tục các phép toán trên
Ví dụ:
Với s = "312248", thì kết quả truncateString(s) = "2".
Các bước thực hiện để ra kết quả trên như sau:
Kí tự đầu tiên bên trái 3 chia hết cho 3 và bị xóa. Xâu s trở thành "12248";
Cả 1 và 8 đều không chia hết cho 3, nhưng tổng của chúng là 9 thì chia hết cho 3, do đó cả 1 và 8 bị xóa khỏi xâu. Xâu s trở thành "224";
Cả 2 và 4 đều không chia hết cho 3, nhưng tổng của chúng là 6 thì chia hết cho 3, do đó cả 2 và 4 bị xóa khỏi xâu. Xâu s trở thành "2";
Xâu "2" không thỏa mãn điều kiện nào trong các điều kiện trên, do đó đây là xâu đáp án cuối cùng.
Đầu vào/đầu ra:
[Thời gian chạy] 3 seconds 
[Đầu vào] string s
Điều kiện:
1 ≤ s.length ≤ 15.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string truncateString(string s)
{
    bool test = true;
    while(test == true && s.length() > 0) {
        test = false;
        if ((int)(s[0] - '0') % 3 == 0) {
            test = true;
            s.erase(0, 1);
        } else 
            if ((int)(s[s.length() - 1] - '0') % 3 == 0) {
                test = true;
                s.erase(s.length() - 1, 1);
            } else 
                if (((int)(s[0] + s[s.length() - 1] - '0')) % 3 == 0) {
                    test = true;
                    s.erase(0, 1);
                    s.erase(s.length() - 1, 1);
                }
    }
    return s;
}

int main() {
    string s = "";
    cin >> s;
    
    cout << truncateString(s) << endl;

    return 0;
}