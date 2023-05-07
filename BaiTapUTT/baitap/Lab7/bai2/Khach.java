package BaiTapUTT.baitap.Lab7.bai2;

import java.util.Scanner;

public class Khach extends Nguoi implements IKhachSan {
    private int soNgayTro;
    private String loaiPhong;
    private int giaPhong;

    public Khach(String hoTen, int tuoi, int namSinh, String soCMTND, int soNgayTro, String loaiPhong, int giaPhong) {
        super(hoTen, tuoi, namSinh, soCMTND);
        this.soNgayTro = soNgayTro;
        this.loaiPhong = loaiPhong;
        this.giaPhong = giaPhong;
    }

    // Getters and setters
    public int getSoNgayTro() {
        return soNgayTro;
    }

    public void setSoNgayTro(int soNgayTro) {
        this.soNgayTro = soNgayTro;
    }

    public String getLoaiPhong() {
        return loaiPhong;
    }

    public void setLoaiPhong(String loaiPhong) {
        this.loaiPhong = loaiPhong;
    }

    public int getGiaPhong() {
        return giaPhong;
    }

    public void setGiaPhong(int giaPhong) {
        this.giaPhong = giaPhong;
    }

    @Override
    public void nhapThongTin() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\t + Nhập họ tên: ");
        this.hoTen = scanner.nextLine();
        System.out.print("\t + Nhập tuổi: ");
        this.tuoi = scanner.nextInt();
        System.out.print("\t + Nhập năm sinh: ");
        this.namSinh = scanner.nextInt();

        scanner.nextLine(); // Đọc ký tự '\n' trong bộ đệm

        System.out.print("\t + Nhập số CMTND: ");
        this.soCMTND = scanner.nextLine();
        System.out.print("\t + Nhập số ngày trọ: ");
        this.soNgayTro = scanner.nextInt();

        scanner.nextLine(); // Đọc ký tự '\n' trong bộ đệm

        System.out.print("\t + Nhập loại phòng trọ: ");
        this.loaiPhong = scanner.nextLine();
        System.out.print("\t + Nhập giá phòng: ");
        this.giaPhong = scanner.nextInt();
    }

    public static int count = 0;
    @Override
    public void hienThiThongTin() {
        System.out.println("-----------------------> Thông tin khách trọ " + ++count + " <--------------------");
        System.out.println(this);
        System.out.println("\t + Số ngày trọ: " + soNgayTro);
        System.out.println("\t + Loại phòng trọ: " + loaiPhong);
        System.out.println("\t + Giá phòng: " + giaPhong);
        System.out.println("--------------------------------------------------------------------");
    }
}
