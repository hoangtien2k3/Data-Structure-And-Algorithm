
/*
    Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. Tiếp theo nhập hai số nguyên a và b.
Hãy thay đổi giá trị của những phần tử có giá trị a thành giá trị b. In ra màn hình danh sách đó, sau một phần tử có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
6
1 1 2 2 3 3
2 10

1 1 10 10 3 3
Với  l = [1, 1, 2, 2, 3, 3], a = 2, b = 10, thì kết quả sẽ là:
"1 1 10 10 3 3 ".

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

Node *addTail(Node *a, int x) {
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
    return a;
}

Node *addMiddle(Node *a, int c, int b) {
    Node *p = a;
    while(p->next != NULL) {
        if (p->data == c) {
            p->data = b;
        }
        p = p->next;
    }
    return a;
}

void in(Node *a) {
    Node *p = a;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n, c, b, x;
    cin >> n;
    cin >> x;
    Node *a = makeNode(x);
    for(int i=1; i < n; i++) {
        cin >> x;
        addTail(a, x);
    }
    cin >> c >> b;
    addMiddle(a, c, b);
    in(a);
    return 0;
}

