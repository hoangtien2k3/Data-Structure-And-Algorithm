
// quản lý danh sách sinh viên theo danh sách liên kết đơn

#include<bits/stdc++.h>
using namespace std;


struct Student {
    string name, id;
    double gpa;
};


struct NodeSV {
    Student s;
    NodeSV *next;
};


NodeSV *makeNode() {
    Student s;
    cout << "Nhap Thong Tin Sinh Vien: \n";
    cout << "Nhap vao ID: "; cin >> s.id;
    cout << "Nhap vao ten: "; cin.ignore();
    getline(cin, s.name);
    cout << "Nhap gpa: "; cin >> s.gpa;
    NodeSV *temp = new NodeSV();
    temp->s = s;
    temp->next = NULL;
    return temp;
}

bool empty(NodeSV *a) {
    return a == NULL;
}

int size(NodeSV *a) {
    int count = 0;
    while(a != NULL) {
        ++count;
        a = a->next; // cho node hiện tại nhảy sang node tiếp theo // (giống như i++)
    }
    return count;
}

// thêm phần tử vào đầu danh sách:
void addHead(NodeSV* &a) {
    NodeSV *temp = makeNode();
    if (a == NULL) {
        a = temp; // gán luôn a cho node ta thêm vào( vì a là phần tử đầu danh sách liên kết)
    } else {
        temp->next = a; // liên kết temp với danh sách liên kết
        a = temp; // a nhảy về phần tử đầu tiên.
    }
}

// thêm phần tử vào cuối danh sách:
void addTail(NodeSV* &a) {
    NodeSV *temp = makeNode();
    if (a == NULL) {
        a = temp;
    } else {
        NodeSV *p = a; // để danh sách không bị biến đổi
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

// thêm một phâng tử vào giữa:
void addMiddle(NodeSV* &a, int pos) {
    int n = size(a);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri chen khong hop le!"; return;
    } else if (pos == 1) {
        addHead(a); 
        return;
    } else if (n == pos + 1) {
        addTail(a);
        return;
    } else {
        NodeSV *p = a;
        for(int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        NodeSV *temp = makeNode();
        temp->next = p->next;
        p->next = temp;
    }
}

// xóa phần tử ở đầu:
void deleteHead(NodeSV* &a) {
    if (a == NULL) return;
    a = a->next;
}

// xóa phần tử ở cuối:
void deleteTail(NodeSV* &a) {
    if (a == NULL) return;
    NodeSV *truoc = NULL;
    NodeSV *sau = a;
    while(sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        a = NULL;
    } else {
        truoc->next = NULL;
    }
}
    
// xóa phần tử ở giữa:
void deleteMiddle(NodeSV* &a, int pos) {
    if (pos <= 0 || pos > size(a)) return;
    NodeSV *truoc = NULL;
    NodeSV *sau = a;
    for(int i = 1; i < pos; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        a = a->next;
    } else {
        truoc->next = sau->next;
    }
}

// sắp xếp theo thứ tự tăng dần trong danh sách liên kết:
void sapxep(NodeSV* &a) { // selection sort
    for(NodeSV *p = a; p->next != NULL; p = p->next) {
        NodeSV *min = p;
        for(NodeSV *q = p->next; q != NULL; q = q->next) {
            if (q->s.gpa < min->s.gpa) {
                min = q;
            }
        }
        Student temp = min->s;
        min->s = p->s;
        p->s = temp;
    }
}

void in(Student s) {
    cout << "\n____________________________\n";
    cout << "ID: " << s.id << endl;
    cout << "Ho Ten: " << s.name << endl;
    cout << "GPA: " << fixed << setprecision(2) << s.gpa << endl;
    cout << "\n____________________________\n";
}

// in danh sach:
void in_danh_sach(NodeSV *a) {
    cout << "Danh Sach Sinh Vien: \n";
    while(a != NULL) {
        in(a->s);
        a = a->next;
    }
    cout << endl;
}

int main() {
    NodeSV *head = NULL; // node đầu tiên bằng NULL
    while(1) {
        cout << "____________Menu__________\n";
        cout << "1. chen sinh vien o dau danh sach\n";
        cout << "2. chen sinh vien o cuoi danh sach\n";
        cout << "3. chen sinh vien o giua danh sach\n";
        cout << "4. xoa phan tu o dau\n";
        cout << "5. xoa phan tu o cuoi\n";
        cout << "6. xoa phan tu o giua\n";
        cout << "7. duyet danh sach lien ket\n";
        cout << "8. sap xep sinh vien theo GPA tang dan\n";
        cout << "0. KET THUC CHUONG TRINH\n";
        cout << "___________________________\n";
        cout << "---Nhap lua chon---: ";
        int lc; cin >> lc;
        if (lc == 1) {
            addHead(head);
        } else if (lc == 2) {
            addTail(head);
        } else if (lc == 3) {
            int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
            addMiddle(head, pos);
        } else if (lc == 4) {
            deleteHead(head);
        } else if (lc == 5) {
            deleteTail(head);
        } else if (lc == 6) {
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteMiddle(head, pos); 
        } else if (lc == 7) {
            in_danh_sach(head);
        } else if (lc == 8){
            sapxep(head);
        } else if (lc == 0) {
            break;
        }
    }  

    return 0; 
}

