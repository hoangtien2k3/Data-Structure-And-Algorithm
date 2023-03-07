#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <math.h>
#include <list>
#include <time.h>
#include <bitset>
#include <algorithm>
using namespace std;

class BST {
public:
    int key, height, count;
    BST *left, *right;

    BST():
        key(0), count(0), height(0), left(NULL), right(NULL){}

    BST(int key):
        key(key), height(1), count(1), left(NULL), right(NULL){}

    int getHeight(BST *root){
        if (!root)
            return 0;
        return root -> height;
    }

    int getBalanceFactor(BST *root){
        if (!root)
            return 0;
        return getHeight(root -> left) - getHeight(root -> right);
    }    

    int max(int a, int b){
        return a > b ? a : b;
    }

    BST* rightRotate(BST *z){
        BST* y = z -> left;
        BST* x = y -> right;

        y -> right = z;
        z -> left = x;

        z -> height = 1 + max(getHeight(z -> left), getHeight(z -> right));
        y -> height = 1 + max(getHeight(y -> left), getHeight(y -> right));
        
        return y;
    }

    BST* leftRotate(BST *y){
        BST* x = y -> right;
        BST* t2 = x -> left;

        x -> left = y;
        y -> right = t2;

        y -> height = 1 + max(getHeight(y -> left), getHeight(y -> right));
        x -> height = 1 + max(getHeight(x -> left), getHeight(x -> right));
        
        return x;
    }

    BST* Insert(BST* root, int key){
        if (!root)
            return new BST(key);
        if (key < root -> key)
            root -> left = Insert(root -> left, key);
        else if (key > root -> key)
            root -> right = Insert(root -> right, key);
        else
            root -> count++;

        root -> height = 1 + max(getHeight(root -> left), getHeight(root -> right));

        int b = getBalanceFactor(root);

        //left left case
        if (b > 1 && key < root -> left -> key)
            return rightRotate(root);
        
        // left right case
        if (b > 1 && key > root -> left -> key){
            root -> left = leftRotate(root -> left);
            return rightRotate(root);
        }
        // right right case
        if (b < -1 && key > root -> right -> key)
            return leftRotate(root);

        // right left case
        if (b < -1 && key < root -> right -> key){
            root -> right = rightRotate(root -> right);
            return leftRotate(root);
        }
        return root;
    }

    int solve(BST *root, int key){
        if (!root)
            return 0;
        if (key < root -> key)
            return solve(root -> left, key);
        if (key > root -> key)
            return solve(root -> right, key);
        return root -> count;
    }
};


void PrintTreeAVL(BST *root) {
    if (root != NULL) {
        cout << root->key << " ";
        PrintTreeAVL(root->left);
        PrintTreeAVL(root->right);
    }
}

int main(){
    BST b;
    BST* root = NULL;
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++){
        int val;
        cin >> val;
        root = b.Insert(root, val);
    }
    

    PrintTreeAVL(root);



}