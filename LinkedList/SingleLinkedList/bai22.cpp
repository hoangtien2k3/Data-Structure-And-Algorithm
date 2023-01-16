
/*
    Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. Tiếp theo nhập hai số nguyên k và x, (0 ≤ k ≤ n), hãy chèn giá trị x vào danh sách liên kết tại chỉ số k và in ra màn hình danh sách đó, sau một phần tử có một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
4
1 2 3 4
1 10

1 10 2 3 4
Với l = [1, 2, 3, 4], k = 1, x = 10 thì kết quả mong muốn là:
"1 10 2 3 4 ".

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *makeNode(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

int sizeLinkedList(Node *a) {
    int count = 0;
    while(a != NULL) {
        ++count;
        a = a->next;
    }
    return count;
}

void addHead(Node* &a, int x) {
    Node *temp = makeNode(x);
    if (a == NULL) {
        a = temp;
    } else {
        temp->next = a;
        a = temp;
    }
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

void addMiddle(Node* &a, int k, int x) {
    int size = sizeLinkedList(a);
    if (k == 0) {
        addHead(a, x);
    } else if (k == size + 1) {
        addTail(a, x);
    } else {
        Node *p = a;
        Node *temp = makeNode(x);
        for(int i = 1; i <= k - 1; i++) {
            p = p->next;
        }
        temp->next = p->next;
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
    int n, k, x;
    cin >> n;
    cin >> x;
    Node *a = makeNode(x);
    for(int i = 1; i < n; i++) {
        cin >> x;
        addTail(a, x);
    }
    cin >> k;
    cin >> x;
    addMiddle(a, k, x);
    in(a);

    return 0;
}