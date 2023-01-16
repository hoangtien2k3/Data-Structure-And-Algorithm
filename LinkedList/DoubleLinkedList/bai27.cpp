
/*
    Nhập vào một số nguyên dương n, hãy cài đặt một danh sách lên kết đôi để lưu các số từ n giảm về 1 và từ 1 răng đến n (xem ví dụ để rõ hơn). In ra danh sách liên kết đó, phía sau mỗi phần tử có một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
3

3 2 1 2 3
Với n = 3 thì kết quả mong muốn là:
"3 2 1 2 3".

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *previous;
};

struct List {
    Node *head;
    Node *tail;
};

void init(List &l) {
    l.head = l.tail = NULL;
}

Node *makeNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->previous = NULL;
    return temp;
} 

void addHead(List &l, int value) {
    Node *temp = makeNode(value);
    if (l.head == NULL) {
        l.head = l.tail = temp;
    } else {
        temp->next = l.head;
        l.head->previous = temp;
        l.head = temp;
    }
}

void addTail(List &l, int value) {
    Node *temp = makeNode(value);
    if (l.head == NULL) {
        l.head = l.tail = temp;
    } else {
        l.tail->next = temp;
        temp->previous = l.tail;
        l.tail = temp;
    }
}

void in_danh_sach(List l) {
    Node *p = l.head;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n;
    cin >> n;
    List l;
    init(l);
    addHead(l, 1);
    for(int i=2; i<=n; i++) {
        addHead(l, i);
        addTail(l, i);
    }
    in_danh_sach(l);
    return 0;
}

