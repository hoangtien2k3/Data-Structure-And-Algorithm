
/*
    Huyền có một cái điện thoại, màn hình điện thoại của Huyền chỉ hiển thị được tối đa k tin nhắn. Màn hình của Huyền hiện thị như sau:

Không hiện thị 2 tin nhắn của cùng một số điện thoại (SĐT) trên cùng một khung hình, nếu SĐT a gửi tin nhắn đến mà trên màn hình đã có tin nhắn của SĐT a thì màn hình không thay đổi gì.
Khi SĐT a gửi tin nhắn đến mà trên màn hình chưa có tin nhắn của SĐT a thì:
Nếu màn hình chưa đủ k tin nhắn thì tin nhắn của SĐT a sẽ được chèn vào cuối màn hình. 
Nếu màn hình đã có đủ k tin nhắn thì thì màn hình sẽ đẩy tin nhắn trên cùng ra và sau đó chèn tin nhắn của SĐT a vào cuối màn hình.

Cho dãy a là các SĐT sẽ gửi tin nhắn cho Huyền. Hỏi sau khi nhận được tin nhắn cuối cùng thì màn hình của Huyền đang hiển thì tin nhắn của các SĐT nào, đưa ra theo thứ tự từ trên xuống dưới của màn hình.

Ví dụ:

Test mẫu 1:

Input	Output
5
1 2 1 3 4
3

2 3 4
Với a = [1, 2, 1, 3, 4], k = 3. thì messagesPhone(a) = [2, 3, 4];

Giải thích:
Lúc đầu màn hình điện thoại rỗng [].
Sau khi 1 nhắn tin đến thì màn hình hiển thì [1].
Sau khi 2 nhắn tin đến thì màn hình hiển thị [1, 2].
Sau khi 1 nhắn tin đến thì màn hình không thay đổi gì vì trên màn hình đã có tin nhắn của 1 rồi.
Sau khi 3 nhắn tin đến màn hình hiển thị [1, 2, 3]
Sau khi 4 nhắn tin đến, lúc này màn hình đã hiển thị đủ 3 tin nhắn rồi nên điện thoại sẽ đẩy tin nhắn đầu tiên là 1 đi và chèn tin nhắn của 4 vào cuối, cuối cùng màn hình hiển thị [2, 3, 4].

*/

#include<iostream>
#include<queue>
#include<stdbool.h>
using namespace std;

void messengerPhone(int a[], int b[], int n, int k) {
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (b[a[i]] == false){
            if (q.size() < k){
                b[a[i]] = true;
                q.push(a[i]);
            } else{
                b[q.front()] = false;
                b[a[i]] = true;
                q.push(a[i]);
                q.pop();
            }
	}
	while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}


int main(){
	queue<int> q;
	int b[1001];
	int a[1001];
	int n, k;
	cin >>n;
	for (int  i = 0; i < 1001; i++){
		b[i] = false;
	}
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> k;
	messengerPhone(a, b, n, k);
	return 0;
}