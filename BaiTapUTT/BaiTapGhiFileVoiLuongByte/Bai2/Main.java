package BaiTapUTT.BaiTapGhiFileVoiLuongByte.Bai2;

import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập thông tin sinh viên HTTT
        System.out.println("Nhập thông tin sinh viên HTTT:");
        SinhvienHTTT svHTTT = nhapSinhVienHTTT(scanner);
        luuSinhVienHTTT(svHTTT);

        // Nhập thông tin sinh viên UTT
        System.out.println("\nNhập thông tin sinh viên UTT:");
        SinhvienUTT svUTT = nhapSinhVienUTT(scanner);
        luuSinhVienUTT(svUTT);

        // Hiển thị danh sách sinh viên HTTT
        System.out.println("\nDanh sách sinh viên HTTT:");
        hienThiDanhSachSinhVienHTTT();

        // Hiển thị danh sách sinh viên UTT
        System.out.println("\nDanh sách sinh viên UTT:");
        hienThiDanhSachSinhVienUTT();
    }

    public static SinhvienHTTT nhapSinhVienHTTT(Scanner scanner) {
        System.out.print("Nhập mã sinh viên: ");
        String maSinhVien = scanner.nextLine();

        System.out.print("Nhập họ tên: ");
        String hoTen = scanner.nextLine();

        System.out.print("Nhập ngày sinh: ");
        String ngaySinh = scanner.nextLine();

        System.out.print("Nhập giới tính: ");
        String gioiTinh = scanner.nextLine();

        System.out.print("Nhập điểm trung bình: ");
        double diemTrungBinh = Double.parseDouble(scanner.nextLine());

        System.out.print("Nhập học phí: ");
        double hocPhi = Double.parseDouble(scanner.nextLine());

        return new SinhvienHTTT(maSinhVien, hoTen, ngaySinh, gioiTinh, diemTrungBinh, hocPhi);
    }

    public static SinhvienUTT nhapSinhVienUTT(Scanner scanner) {
        System.out.print("Nhập mã sinh viên: ");
        String maSinhVien = scanner.nextLine();

        System.out.print("Nhập họ tên: ");
        String hoTen = scanner.nextLine();

        System.out.print("Nhập ngày sinh: ");
        String ngaySinh = scanner.nextLine();

        System.out.print("Nhập giới tính: ");
        String gioiTinh = scanner.nextLine();

        System.out.print("Nhập điểm trung bình: ");
        double diemTrungBinh = Double.parseDouble(scanner.nextLine());

        System.out.print("Nhập đơn vị: ");
        String donVi = scanner.nextLine();

        System.out.print("Nhập lương: ");
        double luong = Double.parseDouble(scanner.nextLine());

        return new SinhvienUTT(maSinhVien, hoTen, ngaySinh, gioiTinh, diemTrungBinh, donVi, luong);
    }

    public static void luuSinhVienHTTT(SinhvienHTTT svHTTT) {
        try {
            FileOutputStream fileOutputStream = new FileOutputStream("svhttt.obj");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
            objectOutputStream.writeObject(svHTTT);
            objectOutputStream.close();
            fileOutputStream.close();
            System.out.println("Đã lưu sinh viên HTTT vào file sv httt.obj.");
        } catch (IOException e) {
            System.out.println("Lỗi: " + e.getMessage());
        }
    }

    public static void luuSinhVienUTT(SinhvienUTT svUTT) {
        try {
            FileOutputStream fileOutputStream = new FileOutputStream("svutt.obj");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
            objectOutputStream.writeObject(svUTT);
            objectOutputStream.close();
            fileOutputStream.close();
            System.out.println("Đã lưu sinh viên UTT vào file svutt.obj.");
        } catch (IOException e) {
            System.out.println("Lỗi: " + e.getMessage());
        }
    }

    public static void hienThiDanhSachSinhVienHTTT() {
        try {
            FileInputStream fileInputStream = new FileInputStream("svhttt.obj");
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
            SinhvienHTTT svHTTT = (SinhvienHTTT) objectInputStream.readObject();
            svHTTT.hienThiThongTin();
            objectInputStream.close();
            fileInputStream.close();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Lỗi: " + e.getMessage());
        }
    }

    public static void hienThiDanhSachSinhVienUTT() {
        try {
            FileInputStream fileInputStream = new FileInputStream("svutt.obj");
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
            SinhvienUTT svUTT = (SinhvienUTT) objectInputStream.readObject();
            svUTT.hienThiThongTin();
            objectInputStream.close();
            fileInputStream.close();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Lỗi: " + e.getMessage());
        }
    }

}
