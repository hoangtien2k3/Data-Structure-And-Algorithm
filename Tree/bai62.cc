
/*
    Cho một dãy n số nguyên. Hãy cài đặt các số trong dãy đó vào kiểu dữ liệu cây. In cây theo cách duyệt trung thứ tự (xem lý thuyết). Sau mỗi phần tử có đúng một khoảng trắng.

Ví dụ:

Test mẫu 1:

Input	Output
5
3 2 1 5 4

1 2 3 4 5
Với a = [3, 2, 1, 5, 4] thì kết quả mong muốn là "1 2 3 4 5 ".
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void init(Node *&root) {
    root = NULL;
}

Node *makeNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node * addNode(Node *root, int value) {
    Node *temp = makeNode(value);
    if (root == NULL) {
        root = temp;
    } else {
        if (value < root->data) {
            root->left = addNode(root->left, value);
        } else {
            root->right = addNode(root->right, value);
        }
    }
    return root;
}

void PrintTree(Node *root) {
    if (root != NULL) {
        PrintTree(root->left);
        cout << root->data << " ";
        PrintTree(root->right);
    }
}

int main() {
    Node *root;
    init(root);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        root = addNode(root, x);
    }
    PrintTree(root);
    return 0;
}

