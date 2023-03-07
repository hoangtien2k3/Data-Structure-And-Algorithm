
/*
    Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. Tiếp theo cho một số nguyên k, (0 ≤ k < n), hãy xóa phần tử ở chỉ số k và in ra màn hình danh sách đó, sau một phần tử có một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
4
1 2 3 4
1

1 3 4
Với l = [1, 2, 3, 4], k = 1 thì kết quả mong muốn là:
"1 3 4 ".

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

int size(Node* &a) {
    int count = 0;
    while(a != NULL) {
        count++;
        a = a->next;
    }
    return count;
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

// xoa phan tu bat ky
void deleteMiddle(Node* &a, int k) {
    Node *truoc = NULL;
    Node *sau = a;
    for(int i = 0; i < k; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        a = a->next;
    } else {
        truoc->next = sau->next;
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
    for(int i=1; i<n; i++) {
        cin >> x;
        addTail(a, x);
    }
    cin >> k;
    deleteMiddle(a, k);
    in(a);

    return 0;
}