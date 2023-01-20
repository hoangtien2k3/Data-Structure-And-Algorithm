
// Stack Linked List: danh sách liên kết với stack trong C++

// VD: chuyển thập phân sang nhị phân bằng stack

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

bool empty(Node *top) {
    return top == NULL;
}

int getSize(Node *top) {
    int count = 0;
    while(top != NULL) {
        ++count;
        top = top->next;
    }
    return count;
}

Node *makeNode(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void push(Node* &top, int x) {
    Node *temp = makeNode(x); // khi khai báo thì temp->next = NULL
    if (top == NULL) {
        top = temp;
    } else {
        temp->next = top; // gán con trỏ temp->next = top
        top = temp;
    }
}

void pop(Node* &top) {
    if (top == NULL) return;
    top = top->next;
}

int getTop(Node *top) {
    return top->data;
}

void in(Node *top) {
    while(!empty(top)) {
        cout << getTop(top);
        pop(top);
    }
}

int main() {
    Node *top = NULL;
    long long n; cin >> n;
    while(n) {
        int ans = n % 2;
        push(top, ans);
        n /= 2;
    }
    in(top);
    return 0;
}