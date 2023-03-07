
/*
    Cho một sâu s chỉ gồm các ký tự viết thường, hãy viết hàm trả về chuỗi mã hóa của sâu này. Xem ví dụ để hiểu rõ hơn quá trình mã hóa.

    Ví dụ

    Test mẫu 1:

    Input	   
        aaabbaaac
    Output:
        a3b2a3c1
    Với s = "aaabbaaac" thì encodeString(s) = "a3b2a3c1".

*/

#include<bits/stdc++.h>
using namespace std;

string to_string(int n){
    string s = "";
    while (n > 0){
        s = char(n % 10 + '0') + s;
        n /= 10;
    }
    return s;
}

int main(){
	string s;
	getline(cin, s);
 	s = s + '@';
    cout << s << endl;

    stack<char> st;
    string str = "";

    for (int i = 0; i < s.length(); i++){
        if (st.empty() || st.top() == s[i]){
            st.push(s[i]);
        } else {
            int count = 0;
            str += st.top();
            while(!st.empty()){
                count++;
                st.pop();
            }
            str = str + to_string(count);
            st.push(s[i]);
        }
    }
    cout << str;
}