
//! Đếm số cây con của cây nhị phân tìm kiếm.
/*
    Cho một dãy gồm n số nguyên, hãy cài đặt dãy đó vào cây nhị phân tìm kiếm bằng cách sau, phần tử đầu tiên được chọn làm gốc, các phần tử tiếp theo được chèn và cây nhị phần theo cách: node con bên trái luôn nhỏ hơn node cha, node con bên phải luôn lớn hơn học bằng node cha.

Hãy đưa ra bậc của cây đó.

Ví dụ:

Test mẫu 1:

Input	Output
7
4 7 2 1 3 2 5

3
Với a = [4, 7, 2, 1, 3, 2, 5] thì kết quả mong muốn là 3:
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

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

//! C1:
// int treeLevel(Node *t){
// 	if (t == NULL) return -1;
// 	return 1 + max(treeLevel(t->left), treeLevel(t->right));
// }

//! C2:
int t = 0;
int treeLevel(Node *root, int k) {
    if (root->left == NULL && root->right == NULL) {
        if (k > t) // kiểm tra 2 node con cùng bậc 
            t = k; 
    }
    else {
        if (root->left != NULL)
            treeLevel(root->left, k+1);
        if (root->right != NULL) 
            treeLevel(root->right, k+1);
    }
    return t;
}

int main() {
    int n; cin >> n;
    Node *root = NULL;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        root = addNode(root, x);
    }
    cout << treeLevel(root, 0);
    return 0;
}