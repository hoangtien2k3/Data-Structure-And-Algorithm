
/*
    Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn, tiếp theo nhập số nguyên k (0 ≤ k < n).
Hãy đưa ra giá trị phần tử ở chỉ số k.

Ví dụ:

Test mẫu 1:

Input	Output
5
1 2 3 4 5
3

4
Với l = [1, 2, 3, 4, 5] và k = 3 thì kết quả sẽ là 4.

*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *createNode(int x){
    Node *temp = new Node;
    temp->next = NULL;
    temp->data = x; 
    return temp;
}

void addTail(Node* &a, int x) {
    Node *temp = createNode(x);
    if (a == NULL) {
        a = temp;
    } else {
        Node *p = a;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

int getNode(Node* &a, int k) {
    for(int i = 0; i < k; i++) {
        a = a->next;
    }
    return a->data;
}

int main() {
    int n, k, x;
    cin >> n;
    cin >> x;
    Node *a = createNode(x);
    for(int i = 1; i < n; i++) {
        cin >> x;
        addTail(a, x);
    }
    cin >> k;
    cout << getNode(a, k);
    return 0;
}
