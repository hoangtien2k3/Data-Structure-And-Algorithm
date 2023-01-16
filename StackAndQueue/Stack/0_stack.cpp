
/*
    ! cấu trúc stack. (LIFO : Last in frist out)

    Stack là một loại container adaptor, được thiết kế để hoạt động theo kiểu LIFO (Last - in first - out) 
    (vào sau ra trước), tức là một kiểu danh sách mà việc bổ sung và loại bỏ một phần tử được thực hiển ở 
    cuối danh sách. Vị trí cuối cùng của stack gọi là đỉnh (top) của ngăn xếp.

    Stack giống như việc giáo viên kiểm tra vở bài tập của học sinh vậy, ai nộp sau 
    cùng thì vở bài tập củangười đó sẽ được giáo viên kiểm tra đầu tiên


    
    ! Stack có các hàm sau (ví dụ cho C++):
        size : trả về kích thước hiện tại của stack. ĐPT O(1).
        empty : true stack nếu rỗng, và ngược lại. ĐPT O(1).
        push : đẩy phần tử vào stack. ĐPT O(1).
        pop : loại bỏ phẩn tử ở đỉnh của stack. ĐPT O(1).
        top : truy cập tới phần tử ở đỉnh stack. ĐPT O(1).

*/

#include<iostream>
#include<stack>

using namespace std;

int main(){
	string s;
	stack<char> st;
	getline(cin,s);
	for (int i = 0; i < s.length(); i++){
		st.push(s[i]);
	}
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
    
	return 0;
}