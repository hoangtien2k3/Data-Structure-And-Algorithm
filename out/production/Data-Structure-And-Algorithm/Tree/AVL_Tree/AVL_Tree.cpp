//! Cây AVL Tree
/*
    * SAO LẠI SINH RA CÂY AVL LÀM GÌ ???

    ! + Cây AVL chính sự nâng cấp của cây BST (Binary Search Tree).
    
    ! Vậy thì BST có điểm yếu gì mà phải nâng cấp:
        + khi ta thêm các phần tử theo thứ tự tăng dần (giảm dần) thì cây bị suy biến và không khác gì một Linked List (Danh sách liên kết). 

        + Khi đó, độ phức tạp của thuật toán tìm kiếm của cây là O(n) chứ không phải O(log n) => ưu điểm của cây BST so với linkedlist cũng không còn nữa.

*/

/*
    ! Cây AVL:
        + Cây AVL là cây nhị phân tìm kiếm cân bằng với “chiều cao” giữa cây con bên trái 
        và cây con bên phải chênh nhau không vượt quá 1.

    ! Kỹ thuật quay cây AVL:
        + Kỹ thuật quay trái: Left-Left
        + Kỹ thuật quay phải: Right-Right
        + Kỹ thuật quay trái-phải: Left-Right
        + Kỹ thuật quay phải-trái: Right-Left

    ! Hệ số cân bằng:
        + Hệ số cân bằng của một nút trong cây AVL là hiệu số giữa chiều cao của cây con bên trái 
        và chiều cao của cây con bên phải của nút đó. 

        * hệ số cân bằng = abs( chiêu cao cây con bên trái - chiều cao cây con bên phải).

*/

#include <bits/stdc++.h>
#include <cmath>
#define COUNT 10
 
using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

 
int getHeight(Node* root) {
    if (root == NULL)
        return 0;
    //return 1 + max(getHeight(root->left), getHeight(root->right));
    return root->height;
}

 
Node* rightRotate(Node* root) {
    Node* x = root->left;
 
    // Bắt đầu quay phải.
    root->left = x->right;
    x->right = root;
 
    // Thiết lập chiều cao.
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
 
    // Return x - trả về root mới.
    return x;
}
 
Node* leftRotate(Node* root) {
    Node* y = root->right;
 
    // Bắt đầu quay trái
    root->right = y->left;
    y->left = root;
 
    // Thiết lập chiều cao.
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
 
    // Return y - trả về root mới
    return y;
}

// Insertion - AVL Tree
Node* Insert(Node* root, int value) {
    // 1. Insert
    if (root == NULL)
        return new Node{ value, NULL, NULL, 1 }; // Trả về Node có height = 1
    if (value > root->data)
        root->right = Insert(root->right, value);
    else if (value < root->data)
        root->left = Insert(root->left, value);
    else
        return root; // Neu bang thi khong them. Nghia la cac phan tu la duy nhat(doc nhat)
 
    //! 2. Set height.
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
 
    //! 3. Rotate: chỉ số cân bằng của cây AVL.
    int valBalance = getHeight(root->left) - getHeight(root->right);
    
    // Kiểm tra 4 TH xảy ra:
    // 3.1. Left-left.
    if (valBalance > 1 && value < root->left->data)
        return rightRotate(root);
    
    // 3.2. Right-Right.
    if (valBalance < -1 && value > root->right->data) // valBalance < -1 vì (phải lớn hơn trái thì khi hiệu của nó sẽ bé hơn -1)
        return leftRotate(root);
    
    // 3.3. Left-Right
    if (valBalance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // 3.4. Right-Left
    if (valBalance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 
 
// In - Print 2D ra console.
void print2DUtil(Node* root, int space){
    if (root == NULL)
        return;
    space += COUNT;
 
    print2DUtil(root->right, space);
    cout << endl;
 
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << " (" << root->height << ") " << "\n";
 
    print2DUtil(root->left, space);
}
 
void print2D(Node* root){
    print2DUtil(root, 0);
}
 
int main() {
    Node* tree = NULL;
    tree = Insert(tree, 18);
    tree = Insert(tree, 12);
    tree = Insert(tree, 30);
    tree = Insert(tree, 25);
    tree = Insert(tree, 69);
    tree = Insert(tree, 23);
    print2D(tree);


    return 0;
}
