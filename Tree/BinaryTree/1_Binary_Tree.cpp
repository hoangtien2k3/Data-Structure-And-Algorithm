
//! cây nhị phân:
/*
    ! Định nghĩa cây nhị phân:
    + Cây nhị phân là một cấu trúc dữ liệu bao gồm các nút được kết nối với nhau theo quan hệ 
    cha con với mỗi nút cha có tối đa 2 nút con.
        + Giá trị lưu tại nút đó. Giá trị này có thể là bất kỳ kiểu dữ liệu nào.
        + Địa chỉ nút gốc của cây con bên trái.
        + Địa chỉ nút gốc của cây con bên phải.


    ! Các loại cây nhị phân: 
        + Cây nhị phân đúng: là cây nhị phân mà mỗi nút của nó đều có bậc 2.
        + Cây nhị phân đầy đủ là cây nhị phân có mức của các nút lá đều bằng nhau.
        + Cây nhị phân tìm kiếm
        + Cây nhị phân cân bằng: số phần tử của cây con bên trái chênh lệch không quá 1 so với cây con bên phải.

*/

#include <iostream>
using namespace std;

struct tNode{
	int data;
	tNode *pLeft, *pRight;
};

void init(tNode *&root) {
    root = NULL;
}

//create new node
tNode *newNode(int data){
	tNode *node = new tNode;
	node->data = data;
	node->pLeft = NULL;
	node->pRight = NULL;
	return node;
}

//insert new Node into tree
void insertNode(tNode *p, int value){
	tNode *node = newNode(value);
	if (p->pLeft == NULL){
		p->pLeft = node;
	}else if (p->pRight == NULL) {
		p->pRight = node;
	}else{
		node->pLeft = p->pLeft;
		p->pLeft = node;
	}
}

//insert new Node into root:
void insertNewRoot(tNode *&root, int value){
	tNode *node = newNode(value);
	node->pLeft = root;
	root = node;
}

void LNR(tNode *root){
	if(root!=NULL){
		LNR(root->pLeft);
		if(root!=NULL){
			cout<<root->data<<" ";
		}
		LNR(root->pRight);
	}
}


int main() {
    tNode *root;
    init(root);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        insertNode(root, x);
    }
	
    LNR(root);

    return 0;
}