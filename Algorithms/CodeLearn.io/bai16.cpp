
/*
    Định nghĩa phép toán crossover của hai xâu có độ dài bằng nhau A và B như sau:
Kết quả của phép toán này là một xâu result có độ dài bằng với hai xâu đầu vào
result[i] bằng A[i] hoặc B[i].
Cho một danh sách các xâu có độ dài bằng nhau inputArray và một xâu result, hãy đếm xem có bao nhiêu cặp xâu trong mảng đã cho mà kết quả của phép toán crossover cho ra kết quả là result.
Ví dụ:
Với inputArray = ["abc", "aaa", "aba", "bab"] và result = "bbb", kết quả stringsCrossover(inputArray, result) = 2.
Có 2 cặp xâu kí tự thỏa mãn yêu cầu đề bài là:
abc vs bab
Ta thấy rằng với A = "abc" và B = "bab".
result[0] = 'b' = B[0]
result[1] = 'b' = A[1]
result[2] = 'b' = B[2].
aba vs bab
Đầu vào/Đầu ra:
[Thời gian chạy] 0.5 giây
[input] array.string inputArray
Mảng không rỗng chứa các xâu kí tự có độ dài bằng nhau.
Điều kiện:
2 ≤ inputArray.length ≤ 10,
1 ≤ inputArray[i].length ≤ 10.
[input] string result
Xâu kí tự có cùng độ dài với các xâu kí tự trong mảng inputArray.
Điều kiện:
result.length = inputArray[i].length.
[output] integer.
*/

#include<bits/stdc++.h>
using namespace std;

bool check(string a, string b, string c){
    for(int i=0; i < a.length(); i++) {
        if (a[i] == c[i] || b[i] == c[i]) {
            return true;
        }
    }
    return false;
}

int stringsCrossover(vector<string> inputArray, string result){
    int count = 0;
    for (int i = 0; i < inputArray.size() - 1; i++)
        for (int j = i + 1; j < inputArray.size(); j++)
            if (check(inputArray[i], inputArray[j], result) == 1) 
                count++;
    return count;
}

int main() {
    vector<string> inputArray;
    string result;
    int n;
    cout << "Nhap vao so phan tu cua vector: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        string x;
        cout << "v["<<i<<"] = ";
        cin >> x;
        inputArray.push_back(x);
    }

    cout << "Nhap vao result: ";
    cin >> result;

    cout << "KQ: " << stringsCrossover(inputArray, result) << endl;
    return 0;
}