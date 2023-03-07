
/*
    Nhầm chữ số:

        Trong một buổi học toán , giáo viên viết 2 số nguyên A và B, yêu cầu Tèo thực hiện phép cộng
    Tèo không bao giờ tính sai, nhưng thi thoảng cậu ta chép các con số một cách không chính xác
    lỗi duy nhất là ghi nhầm "5" thành "6" hoặc ngược lại. cho 2 số A và B, tính tổng nhỏ nhất 
    và lớn nhất mà Tèo có thể nhận được.


    input: có một dòng chứ 2 số nguyên dương A và B (1 <= A , B <= 1000000).
    output: In ra 2 số nguyên cách nhau bởi 1 dấu cách, tổng nhỏ nhất và lớn nhất có thể nhận được.


    Ex:
        input:     11      25
        output:    36      37


        input:     1430    4862
        output:    6282    6292

*/

#include<bits/stdc++.h>
using namespace std;

string sum(string a, string b) {
    while(a.length() < b.length()) a = "0" + a;
    while(a.length() > b.length()) b = "0" + b;

    int length = a.length();
    int res = 0; // bien nho
    string ans = "";

    for(int i = length - 1; i >= 0; i--) {
        int result = int(a[i] - '0') + int(b[i] -'0') + res;
        ans = char(result % 10 + '0') + ans;
        res = result / 10;
    }

    if (res > 0) return char(res + '0') + ans;
    
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    string a, b;

    int t = 1;
    while(t--) {
        cin >> a >> b;
        for(int i = 0; i < a.length(); i++) 
            if (a[i] == '6') a[i] = '5';

        for(int i = 0; i < b.length(); i++) 
            if (b[i] == '6') b[i] = '5';

        cout << sum(a, b) << " ";

        for(int i = 0; i < a.length(); i++) 
            if (a[i] == '5') a[i] = '6';

        for(int i = 0; i < b.length(); i++) 
            if (b[i] == '5') b[i] = '6';

        cout << sum(a, b) << endl;

    }

    return 0;
}

