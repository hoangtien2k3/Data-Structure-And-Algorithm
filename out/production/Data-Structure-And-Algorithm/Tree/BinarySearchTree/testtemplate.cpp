

#include<bits/stdc++.h>
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

class BinarySearchTree {
public:

    //! thêm phần tử vào cây nhị phân tìm kiếm:
    Node * addNode(Node *root, int value) {
        Node *temp = new Node(value);
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

    //! Tìm kiếm trong cây nhị phân:
    Node * Search_In_Tree(Node *root, int x) { //! O(log(n))
        if (root == NULL) {
            return NULL;
        } else {
            if (x < root->data) {
                Search_In_Tree(root->left, x);
            } else if (x > root->data) {
                Search_In_Tree(root->right, x);
            } else { // root->data == x
                return root; // trả về nút cần tìm.
            }
        }
    }


    //! hàm tìm node thế mạng:
    Node * Find_and_replace(Node *&p, Node *&tree) {
        if (tree->left != NULL) {
            tree->left = Find_and_replace(p, tree->left); // tìm ra node trái nhất
        } else { // đã tìm ra node trái nhất
            p->data = tree->data; // cập nhật lại data của node cần xóa bằng node thế mạng(hay node trái nhất vừa tìm được tree)
            p = tree; // trỏ nút p vào nút tree sẽ làm thế mạng bị xóa
            tree = tree->right; // bản chất tree->right = NULL, đê xóa Node trái nhất cuối cùng.
        }
        return p;
    }


    //! Xóa node có một con (con trái hoặc con phải):
    Node * DeleteNode(Node *root, int x) {
        if (root == NULL) 
            return NULL;
        else {
            if (x < root->data) {
                root->left = DeleteNode(root->left, x); // duyet sang trai cay
            } else if (x > root->data) {
                root->right = DeleteNode(root->right, x); // duyet sang ben phai cay
            } else { // x = root->data
                Node *p = root; // p là node ta đang đi tìm
                if (root->left == NULL) { // khong co node con ben trai
                    root = root->right;
                } else if (root->right == NULL) { // khong co node con ben phai
                    root = root->left;
                } else { //! Node can xoa la node co 2 con 
                    Find_and_replace(p, root->right); //! hàm tìm node thế mạng
                    // duyệt và tìm ra nút con trái nhất của cây con bên phải.
                }

                delete p; // xoa di node can xoa ban dau;
            }
        }
        return root;
    }


    //! Hàm hủy cây nhị phân:
    void DestroyTree(Node *&root) {
        if (root != NULL) { // chỉ có thể duyệt hậu tự (LRN) la xóa dần các nút gốc
            DestroyTree(root->left);
            DestroyTree(root->right);
            delete root;
        }
    }

    //! tim phan tu lon nhat trong cay:
    int Find_Max(Node *root) {
        int max = root->data; // gán max cho giá trị node đầu tiên
        if (root->left == NULL && root->right == NULL) {
            return max;
        }
        if (root->right != NULL) {
            int data_right = Find_Max(root->right);
            if (max < data_right) {
                max = data_right;
            }
        }   
        return max;
    }


    //! Tim phan tu nho nhat cua cay:
    int Find_Min(Node *root) {
        int min = root->data;
        if (root->left == NULL && root->right == NULL) {
            return min;
        }
        if (root->left != NULL) {
            int data_left = Find_Min(root->left);
            if (data_left < min) {
                min = data_left;
            }
        }
        return min;
    }


    //! Tìm bậc của câu nhị phân:
    int TreeLevel(Node *root) {
        if (root == NULL) return -1;
        return 1 + max(TreeLevel(root->left), TreeLevel(root->right));
    }


};


class PrintBinarySearchTree {
public:

    //! in node có 2 con:
    void Print_Node_2_Element(Node *root) {
        if (root != NULL) {
            if (root->left != NULL && root->right != NULL) {
                cout << root->data << " ";
            }
            Print_Node_2_Element(root->left); // duyet sang cay con trai
            Print_Node_2_Element(root->right); // duyet sang cay con phai
        }
    }


    //! in node co 1 con:
    void Print_Node_1_Element(Node *root) {
        if (root != NULL) {
            if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) {
                cout << root->data << " ";
            }
            Print_Node_1_Element(root->left);
            Print_Node_1_Element(root->right); 
        }
    }

    //! in node la:
    void Print_Node_La(Node *root) {
        if (root != NULL) {
            if (root->left == NULL && root->right == NULL) {
                cout << root->data << " ";
            }
            Print_Node_La(root->left);
            Print_Node_La(root->right);
        }
    
    }

    //! in cây theo NLR
    void Print_NLR(Node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            Print_NLR(root->left);
            Print_NLR(root->right);
        }
    }

};



int main() {
    Node *root = NULL;
    BinarySearchTree p1;
    PrintBinarySearchTree q1;

    while(true) {
        cout << "\n_____________Menu______________\n";
        cout << "\n1. Nhap du lieu cay";
        cout << "\n2. Xuat danh sach cay";
        cout << "\n3. Tim phan tu trong cay";
        cout << "\n4. Xuat danh sach cay co 2 con !";
        cout << "\n5. Xuat danh sach cay co 1 con !";
        cout << "\n6. Xuat danh sach cay co Node La !";
        cout << "\n7. Tim Max cua danh sach cay";
        cout << "\n8. Tim Min cua danh sach cay";
        cout << "\n9. Xoa Node bat ky trong danh sach cay";
        cout << "\n10. Xoa cay nhi phan tim kiem";
        cout << "\n11. Bac cua cay nhi phan tim kiem";
        cout << "\n0. Khet thuc!!!";
        cout << "\n_________________________________\n";
        int lc; cout << "Nhap vao lua chon: "; cin >> lc;

        if (lc == 1) {
            int x; cout << "Nhap vao gia tri can them vao: "; cin >> x;
            root = p1.addNode(root, x);
        } else if (lc == 2) {
            cout << "Xuat du lieu cay theo NLR: ";
            q1.Print_NLR(root);
        } else if (lc == 3) {
            cout << "Danh Sach: "; q1.Print_NLR(root); 
            int x; cout << "\nNhap vao phan tu can tim kiem: "; cin >> x;
            Node *p = p1.Search_In_Tree(root, x);
            if (p == NULL) {
                cout << "Phan tu " << x << " khong ton tai trong cay!!!";
            } else {
                cout << "Phan tu " << x << " co ton tai trong cay!!!";
            }
        } else if (lc == 0) {
            break;
        } else if (lc == 4) {
            cout << "Node co 2 con: ";
            q1.Print_Node_2_Element(root);
        } else if (lc == 5) {
            cout << "Node co 1 con(trai or phai): ";
            q1.Print_Node_1_Element(root);
        } else if (lc == 6) {
            cout << "Node la: ";
            q1.Print_Node_La(root);
        } else if (lc == 7) {
            cout << "Max: " << p1.Find_Max(root);
        } else if (lc == 8) {
            cout << "Min: " << p1.Find_Min(root);
        } else if (lc == 9) {
            int x; cout << "Nhap vao gia tri can xoa: "; cin >> x;
            p1.DeleteNode(root, x);
        } else if (lc == 10) {
            p1.DestroyTree(root);
        } else if (lc == 11) {
            cout << "Bac cua cay: " << p1.TreeLevel(root);
        }
    }

    return 0;
}
