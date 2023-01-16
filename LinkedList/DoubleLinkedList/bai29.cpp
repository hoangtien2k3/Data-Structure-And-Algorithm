
/*
Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đơn. Tiếp theo cho một số nguyên k, (0 ≤ k < n).
Hãy xóa phần tử ở chỉ số k và in ra màn hình danh sách đó, sau một phần tử có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
4
1 2 3 4
1

1 3 4
Với l = [1, 2, 3, 4], k = 1 thì kết quả mong muốn là:
"1 3 4 ".

Test mẫu 2:

Input	Output
3
1 2 3
0

2 3
Với l = [1, 2, 3], k = 0 thì kết quả mong muốn là:
"2 3".

*/

#include<bits/stdc++.h>
using namespace std;

// hàm khai báo Node
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

bool empty(List l) {
    return l.head == NULL;
}

int Size(List l) {
    int count = 0;
    while(l.head != NULL) {
        ++count;
        l.head = l.head->next;
    }
    return count;
}

// Hàm tạo Node trong danh sách liên kết đơn
Node *makeNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

//! chen phan tu vao dau:
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

//! chen phan tu vao cuoi:
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

//! xóa phần tử đầu:
void deleteHead(List &l) {
    if (l.head == NULL) {
        return;
    } else {
        l.head = l.head->next;
        l.head->previous = NULL;
    }
}

//! xóa phần tử cuối:
void deleteTail(List &l) {
    if (l.head == NULL) {
        return;
    } else {
        l.tail = l.tail->previous;
        l.tail->next = NULL;
    }
}

//! xóa phần tử ở giữa:
void deleteMiddle(List &l, int pos) {
    int size = Size(l);
    if (pos < 0 || pos >= size) {
        return;
    } else if (pos == 0) {
        deleteHead(l);
    } else if (pos == size - 1) {
        deleteTail(l);
    } else {
        Node *p = l.head;
        for(int i=1; i<=pos; i++) {
            p = p->next;
        }
        p->previous->next = p->next;
        p->next->previous = p->previous;
    }
}


void in_danh_sach(List l) {
    while(l.head != NULL) {
        cout << l.head->data << " ";
        l.head = l.head->next;
    }
}

int main() {
    int n, k, x;
    List l;
    init(l);
    cin >> n >> x;
    addHead(l, x);
    for(int i=1; i<n; i++) {
        int value; cin >> value;
        addTail(l, value);
    }
    cin >> k;
    deleteMiddle(l, k);
    in_danh_sach(l);
    return 0;
}

