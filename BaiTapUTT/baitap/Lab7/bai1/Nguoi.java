package BaiTapUTT.baitap.Lab7.bai1;

import java.util.Scanner;

public class Nguoi implements INguoi {
    private String hoTen;
    private int tuoi;
    private int namSinh;
    private String ngheNghiep;

    @Override
    public void nhapThongTin() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\t + Nhập họ tên: ");
        this.hoTen = scanner.nextLine();
        System.out.print("\t + Nhập tuổi: ");
        this.tuoi = scanner.nextInt();
        scanner.nextLine();
        System.out.print("\t + Nhập năm sinh: ");
        this.namSinh = scanner.nextInt();
        scanner.nextLine();
        System.out.print("\t + Nhập nghề nghiệp: ");
        this.ngheNghiep = scanner.nextLine();
    }

    @Override
    public void hienThiThongTin() {
        System.out.println("\t + Họ tên: " + this.hoTen);
        System.out.println("\t + Tuổi: " + this.tuoi);
        System.out.println("\t + Năm sinh: " + this.namSinh);
        System.out.println("\t + Nghề nghiệp: " + this.ngheNghiep);
    }
}