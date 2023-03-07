
/*
    Cho một xâu kí tự s
Hãy kiểm tra xem xâu s có thể tạo ra bằng cách ghép một xâu vào chính nó hay không?  
Ví dụ:
Với inputString = "tandemtandem", kết quả isTandemRepeat(inputString) = true
Có thể tạo ra xâu "tandemtandem" bằng cách ghép xâu "tandem" vào phía sau của chính nó
Với inputString = "qqq", kết quả isTandemRepeat(inputString) = false
Với inputString = "2w2ww", kết quả isTandemRepeat(inputString) = false
Đầu vào/Đầu ra
[Thời gian chạy] 0.5 seconds
[Đầu vào] string inputString
Điều kiện:
2 ≤ inputString.length ≤ 20.
[Đầu ra] boolean.
*/

#include<iostream>
#include<stdbool.h>
#include<bits/stdc++.h>
using namespace std;

bool isTandemRepeat(string inputString)
{   
    if (inputString.length() % 2 == 0) {
        if (inputString.substr(0, inputString.length()/2) == inputString.substr(inputString.length()/2, inputString.length()/2)) {
            return true;
        }
    }
    return false;
}


int main() {
    string inputString;
    cin >> inputString;

    cout << isTandemRepeat(inputString) << endl;
    
    return 0;
}

