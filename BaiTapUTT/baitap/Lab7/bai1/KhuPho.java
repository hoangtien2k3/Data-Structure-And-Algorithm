package BaiTapUTT.baitap.Lab7.bai1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class KhuPho {
    private List<HoDan> danhSachHoDan;

    public KhuPho() {
        this.danhSachHoDan = new ArrayList<>();
    }

    public void nhapThongTin() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("<=> Nhập số hộ dân: ");
        int soHoDan = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < soHoDan; i++) {
            HoDan hoDan = new HoDan();
            hoDan.nhapThongTin();
            this.danhSachHoDan.add(hoDan);
        }
    }

    public void hienThiThongTin() {
        System.out.println("\n=======> Danh Sách Thông tin về các hộ trong khu phố <=======");
        this.danhSachHoDan.forEach(HoDan::hienThiThongTin);
    }
}