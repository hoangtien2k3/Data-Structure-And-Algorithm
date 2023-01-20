
/*
    Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. Tiếp theo nhập một số nguyên k (0 ≤ k <n).
Hãy xóa những phần tử có giá trị lớn hơn giá trị của phần tử ở chỉ số k. In ra màn hình danh sách đó, sau một phần tử có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
6
1 1 2 2 3 3
2

1 1 2 2
Với  l = [1, 1, 2, 2, 3, 3], k = 2, thì kết quả sẽ là:
"1 1 2 2 ".

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

void addMiddle(Node* &a, int x) {
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

int size(Node *a) {
    int count = 0;
    Node *p = a;
    while(p != NULL) {
        ++count;
        p = p->next;
    }
    return count;
}

void deleteElementsMoreK(Node* &a, int k) {
    Node *p = a;
    int answer = 0, count = 0;
    for(Node *vt = a; vt != NULL; vt = vt->next) {
        if (count == k) {
            answer = vt->data;
        }
        count++;
    }
    Node *res = a;
    for(Node *res = a; res != NULL; res = res->next) {
        if (res->data <= answer) {
            cout << res->data << " ";
        }
    }
}

int main() {
    int n, x, k;
    cin >> n;
    cin >> x;
    Node *a = makeNode(x);
    for(int i=1; i < n; i++) {
        cin >> x;
        addMiddle(a, x);
    }
    cin >> k;
    deleteElementsMoreK(a, k);
    return 0;
}


