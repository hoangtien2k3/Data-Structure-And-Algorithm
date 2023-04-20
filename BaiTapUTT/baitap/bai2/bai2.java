package BaiTap.baitap.bai2;

import java.util.ArrayList;
import java.util.Scanner;

// Lớp cha quản lý thông tin của một thí sinh
class ThiSinh {
    protected String soBaoDanh;
    protected String hoTen;
    protected String diaChi;
    protected int uuTien;

    // Constructor
    public ThiSinh(String soBaoDanh, String hoTen, String diaChi, int uuTien) {
        this.soBaoDanh = soBaoDanh;
        this.hoTen = hoTen;
        this.diaChi = diaChi;
        this.uuTien = uuTien;
    }

    // Phương thức hiển thị thông tin của thí sinh
    public void hienThiThongTin() {
        System.out.println("Số báo danh: " + soBaoDanh);
        System.out.println("Họ tên: " + hoTen);
        System.out.println("Địa chỉ: " + diaChi);
        System.out.println("Ưu tiên: " + uuTien);
    }

    // Phương thức trả về số báo danh của thí sinh
    public String getSoBaoDanh() {
        return soBaoDanh;
    }
}

// Lớp con quản lý thông tin của một thí sinh khối A
class ThiSinhKhoiA extends ThiSinh {
    // Thuộc tính của thí sinh khối A
    private float diemToan;
    private float diemLy;
    private float diemHoa;

    // Constructor
    public ThiSinhKhoiA(String soBaoDanh, String hoTen, String diaChi, int uuTien, float diemToan, float diemLy, float diemHoa) {
        super(soBaoDanh, hoTen, diaChi, uuTien);
        this.diemToan = diemToan;
        this.diemLy = diemLy;
        this.diemHoa = diemHoa;
    }

    // Phương thức hiển thị thông tin của thí sinh khối A
    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Điểm toán: " + diemToan);
        System.out.println("Điểm lý: " + diemLy);
        System.out.println("Điểm hóa: " + diemHoa);
    }
}

// Lớp con quản lý thông tin của một thí sinh khối B
class ThiSinhKhoiB extends ThiSinh {
    // Thuộc tính của thí sinh khối B
    private float diemToan;
    private float diemHoa;
    private float diemSinh;

    // Constructor
    public ThiSinhKhoiB(String soBaoDanh, String hoTen, String diaChi, int uuTien, float diemToan, float diemHoa, float diemSinh) {
        super(soBaoDanh, hoTen, diaChi, uuTien);
        this.diemToan = diemToan;
        this.diemHoa = diemHoa;
        this.diemSinh = diemSinh;
    }

    // Phương thức hiển thị
    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Điểm toán: " + diemToan);
        System.out.println("Điểm hóa: " + diemHoa);
        System.out.println("Điểm sinh: " + diemSinh);
    }
}


// Lớp con quản lý thông tin của một thí sinh khối C
class ThiSinhKhoiC extends ThiSinh {
    // Thuộc tính của thí sinh khối C
    private float diemVan;
    private float diemSu;
    private float diemDia;
    // Constructor
    public ThiSinhKhoiC(String soBaoDanh, String hoTen, String diaChi, int uuTien, float diemVan, float diemSu, float diemDia) {
        super(soBaoDanh, hoTen, diaChi, uuTien);
        this.diemVan = diemVan;
        this.diemSu = diemSu;
        this.diemDia = diemDia;
    }

    // Phương thức hiển thị thông tin của thí sinh khối C
    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Điểm văn: " + diemVan);
        System.out.println("Điểm sử: " + diemSu);
        System.out.println("Điểm địa: " + diemDia);
    }
}


// Lớp quản lý thông tin về tuyển sinh
class TuyenSinh {
    private ArrayList<ThiSinh> danhSachThiSinh; // Danh sách các thí sinh đăng ký dự thi

    // Constructor
    public TuyenSinh() {
        danhSachThiSinh = new ArrayList<ThiSinh>();
    }

    // Phương thức thêm một thí sinh vào danh sách
    public void themThiSinh(ThiSinh thiSinh) {
        danhSachThiSinh.add(thiSinh);
    }

