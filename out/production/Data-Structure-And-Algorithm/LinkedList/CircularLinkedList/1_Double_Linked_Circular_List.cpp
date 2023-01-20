
//! DANH SÁCH LIÊN KẾT VÒNG ĐÔI:

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *previous;
};

struct List {
    Node *head;
    Node *tail;
};

Node *makeNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = temp;
    temp->previous = temp;
    return temp;
}

//! add vào đầu:
void addHead(List &l, int value) {
    Node *temp = makeNode(value);
    if (l.head == NULL) {
        l.head = l.tail = temp;
        l.tail->next = l.head;
        l.head->previous = l.tail;
    } else {
        Node *p = l.head;
        while(p->next != l.head) { //! tìm ra phần tử cuối cùng của danh sách:
            p = p->next;
        }
        
        temp->next = l.head; 
        p->next = temp; //! quay vòng.

        l.head->previous = temp;
        temp->previous = p; //! quay vòng.

        l.head = temp; //! l.head thành phần tử đầu danh sách.
    }
}   


//! add vào cuối:
// void addTail(List &l, int value) {
//     Node *temp = makeNode(value);

//     Node *p = l.head;



// }


//! in danh sach:
void in_danh_sach(List l) {
    cout << "\n____________________\n";
    Node *p = l.head;
    if (l.head != NULL) {
        do {
            cout << p->data << " ";
            p = p->next;
        } while(p != l.head);
    }
    cout << "\n____________________\n";
}


int main() {
    List l;


    while(1) {
        cout << "_________Menu______________\n";
        cout << "1. them vao dau danh sach\n";
        cout << "2. them vao cuoi danh sach\n";
        cout << "3. them vao giua danh sach\n";
        cout << "4. xoa phan tu dau danh sach\n";
        cout << "5. xoa phan tu cuoi danh sach\n";
        cout << "6. xoa phan ti vi tri bat ky\n";
        cout << "7. xuat danh sach lien ket\n";
        cout << "____________________________\n";
        cout << "Nhap vao lua chon: ";
        int x; cin >> x;
        if (x == 1) {
            int value; cout << "Nhap gia tri chen: ";cin >> value;
            addHead(l, value);
        } else if (x == 7) {
            in_danh_sach(l);
        }
    }


    return 0;
}



