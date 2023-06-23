package BaiTapUTT.BaiTapGhiFileVoiLuongChar.Bai2;


/*
    Định nghĩa các lớp theo yêu cầu sau:
        a. Hãy định nghĩa class Sinhvien với các thuộc tính: mã sinh viên, họ tên,
        ngày sinh, giới tính, điểm trung bình và các phương thức khởi tạo,
        hiển thị thông tin.
        b. Định nghĩa class SinhvienHTTT kế thừa từ sinhvien, có thêm thuộc
        tính: học phí và phương thức khởi tạo, hiển thị thông tin.
        c. Định nghĩa class SinhvienUTT kế thừa từ Sinhvien, có thêm thuộc tính:
        đơn vị, lương và phương thức khởi tạo, hiển thị thông tin.
    Yêu cầu:
        Thiết kế các phương thức cho phép nhập dữ liệu sinh viên. Sinh viên UTT
        thì lưu dữ liệu vào file svutt.dat, sinh viên HTTT thì lưu dữ liệu vào file
        svhttt.dat, tất cả các file đều ghi dạng text

*/


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập vào số lượng sinh viên: ");
        int soLuong = scanner.nextInt();

        int i = 0;
        while(i < soLuong) {
            // Nhập thông tin sinh viên từ bàn phím
            scanner.nextLine();
            System.out.println("Nhập thông tin sinh viên HTTT:");
            System.out.print("Mã sinh viên: ");
            String maSv = scanner.nextLine();
            System.out.print("Họ tên: ");
            String hoTen = scanner.nextLine();
            System.out.print("Ngày sinh: ");
            String ngaySinh = scanner.nextLine();
            System.out.print("Giới tính: ");
            String gioiTinh = scanner.nextLine();
            System.out.print("Điểm trung bình: ");
            double diemTb = scanner.nextDouble();
            System.out.print("Học phí: ");
            double hocPhi = scanner.nextDouble();
            scanner.nextLine(); // Đọc dòng trống sau khi nhập số
            System.out.print("Đơn vị: ");
            String donVi = scanner.nextLine();
            System.out.print("Lương: ");
            double luong = scanner.nextDouble();

            // Tạo đối tượng sinh viên HTTT và lưu dữ liệu
            SinhvienHTTT svHTTT = new SinhvienHTTT(maSv, hoTen, ngaySinh, gioiTinh, diemTb, hocPhi);
            svHTTT.hienThiThongTin();
            svHTTT.luuDuLieu();
            System.out.println("Đã lưu thông tin SinhvienHTTT vào file (svhttt.dat) Thành Công.");


            // Tạo đối tượng sinh viên UTT và lưu dữ liệu
            SinhvienUTT svUTT = new SinhvienUTT(maSv, hoTen, ngaySinh, gioiTinh, diemTb, donVi, luong);
            svUTT.hienThiThongTin();
            svUTT.luuDuLieu();
            System.out.println("Đã lưu thông tin SinhvienUTT vào file (svutt.dat) Thành Công.");

        }

        scanner.close();
    }
}
