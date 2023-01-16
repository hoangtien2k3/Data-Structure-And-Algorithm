
/*
    Đề Số 2:
    * Đề bài: Cài đặt chương trình sử dụng danh sách liên kết đơn(hoặc liên kết kép) để quản lý
    SachGiaoKhoa theo yêu cầu sau:

    * Thông tin SachGiaoKhoa gồm: MaSach(Mã sách giáo khao), TenSach(Tên sách),
    NhaXB(Nhà xuất bản), SoLuongBan(Số lượng bán), DonGiaBan(Đơn giá bán)
    ThanhTien(Thành tiền)

    Trong đó: ThanhTien = SoLuongBan * DonGiaBan

    * Thao tác cần thực hiện:
    Yếu cầu 1: Nhâp danh sách sách giáo khoa từ bàn phím và lưu vào DSLK Đơn (hoặc DSLK kép)
    Yêu cầu 2: In danh sách sách giáo khoa đã nhập
    Yêu cầu 3: Tìm kiếm sách giáo khoa có tên là X nào đó, với X nhập vào từ bàn phím.
    Yêu cầu 4: Sắp xếp danh sách giáo khoa với thứ tự giảm dần của thành tiền.
    Yêu cầu 5: Tính tổng tiền của các quyển giáo khoa đã nhập.
    Yêu cầu 6: Hiển thị tên các quyển sách giáo khoa có số lượng > 10.
    Yêu cầu 7: Cho biết tên(hoặc thông tin đầy đủ) của sách giáo khoa số lượng nhỏ nhất.

*/

#include <bits/stdc++.h>
using namespace std;

struct SachGiaoKhoa
{
    string maSach, tenSach, nhaXB;
    int soLuongBan;
    float donGiaBan;
    long long thanhTien;
};

class Node_SGK
{
public:
    SachGiaoKhoa sgk;
    Node_SGK *next;

    bool empty(Node_SGK *);
    int size(Node_SGK *);
    Node_SGK *makeNode_SGK();
    void addHead(Node_SGK *&);
    void addTail(Node_SGK *&);
    void in_SGK(SachGiaoKhoa);
    void in_DanhSach_SachGiaoKhoa(Node_SGK *);
    void Tim_Kiem_SGK(Node_SGK *, string);
    double Thanh_Tien(SachGiaoKhoa);
    void Sap_Xep_SGK_Giam_Dan(Node_SGK *&);
    double _Tong_Tien_Sach(Node_SGK *);
    bool _Check_So_Luong(SachGiaoKhoa);
    void TenSach_SoLuongLonHon_10(Node_SGK *);
    void ThongTin_SGK_CoSoLuongNhoNhat(Node_SGK *);
    
};

bool Node_SGK::empty(Node_SGK *sgk)
{
    return sgk == NULL;
}

int Node_SGK::size(Node_SGK *sgk)
{
    int count = 0;
    while (sgk != NULL)
    {
        ++count;
        sgk = sgk->next;
    }
    return count;
}

Node_SGK *Node_SGK::makeNode_SGK()
{
    SachGiaoKhoa s;
    static int i = 1;
    cout << "\n=> NHAP VAO THONG TIN SACH GIAO KHOA THU " << i++ << ": " << endl;
    cout << "\t+ Nhap vao Ma Sach: ";
    cin.ignore();
    getline(cin, s.maSach);
    cout << "\t+ Nhap vao Ten Sach: ";
    getline(cin, s.tenSach);
    cout << "\t+ Nhap vao Nha Xuat Ban: ";
    getline(cin, s.nhaXB);
    cout << "\t+ Nhap vao So Luong Ban: ";
    cin >> s.soLuongBan;
    cout << "\t+ Nhap vao Don Gia Ban: ";
    cin >> s.donGiaBan;
    // cout << "Nhap vao thanh tien: "; cin >> s.thanhTien;
    s.thanhTien = (long)s.soLuongBan * (long)s.donGiaBan;

    Node_SGK *temp = new Node_SGK;
    temp->sgk = s;
    temp->next = NULL;

    return temp;
}

void Node_SGK::addHead(Node_SGK *&sgk)
{
    Node_SGK *temp = makeNode_SGK();
    if (sgk == NULL)
    {
        sgk = temp;
    }
    else
    {
        temp->next = sgk;
        sgk = temp;
    }
}

