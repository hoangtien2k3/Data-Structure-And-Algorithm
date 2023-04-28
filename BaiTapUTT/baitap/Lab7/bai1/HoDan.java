package BaiTapUTT.baitap.Lab7.bai1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class HoDan {
    private int soThanhVien;
    private int soNha;
    private List<Nguoi> danhSachNguoi;

    public HoDan() {
        this.danhSachNguoi = new ArrayList<>();
    }

    public static int index = 0;
    public void nhapThongTin() {
        System.out.println("Nhập Thông Tin Hộ Dân Số " + ++index + ": ");
        Scanner scanner = new Scanner(System.in);
        System.out.print("- Nhập số thành viên: ");
        this.soThanhVien = scanner.nextInt();
        scanner.nextLine();
        System.out.print("- Nhập số nhà: ");
        this.soNha = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Nhập thông tin về từng cá nhân trong hộ gia đình:");
        for (int i = 0; i < this.soThanhVien; i++) {
            System.out.println("\t=> Nhập thông tin thanh viên " + (i + 1) + ": ");
            Nguoi nguoi = new Nguoi();
            nguoi.nhapThongTin();
            this.danhSachNguoi.add(nguoi);
        }
    }

    public static int count = 0;
    public void hienThiThongTin() {
        System.out.println("\n----------------> Thông Tin Hộ Dân Sô " + ++count + " <-----------------");
        System.out.println("\t- Số thành viên: " + this.soThanhVien);
        System.out.println("\t- Số nhà: " + this.soNha);
        System.out.println("Thông tin về từng cá nhân trong hộ gia đình:");
//        this.danhSachNguoi.forEach(Nguoi::hienThiThongTin);
        this.danhSachNguoi.stream()
                .forEach(nguoi -> nguoi.hienThiThongTin());
        System.out.println("-----------------------------------------------------------------------");
    }

}