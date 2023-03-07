
/*
    Một trang web định nghĩa 1 mật khẩu được gọi là mạnh (strong) nếu đảm bảo các yếu tố sau:
    Có độ dài tối thiểu là 6
    Chứa ít nhất 1 chữ số (1234567890)
    Chứa ít nhất kí tự chữ cái in thường (abc...z)
    Chứa ít nhất 1 kí tự chữ cái in hoa (ABC...Z)
    Chứa ít nhất 1 kí tự đặc biệt: !@#$%^&*()-+
    Cho một xâu kí tự thể hiện password, hãy kiểm tra xem đó có phải là password mạnh hay không?
    Ví dụ:
    Với password = "abc", kết quả checkStrongPassword(password ) = false;
    Với password = "Aa1!", kết quả checkStrongPassword(password ) = false;
    Với password = "Aabc1!", kết quả checkStrongPassword(password ) = true;
    Đầu vào/đầu ra:
    [Thời gian chạy] 0.5s với C++, 3s với Java và C#, 4s với Python, JS, Go
    [Đầu vào] string password
    Điều kiện:
    3 ≤ password.length ≤ 100.
    [Đầu ra] boolean
    true nếu password là strong, false ngược lại
*/
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool checkStrongPassword(string password)
{
    if (password.length() < 6) 
        return false;
    string p = "!@#$%^&*()-+";
    bool test1 = false;
    bool test2 = false;
    bool test3 = false;
    bool test4 = false;
    for(int i=0; i<password.length(); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            test1 = true;
        } else if (password[i] >= '0' && password[i] <= '9') {
            test2 = true;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            test3 = true;
        } else {
            if (p.find(password[i]) != -1) {
                test4 = true;
            }
        }
    }
    return test1 && test2 && test3 && test4;
}

int main() {
    string password;
    cin >> password;
    if (checkStrongPassword(password)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}