void Node_SGK::addTail(Node_SGK *&sgk)
{
    Node_SGK *temp = makeNode_SGK();
    if (sgk == NULL)
    {
        sgk = temp;
    }
    else
    {
        Node_SGK *p = sgk;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void Node_SGK::in_SGK(SachGiaoKhoa s)
{

    cout << "\t\t+ Ma Sach: " << s.maSach << endl;
    cout << "\t\t+ Ten Sach: " << s.tenSach << endl;
    cout << "\t\t+ Nha Xuat Ban: " << s.nhaXB << endl;
    cout << "\t\t+ So Luong Ban: " << s.soLuongBan << endl;
    cout << "\t\t+ Don Gia Ban: " << s.donGiaBan << endl;
    cout << "\t\t+ Thanh Tien: " << s.thanhTien << endl;

    cout << "_____________________________________________________" << endl;
}

void Node_SGK::in_DanhSach_SachGiaoKhoa(Node_SGK *sgk)
{
    cout << "\n\t=====> DANH SACH - SACH GIAO KHOA <=====" << endl;
    cout << "_____________________________________________________" << endl;
    int i = 1;
    while (sgk != NULL)
    {
        cout << "\t-> Thong Tin Sach Giao Khoa Thu " << i++ << ": " << endl;
        sgk->in_SGK(sgk->sgk);
        sgk = sgk->next;
    }
    cout << endl;
}

void Node_SGK::Tim_Kiem_SGK(Node_SGK *sgk, string str)
{
    SachGiaoKhoa ans;
    for (Node_SGK *p = sgk; p != NULL; p = p->next)
    {
        if ((p->sgk).tenSach == str)
        {
            cout << endl
                 << "______________________________________________________" << endl;
            cout << "==> Da Tim Thay Ten Sach Can Tim (Thong Tin Sach):  " << str << endl;
            in_SGK(p->sgk);
            return;
        }
    }
    cout << "Khong Tin Thay Sach Co Ten La: " << str << endl;
}

double Node_SGK::Thanh_Tien(SachGiaoKhoa s)
{
    return s.soLuongBan * s.donGiaBan;
}

void Node_SGK::Sap_Xep_SGK_Giam_Dan(Node_SGK *&sgk)
{
    for (Node_SGK *p = sgk; p->next != NULL; p = p->next)
    {
        Node_SGK *min = p;
        for (Node_SGK *q = p->next; q != NULL; q = q->next)
        {
            if (q->sgk.thanhTien > min->sgk.thanhTien)
            {
                min = q;
            }
        }
        SachGiaoKhoa temp = min->sgk;
        min->sgk = p->sgk;
        p->sgk = temp;
    }
}

double Node_SGK::_Tong_Tien_Sach(Node_SGK *sgk)
{
    float Sum = 0;
    while (sgk != NULL)
    {
        Sum += sgk->sgk.thanhTien;
        sgk = sgk->next;
    }
    return Sum;
}

bool Node_SGK::_Check_So_Luong(SachGiaoKhoa s)
{
    return (s.soLuongBan > 10) ? true : false;
}

void Node_SGK::TenSach_SoLuongLonHon_10(Node_SGK *sgk)
{
    Node_SGK *p = sgk;
    while (p != NULL)
    {
        if (p->_Check_So_Luong(p->sgk) == true)
        {
            cout << "\t\t+ Ten Sach: " << p->sgk.tenSach << endl;
        }
        p = p->next;
    }
}

void Node_SGK::ThongTin_SGK_CoSoLuongNhoNhat(Node_SGK *sgk)
{
    int Min = sgk->sgk.soLuongBan;
    int count = 0;

    Node_SGK *p = sgk;

    while (p != NULL)
    {
        if (p->sgk.soLuongBan < Min)
        {
            Min = p->sgk.soLuongBan;
        }
        p = p->next;
    }

    Node_SGK *q = sgk;
    while (q != NULL)
    {
        if (Min == q->sgk.soLuongBan)
        {
            in_SGK(q->sgk);
        }
        q = q->next;
    }
}

int main()
{
    system("cls");

    Node_SGK *head = NULL;

    do
    {
        cout << endl
             << endl;
        cout << "********************************************************************" << endl;
        cout << "**  _______________________MENU_______________________________    **" << endl;
        cout << "**  1. Nhap Danh Sach Sach Giao Khoa.                             **" << endl;
        cout << "**  2. In Danh Sach Sach Giao Khao Da Nhap.                       **" << endl;
        cout << "**  3. Tim Kiem Sach Giao Khao Co Ten La X.                       **" << endl;
        cout << "**  4. Sap Xep Danh Sach Giam Dan Cua Thanh Tien.                 **" << endl;
        cout << "**  5. Tinh Tong Tien Cua Cac Quyen Sach Giao Khoa Da Nhap.       **" << endl;
        cout << "**  6. Ten Cac Quyen Sach So Luong Lon Hon 10.                    **" << endl;
        cout << "**  7. Thong Tin Day Du Cua Sach Giao Khao Co So Luong Nho Nhat.  **" << endl;
        cout << "**  8. Nhan So 8, Hoac Ky Tu Bat Ky De Ket Thuc Chuong Tinh.      **" << endl;
        cout << "********************************************************************" << endl;

        cout << "______________________________________________________" << endl;
        cout << "---> Nhap Lua Chon --->:  ";
        int lc;
        cin >> lc;

        switch (lc)
        {
        case 1:
        {
            head->addTail(head);
            break;
        }
        case 2:
        {
            head->in_DanhSach_SachGiaoKhoa(head);
            break;
        }
        case 3:
        {
            string str;
            cout << "Nhap Vao Ten Sach Can Tim: ";
            cin.ignore();
            getline(cin, str);
            head->Tim_Kiem_SGK(head, str);
            break;
        }
        case 4:
        {
            head->Sap_Xep_SGK_Giam_Dan(head);
            cout << "==> Da Sap Xep Danh Sach Dam Dan Cua Thanh Tien!!!" << endl;
            break;
        }
        case 5:
        {
            cout << "==> Tong Tien Cua Cac Quyen Sach Giao Khoa Da Nhap:  " << head->_Tong_Tien_Sach(head) << endl;
            break;
        }
        case 6:
        {
            cout << "==> Ten Cac Quyen Sach So Luong Lon Hon 10: " << endl;
            head->TenSach_SoLuongLonHon_10(head);
            break;
        }
        case 7:
        {
            cout << "=> Thong Tin Day Du Cua Sach Giao Khao Co So Luong Nho Nhat: " << endl;
            head->ThongTin_SGK_CoSoLuongNhoNhat(head);
            break;
        }
        default:
        {
            system("cls");
            return 0;
        }
        }
    } while (true);

    cin.get();
    return 0;
}
