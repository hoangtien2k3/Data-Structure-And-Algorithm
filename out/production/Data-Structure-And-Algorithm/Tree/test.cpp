
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class Insert { //! Class chèn đối tượng vào cây nhị phân tìm kiếm
    public:

    Node * insert(Node * root, int data) { // chen phan tu vao cay nhi phan tim kiem.
        if (root == NULL) {
            Node *temp = new Node(data);
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
        } else {
            if (data  < root->data) {
                root->left = insert(root->left, data);
            } else if (data > root->data) {
                root->right = insert(root->right, data);
            }
        }
        return root;
    }
};


class Delete { //! Class xóa đối tượng trong cây nhị phân tìm kiếm
public: 

    //! tìm node thế mạng cho node cần xóa
    Node * findAndReplacce(Node *&p, Node *&tree) {
        if (tree->left != NULL) { //! đi tìm vị trí của trái nhất của cây con bên phải.
            tree->left = findAndReplacce(p, tree->left);

        } else { //! đã tìm ra vị trí của Node thế mạng
            p->data = tree->data;
            p = tree;
            tree = tree->right;
        }

        return p; //! trả về 
    }

    Node * deleteNode(Node *root, int data) {
        if (root == NULL) {
            return NULL;
        } else {
            if (root->data > data) {
                root->left = deleteNode(root->left, data);
            } else if (root->data < data) {
                root->right = deleteNode(root->right, data);
            } else {
                Node *p = root; //! gán p là node đã tìm thấy(cần xóa);

                if (root->left == NULL) {
                    root = root->right;
                }
                else if (root->right == NULL) {
                    root = root->left;
                }
                else {
                    findAndReplacce(p, root->right);
                }
                
                delete p;
            }  
        }
        return root;
    }
};


class Print { //! Class in ra cây nhị phân tìm kiếm
public:
    void preOrder(Node *root) { // in danh sach lien ket
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	preOrder(root->left);
      	preOrder(root->right);
    }
};


class Search { //! Tìm kiếm trong cây nhị phân:
public:
    Node * Search_In_Tree(Node *root, int x) {
        if (root == NULL) {
            return NULL;
        } else {
            if (x < root->data) {
                Search_In_Tree(root->left, x);
            } else if (x > root->data) {
                Search_In_Tree(root->right, x);
            } else { // root->data == x
                return root; // trả về nút cần tìm 
            }
        }
    }
};


int main() {
  
    Insert insert;
    Delete delete1;
    Print print;
    Search search;

    Node *root = NULL;

    while(1) {
        std::cout << "\n_________________Menu________________\n";
        std::cout << "\n1. Chen phan tu vao cay nhi phan tim kiem.";
        std::cout << "\n2. In danh sach cay nhi phan tim kiem.";
        std::cout << "\n3. Xoa phan tu vi tri bat ky trong cay.";
        std::cout << "\n4. Tim kiem phan tu trong cay nhi phan tim kiem";
        std::cout << "\n_____________________________________\n";

        int lc; cout << "Nhap vao lua chon: "; cin >> lc;
        if (lc == 1) {
            int x; std::cout << "Nhap vao doi tuong can chen: "; std::cin >> x;
            root = insert.insert(root, x);
        } else if  (lc == 2) {
            std::cout << "Danh sach cay nhi phan tim kiem: ";
            print.preOrder(root);
        } else if (lc == 3) {
            int x; std::cout << "Nhap vao doi tuong can xoa: "; std::cin >> x;
            delete1.deleteNode(root, x);
        } else if (lc == 4) {
            int x; std::cout << "Nhap vao doi tuong can tim kiem: "; std::cin >> x;
            Node *check = search.Search_In_Tree(root, x);
            if (check == NULL) {
                std::cout << "Khong tim thay doi tuong " << x << " trong cay nhi phan";
            } else {
                std::cout << "Tim thay doi tuong " << x << " trong cay nhi phan";
            }
        }
    }
  	
    
    return 0;
}

