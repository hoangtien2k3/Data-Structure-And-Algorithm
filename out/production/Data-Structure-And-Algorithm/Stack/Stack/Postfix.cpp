
/*
    - Phương pháp chuyển từ biểu thức trung tố sang tiền tố và hậu tố
    
        + Có hai cách để chuyển một biểu thức từ trung tố sang hai loại còn lại đó là dùng:
            –  Stack
            –  Expression Tree (cây biểu thức).



        + Độ ưu tiên của các toán tử:
            multiply (+),subtract (-), multiply (*), divide (/), Modulo (%).

            Ex:

                public static int GetPriority(string op) {
                    if (op == "*" || op == "/" || op == "%")
                        return 2;
                    if (op == "+" || op == "-")
                        return 1;
                    return 0;
                }

*/

#include<bits/stdc++.h>
using namespace std;

int degree(char c) { // hàm này để biết xem cái nào có độ ưu tiên lớn hơn hoặc bằng
    if (c == '^') 
        return 5;
    if (c == '*' || c == '/' || c == '%')
        return 4;
    if (c == '+' || c == '-')
        return 3;
    return 2;
}

string Solution(string s) {
    string res = "";
    stack<char> stack;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            res = res + s[i];
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            res = res + s[i];
        } else if (s[i] == '(') {
            stack.push(s[i]);
        } else if (s[i] == ')') {
            while(stack.size() != 0 && stack.top() != '(') {
                res = res + stack.top(); // lấy ký tự ở đỉnh stack ra ngoài.
                stack.pop(); // xóa ký tự ở đỉnh stack khi lấy ra ngoài.
            }
            stack.pop(); // để xóa ký tự '('
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
            while(stack.size() != 0 && degree(stack.top()) >= degree(s[i])) {
                res = res + stack.top();
                stack.pop();
            }
            stack.push(s[i]);
        }
    }

    while(stack.size()) {
        if (stack.top() != '(') {
            res = res + stack.top();
            stack.pop();
        }
    }
    
    return res;
}

int main() {
    system("cls");
    string s; cout << "Infix: "; cin >> s;
    cout << "Postfix: " << Solution(s) << endl;
    cin.get();
    return 0;
}