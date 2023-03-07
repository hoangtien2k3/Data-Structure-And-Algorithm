
// Danh sách liên kết với Queue trong C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

bool empty(Node *back) {
    return back == NULL;
}

int getSize(Node *back) {
    int count = 0;
    while(back != NULL) {
        ++count;
        back = back->next;
    }
    return count;
}

// đẩy phần tử vào cuối hàng đợi queue
Node *makeNode(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void push(Node* &back, int x) {
    Node *temp = makeNode(x);
    if (back == NULL) {
        back = temp;
    } else {
        temp->next = back;
        back = temp;
    }
}

void pop(Node* &back) {
    Node *truoc = NULL, sau = back;
    while(sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        back = NULL;
    } else {
        truoc->next = NULL;
    }
}

int front(Node *back) {
    while(back->next != NULL) {
        back = back->next; 
    }
    return back->data;
}

int main() {
    Node *back = NULL;
    


    return 0;
} 