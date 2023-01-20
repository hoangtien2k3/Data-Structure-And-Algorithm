
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    int height;
    
public:
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};


class Rotate {
public:

    // lay ra chieu cao cau cay
    int getHeight(Node *root) {
        if (root == NULL) 
            return 0;
        return root->height;
    }

    // lay ra chi so can bang:
    int valueBalance(Node *root) {
        if (root == NULL)
            return 0;
        return getHeight(root->left) - getHeight(root->right);
    }

    Node *rightRotate(Node *root) { // quay phai
        Node *x = root->left;

        root->left = x->right;
        x->right = root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node *leftRotate(Node *root) { // quay trai
        Node *y = root->right;

        root->right = y->left;
        y->left = root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

};



class Insert : public Rotate {
public:
    Node *insert(Node *root, int value) {
        if (root == NULL)
            return new Node(value);
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        } else {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int valueBalance = getHeight(root->left) - getHeight(root->right);

        // left-left
        if (valueBalance > 1 && value < root->left->data) {
            return rightRotate(root);
        }

        // right-right
        if (valueBalance < -1 && value > root->right->data) {
            return leftRotate(root);
        }

        // left-right
        if (valueBalance > 1 && value > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // right-left
        if (valueBalance < -1 && value < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
};



class Delete : public Rotate {
public:

    Node *maxValueNode(Node *root) { // lấy ra giá trị lớn nhất
        Node *current = root;
        
        while(current->right != NULL) {
            current = current->right;
        }

        return current;
    }

    Node *deleteNodeAVL(Node *root, int value) {
        // STEP 1: PERFORM STANDARD BST DELETE
        if (root == NULL)
            return root;

        if (value < root->data) {
            root->left = deleteNodeAVL(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNodeAVL(root->right, value);
        } else { // đã tìm ra node cần xóa đi

            // trường hợp 0 hoặc 1 cây con
            if (root->left == NULL || root->right == NULL) {
                Node *temp = root->left ? root->left : root->right;

                // No child case
                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else { // one child case
                    *root = *temp; // Gán tất cả các giá trị (bao gồm left, right, height) của temp vào root
                    free(temp);
                }
            }

            // trường hợp 2 con: two child case
            else {

                // Tìm node lớn nhất bên trái, hoặc nhỏ nhất bên phải
                Node *temp = maxValueNode(root->left);

                // dua data cua temp vao root
                root->data = temp->data;

                root->right = deleteNodeAVL(root->right, temp->data);
            }
        }

        // neu cay khong con gi
        if (root == NULL) 
            return root;
    

        // cap nhat chieu cao cho cay:
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // 3. CÂN BẰNG CÂY - GET THE BALANCE FACTOR
        int valBalance = valueBalance(root);

        // chi so can bang cau cay:
        if (valBalance > 1 && valueBalance(root->left) >= 0)
        return rightRotate(root);
 
        // Case 2: Right right - Phải phải
        if (valBalance < -1 && valueBalance(root->right) <= 0)
            return leftRotate(root);
    
        // Case 3: Left right - Trái phải
        if (valBalance > 1 && valueBalance(root->left) < 0){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    
        // Case 4: Right left - Phải trái
        if (valBalance < -1 && valueBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    
        return root;
    }

};

void PrintTreeAVL(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        PrintTreeAVL(root->left);
        PrintTreeAVL(root->right);
    }
}

int treeLevel(Node *root){ // lấy ra chiều cao của cây:
	if (root == NULL) 
        return -1;
	return 1 + max(treeLevel(root->left), treeLevel(root->right));
}


int main() {

    Node* root = NULL;
    Insert p1;
    Delete q1;

    while(1) {
        cout << "\n___________Menu_______________";
        cout << "\n1. Chen doi tuong vao cay AVL";
        cout << "\n2. Xoa doi tuong trong cay AVL";
        cout << "\n3. In ra doi tuong cay AVL";
        cout << "\n______________________________\n";
        
        int lc; cout << "Nhap vao lua chon: "; cin >> lc;
        if (lc == 1) {
            int value; cout << "Nhap vao doi tuong can chen: "; cin >> value;
            root = p1.insert(root, value);
        } else if (lc == 2) {
            int value; cout << "Nhap vao doi tuong can xoa: "; cin >> value;
            root = q1.deleteNodeAVL(root, value); 
        } else if (lc == 3) {
            cout << "Cay AVL: ";
            PrintTreeAVL(root);
        }
    }


    return 0;
}

