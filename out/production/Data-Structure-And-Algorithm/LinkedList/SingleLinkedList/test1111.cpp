
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node * makeNode(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

struct List {
    Node *head;
    Node *tail;
};


Node * addHead(List *&list, int x) {
    Node *temp = makeNode(x);
    if (list->head == NULL) {
        list->head = temp; 
    } else {
        temp->next = list->head; 
        list->head = temp; 
    }
    return list->head;
}

Node * addTail(List *&list, int x) {
    Node *temp = makeNode(x);
    if (list->head == NULL) {
        list->head = temp;
    } else {
        Node *p = list->head; 
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return list->head;
}


//! Single Linklist: Xóa Node Có Giá Trị Value
Node * _deleteNode_Value(List * &list, int value) {
    if (list->head == NULL) {
        return NULL;
    } else {
        Node *p = list->head;
        while(p->next->data != value) {
            p = p->next; //! index
        }
        p->next = p->next->next; //! xóa node cần xóa.
    }
    return list->head;
}


//! in danh sach:
void in_danh_sach(List *list) {
    cout << "\n____________________________\n";
    while(list->head != NULL) {
        cout << list->head->data << " ";
        list->head = list->head->next;
    }
    cout << "\n____________________________\n";
}


int main() {

    List *list; // node đầu tiên bằng NULL

    while(1) {
        cout << "____________Menu________________\n";
        cout << "1. chen phan tu vao dau danh sach\n";
        cout << "2. chen phan tu vao cuoi danh sach\n";
        cout << "3. chen phan tu vao giua danh sach\n";
        cout << "9. in ra danh sach lien ket !!!\n";
        cout << "0. KET THUC CHUONG TRINH\n";
        cout << "________________________________\n";
        cout << "---Nhap lua chon---: ";
        int lc; cin >> lc;
        if (lc == 1) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            addHead(list, x);
        } else if (lc == 2) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            addTail(list, x);
        } else if (lc == 3) {
            int value; cout << "Nhap vao gia tri can xoa: "; cin >> value;
            _deleteNode_Value(list, value);
        } else if (lc == 9) {
            in_danh_sach(list);
        } else if (lc == 0) {
            break;
        }
    }   



}


    
















