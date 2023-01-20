#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    int height;

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
        else {
            if (value < root->data) {
                root->left = insert(root->left, value);
            } else if (value > root->data) {
                root->right = insert(root->right, value);
            }
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


void PrintTreeAVL(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        PrintTreeAVL(root->left);
        PrintTreeAVL(root->right);
    }
}

int count1(Node *t, int x){
	if (t == NULL) return 0;
	if (t->data == x) return 1 + count1(t->left, x) + count1(t->right, x);
	else if (t->data < x) return count1(t->right, x);
	return count1(t->left, x);
}

int main() {
    Node* root = NULL;
    Insert p1;

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int value; cin >> value;
        root = p1.insert(root, value);
    }

    PrintTreeAVL(root);

    int x; cin >> x;
    cout << count1(root, x);


    return 0;
}