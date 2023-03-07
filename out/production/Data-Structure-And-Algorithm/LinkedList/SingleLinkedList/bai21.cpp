
/*
    Nhập vào một số nguyên n, tiếp theo là n số nguyên của một dãy số.
Hãy cài đặt nó vào một danh sách liên kết đơn và in ra màn hình danh sách đó, sau mỗt phần tử có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
5
1 2 3 4 5

1 2 3 4 5

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *makeNode(int x){
    Node *temp = new Node;
    temp->next = NULL;
    temp->data = x; 
    return temp;
}

void addTail(Node* &a, int x) {
    Node *temp = makeNode(x);
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

void in(Node *a) {
    while(a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
}

int main() {
    int n, x;
    cin >> n;
    cin >> x;
    Node *a = makeNode(x);
    for(int i = 1; i < n; i++) {
        cin >> x;
        addTail(a, x);
    }
    in(a);

    cout << endl;

    cout << a << endl;
    cout << a->next << endl;
    cout << a->data << endl;


    return 0;
}





