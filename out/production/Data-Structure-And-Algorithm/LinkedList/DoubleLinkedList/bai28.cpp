
/*
    Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đôi. 
    Tiếp theo cho hai số nguyên k và x, (0 ≤ k ≤ n).
    Hãy chèn giá trị x vào danh sách liên kết tại chỉ số k và in ra màn hình danh sách đó, sau một phần tử có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
3
1 2 3
0 10

10 1 2 3
Với l = [1, 2, 3] và k = 0, x = 10 thì kết quả là:
"10 1 2 3 ".

Test mẫu 2:

Input	Output
3
1 2 3
3 10	1 2 3 10
Với l = [1, 2, 3] và k = 3, x = 10 thì kết quả là:
"1 2 3 10".

Test mẫu 3:

Input	Output
4
1 2 3 4
2 10

1 2 10 3 4
Với l = [1, 2, 3, 4] và k = 2, x = 10 thì kết quả là:
"1 2 10 3 4 ".

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

// add vao dau:
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

// add vao cuoi:
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

int Size(List l) {
    int count = 0;
    Node *p = l.head;
    while(p != NULL) {
        ++count;
        p = p->next;
    }
    return count;   
}

// add vao giua:
void addMiddle(List &l, int value, int pos) {
    Node *temp = makeNode(value);
    int size = Size(l);
    if (pos < 0 || pos > size) {
        return;
    } else if (pos == 0) {
        addHead(l, value);
    } else if (pos == size) {
        addTail(l, value);
    } else {
        Node *p = l.head;
        for(int i=1; i<pos; i++) {
            p = p->next;
        }
        temp->next = p->next;
        p->next->previous = temp;
        p->next = temp;
        temp->previous = p;
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
    int n, k, x, value;
    List l;
    init(l);
    cin >> n;
    cin >> value;
    addHead(l, value);
    for(int i=1; i<n; i++) {
        int v; cin >> v;
        addTail(l, v);
    }
    cin >> k >> x;
    addMiddle(l, x, k);
    in_danh_sach(l);

    return 0;
}