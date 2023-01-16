
#include<bits/stdc++.h>
using namespace std;


class SachGiaoKhoa {
public:
    string maSach, tenSach, nhaXB; 
    int soLuongBan;
    float donGiaBan;
    long long thanhTien;

};


class Node_SGK {
public:

    SachGiaoKhoa sgk;
    Node_SGK *next;

};


bool empty(Node_SGK *sgk) {
    return sgk == NULL;
}


int size(Node_SGK *sgk) {
    int count = 0;
    while(sgk != NULL) {
        ++count;
        sgk = sgk->next; 
    }
    return count;
}


Node_SGK * makeNode_SGK() {
    SachGiaoKhoa s;
    cout << "\nNHAP VAO THONG TIN SACH GIAO KHOA: " << endl;
    cout << "Nhap vao ma sach: "; cin.ignore(); getline(cin, s.maSach);
    cout << "Nhap vao ten sach: "; getline(cin, s.tenSach);
    cout << "Nhap vao nha xuat ban: "; getline(cin, s.nhaXB);
    cout << "Nhap vao so luong ban: "; cin >> s.soLuongBan;
    cout << "Nhap vao don gia ban: "; cin >> s.donGiaBan;
    // cout << "Nhap vao thanh tien: "; cin >> s.thanhTien;
    s.thanhTien = (long)s.soLuongBan * (long)s.donGiaBan;

    Node_SGK * temp = new Node_SGK;
    temp->sgk = s;
    temp->next = NULL;

    return temp;
}


void addHead(Node_SGK *&sgk) {
    Node_SGK *temp = makeNode_SGK();
    if (sgk == NULL) {
        sgk = temp;
    } else {
        temp->next = sgk;
        sgk = temp;
    }
}


void addTail(Node_SGK *&sgk) {
    Node_SGK *temp = makeNode_SGK();
    if (sgk == NULL) {
        sgk = temp;
    } else {
        Node_SGK * p = sgk;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}


void in_SGK(SachGiaoKhoa s) {
    cout << endl <<  "___________________________________________" << endl;

    cout << "Ma Sach: " << s.maSach << endl;
    cout << "Ten Sach: " << s.tenSach << endl;
    cout << "Nha Xuat Ban: " << s.nhaXB << endl;
    cout << "So Luong Ban: " << s.soLuongBan << endl;
    cout << "Don Gia Ban: " << s.donGiaBan << endl;
    cout << "Thanh Tien: " << s.thanhTien << endl;

    cout << endl <<  "___________________________________________" << endl;
}



void in_DanhSach_SachGiaoKhoa(Node_SGK *sgk) {
    cout << "\n==> DANH SACH SACH GIAO KHOA <===" << endl;
    while(sgk != NULL) {
        in_SGK(sgk->sgk);
        sgk = sgk->next;
    }
    cout << endl;
}


void Tim_Kiem_SGK(Node_SGK *sgk, string str) {
    SachGiaoKhoa ans;
    for(Node_SGK *p = sgk; p != NULL; p = p->next) {
        if ((p->sgk).tenSach == str) {
            cout << "Da Tim Thay Ten Sach Can Tim (Thong Tin Sach): " << endl;
            in_SGK(p->sgk);
            return;
        } 
    }
    cout << "Khong Tin Thay Sach Co Ten La: " << str << endl;
}


double Thanh_Tien(SachGiaoKhoa s) {
    return s.soLuongBan * s.donGiaBan;
}


void Sap_Xep_SGK_Giam_Dan(Node_SGK *&sgk) {

    for(Node_SGK *p = sgk; p->next != NULL; p = p->next) {
        Node_SGK *min = p;
        for(Node_SGK *q = p->next; q != NULL; q = q->next) {
            if (q->sgk.thanhTien > min->sgk.thanhTien) {
                min = q;
            }
        }
        SachGiaoKhoa temp = min->sgk;
        min->sgk = p->sgk;
        p->sgk = temp;
    }

}


double _Tong_Tien_Sach(Node_SGK *sgk) {

    float Sum = 0;
    while(sgk != NULL) {
        Sum += sgk->sgk.thanhTien;
        sgk = sgk->next;
    }

    return Sum;
}


bool _Check_So_Luong(SachGiaoKhoa s) {
    return (s.soLuongBan > 10) ? true : false;
}


void TenSach_SoLuongLonHon_10(Node_SGK *sgk) {
    Node_SGK *p = sgk;
    while(p != NULL) {
        if (_Check_So_Luong(p->sgk) == true) {
            cout << "Ten Sach: " << p->sgk.tenSach << endl;
        }
        p = p->next;
    }
}


void ThongTin_SGK_CoSoLuongNhoNhat(Node_SGK *sgk) {
    int Min = sgk->sgk.soLuongBan;
    int count = 0;

    Node_SGK * p = sgk;

    while(p != NULL) {
        if (p->sgk.soLuongBan < Min) {
            Min = p->sgk.soLuongBan;
        }
        p = p->next;
    }

    Node_SGK * q = sgk;
    while(q != NULL) {
        if (Min == q->sgk.soLuongBan) {
            in_SGK(q->sgk);
        }
        q = q->next;
    }

}


int main() {
    system("cls");

    Node_SGK *head = NULL;

    while(true) {
        cout << endl << "_________________MENU______________________" << endl;
        cout << "1. Nhap Danh Sach Sach Giao Khoa: " << endl;
        cout << "2. In Danh Sach Sach Giao Khao Da Nhap: " << endl;
        cout << "3. Tim Kiem Sach Giao Khao Co Ten La X: " << endl;
        cout << "4. Sap Xep Danh Sach Giam Dan Cua Thanh Tien: " << endl;
        cout << "5. Tinh Tong Tien Cua Cac Quyen Sach Giao Khoa Da Nhap: " << endl;
        cout << "6. Ten Cac Quyen Sach So Luong Lon Hon 10: " << endl;
        cout << "7. Thong Tin Day Du Cua Sach Giao Khao Co So Luong Nho Nhat: " << endl;

        cout << endl << "___________________________________________" << endl;
        cout << "--- Nhap Lua Chon ---: "; int lc; cin >> lc;

        if (lc == 1) {
            addTail(head);
        } else if (lc == 2) {
            in_DanhSach_SachGiaoKhoa(head);
        } else if (lc == 3) {
            string str; cout << "Nhap Vao Ten Sach Can Tim: "; cin.ignore();
            getline(cin, str);
            Tim_Kiem_SGK(head, str);
        } else if (lc == 4) {
            Sap_Xep_SGK_Giam_Dan(head);
        } else if (lc == 5) {
            cout << "Tong Tien Cua Cac Quyen Sach Giao Khoa Da Nhap: " << _Tong_Tien_Sach(head) << endl;
        } else if (lc == 6) {
            cout << "Ten Cac Quyen Sach So Luong Lon Hon 10: " << endl;
            TenSach_SoLuongLonHon_10(head);
        } else if (lc == 7) {
            cout << "Thong Tin Day Du Cua Sach Giao Khao Co So Luong Nho Nhat: " << endl;
            ThongTin_SGK_CoSoLuongNhoNhat(head);
        }

    }


    cin.get();
    return 0;
}