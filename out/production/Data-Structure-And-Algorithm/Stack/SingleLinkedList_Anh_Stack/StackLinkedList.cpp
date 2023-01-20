
//! Stack Linked List: danh sách liên kết với stack trong C++

//* VD: bài tập: chuyển thập phân sang nhị phân bằng stack

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

void push(Node* &top, int x) { //! thêm phần tử vào đầu.
    Node *temp = makeNode(x); 
    if (top == NULL) {
        top = temp;
    } else {
        temp->next = top; 
        top = temp; //! gán lại cho top thành phần tử đầu của danh sách liên kết đơn.
    }
}

void pop(Node* &top) { //! xóa phần tử ở đầu (vì stack (Last In First Out))
    if (top == NULL) 
        return;
    top = top->next;
}

void in(Node *top) {
    while(!empty(top)) {
        cout << top->data;
        pop(top);
    }
}

int main() {
    system("cls");

    Node *top = NULL;
    long long n; cout << "Input n: "; cin >> n;
    while(n) {
        int ans = n % 2;
        push(top, ans);
        n /= 2;
    }
    in(top);

    cin.get();
    return 0;
}