    // Phương thức nhập thông tin về các thí sinh
    public void nhapThongTin() {
        Scanner sc = new Scanner(System.in);
        int soThiSinh;
        System.out.print("Nhập số lượng thí sinh: ");
        soThiSinh = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < soThiSinh; i++) {
            System.out.println("Thông tin thí sinh thứ " + (i + 1));
            System.out.print("Số báo danh: ");
            String soBaoDanh = sc.nextLine();
            System.out.print("Họ tên: ");
            String hoTen = sc.nextLine();
            System.out.print("Địa chỉ: ");
            String diaChi = sc.nextLine();
            System.out.print("Ưu tiên: ");
            int uuTien = sc.nextInt();
            sc.nextLine();
            System.out.print("Khối thi (A/B/C): ");
            String khoiThi = sc.nextLine();
            switch (khoiThi) {
                case "A":
                    System.out.print("Điểm toán: ");
                    float diemToan = sc.nextFloat();
                    System.out.print("Điểm lý: ");
                    float diemLy = sc.nextFloat();
                    System.out.print("Điểm hóa: ");
                    float diemHoa = sc.nextFloat();
                    sc.nextLine();
                    ThiSinhKhoiA thiSinhKhoiA = new ThiSinhKhoiA(soBaoDanh, hoTen, diaChi, uuTien, diemToan, diemLy, diemHoa);
                    themThiSinh(thiSinhKhoiA);
                    break;
                case "B":
                    System.out.print("Điểm toán: ");
                    float diemToanB = sc.nextFloat();
                    System.out.print("Điểm hóa: ");
                    float diemHoaB = sc.nextFloat();
                    System.out.print("Điểm sinh: ");
                    float diemSinh = sc.nextFloat();
                    sc.nextLine();
                    ThiSinhKhoiB thiSinhKhoiB = new ThiSinhKhoiB(soBaoDanh, hoTen, diaChi, uuTien, diemToanB, diemHoaB, diemSinh);
                    themThiSinh(thiSinhKhoiB);
                    break;
                case "C":
                    System.out.print("Điểm văn: ");
                    float diemVan = sc.nextFloat();
                    System.out.print("Điểm sử: ");
                    float diemSu = sc.nextFloat();
                    System.out.print("Điểm địa: ");
                    float diemDia = sc.nextFloat();
                    sc.nextLine();
                    ThiSinhKhoiC thiSinhKhoiC = new ThiSinhKhoiC(soBaoDanh, hoTen, diaChi, uuTien, diemVan, diemSu, diemDia);
                    themThiSinh(thiSinhKhoiC);
                    break;
                default:
                    System.out.println("Khối thi không hợp lệ");
                    i--;
                    break;
            }
        }
    }

    // Phương thức hiển thị thông tin của tất cả các thí sinh trong danh sách
    public void hienThiThongTin() {
        for (ThiSinh thiSinh : danhSachThiSinh) {
            thiSinh.hienThiThongTin();
        }
    }

    // Phương thức tìm kiếm thí sinh theo số báo danh
    public void timKiemTheoSoBaoDanh(String soBaoDanh) {
        boolean timThay = false;
        for (ThiSinh thiSinh : danhSachThiSinh) {
            if (thiSinh.getSoBaoDanh().equals(soBaoDanh)) {
                thiSinh.hienThiThongTin();
                timThay = true;
                break;
            }
        }
        if (!timThay) {
            System.out.println("Không tìm thấy thí sinh có số báo danh là " + soBaoDanh);
        }
    }

    // Phương thức kết thúc chương trình
    public void ketThuc() {
        System.out.println("Kết thúc chương trình");
    }
}

// Lớp chạy chương trình
public class bai2 {
    public static void main(String[] args) {
        TuyenSinh tuyenSinh = new TuyenSinh();
        tuyenSinh.nhapThongTin();
        // Hiển thị menu và thực hiện các chức năng
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("----- Menu -----");
            System.out.println("1. Nhập thông tin các thí sinh");
            System.out.println("2. Hiển thị thông tin các thí sinh");
            System.out.println("3. Tìm kiếm thí sinh theo số báo danh");
            System.out.println("4. Kết thúc chương trình");
            System.out.print("Vui lòng chọn chức năng (1-4): ");
            int choice = sc.nextInt();
            sc.nextLine();
            switch (choice) {
                case 1:
                    tuyenSinh.nhapThongTin();
                    break;
                case 2:
                    tuyenSinh.hienThiThongTin();
                    break;
                case 3:
                    System.out.print("Nhập số báo danh: ");
                    String soBaoDanh = sc.nextLine();
                    tuyenSinh.timKiemTheoSoBaoDanh(soBaoDanh);
                    break;
                case 4:
                    tuyenSinh.ketThuc();
                    return;
                default:
                    System.out.println("Vui lòng chọn chức năng từ 1 đến 4");
                    break;
            }
        }
    }
}

/*
    Kết quả chạy chương trình:

    ----- Menu -----

    Nhập thông tin các thí sinh
    Hiển thị thông tin các thí sinh
    Tìm kiếm thí sinh theo số báo danh
    Kết thúc chương trình
    Vui lòng chọn chức năng (1-4): 1
    Số lượng thí sinh cần nhập: 2
    Nhập thông tin thí sinh thứ 1:
    Số báo danh: A001
    Họ tên: Nguyễn Văn A
    Địa chỉ: Hà Nội
    Khối thi (A/B/C): A
    Điểm toán: 8.5
    Điểm lý: 7.75
    Điểm hóa: 9.0
    Nhập thông tin thí sinh thứ 2:
    Số báo danh: B001
    Họ tên: Trần Thị B
    Địa chỉ: Hồ Chí Minh
    Khối thi (A/B/C): B
    Điểm toán: 9.0
    Điểm hóa: 8.5
    Điểm sinh: 7.75
    ----- Menu -----
    Nhập thông tin các thí sinh
    Hiển thị thông tin các thí sinh
    Tìm kiếm thí sinh theo số báo danh
    Kết thúc chương trình
    Vui lòng chọn chức năng (1-4): 2
    Thông tin các thí sinh:
    Thí sinh A001 - Nguyễn Văn A - Hà Nội - Ưu tiên: 0
    Khối thi: A
    Điểm toán: 8.5
    Điểm lý: 7.75
    Điểm hóa: 9.0
    Thí sinh B001 - Trần Thị B - Hồ Chí Minh - Ưu tiên: 0
    Khối thi: B
    Điểm toán
    Điểm hóa: 8.5
    Điểm sinh: 7.75
    ----- Menu -----

    Nhập thông tin các thí sinh
    Hiển thị thông tin các thí sinh
    Tìm kiếm thí sinh theo số báo danh
    Kết thúc chương trình
    Vui lòng chọn chức năng (1-4): 3
    Nhập số báo danh: A001
    Thông tin thí sinh có số báo danh A001:
    Thí sinh A001 - Nguyễn Văn A - Hà Nội - Ưu tiên: 0
    Khối thi: A
    Điểm toán: 8.5
    Điểm lý: 7.75
    Điểm hóa: 9.0
    ----- Menu -----
    Nhập thông tin các thí sinh
    Hiển thị thông tin các thí sinh
    Tìm kiếm thí sinh theo số báo danh
    Kết thúc chương trình
    Vui lòng chọn chức năng (1-4): 4
    Chương trình kết thúc.
*/



