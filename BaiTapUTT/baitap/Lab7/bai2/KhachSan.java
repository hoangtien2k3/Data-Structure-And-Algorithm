package BaiTapUTT.baitap.Lab7.bai2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class KhachSan {
    private List<Khach> dsKhach;

    public KhachSan() {
        dsKhach = new ArrayList<>();
    }

    public void nhapDanhSach() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("=> Nhập số lượng khách trọ: ");
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            Khach khach = new Khach("", 0, 0, "", 0, "", 0);
            System.out.println("\n--------> Nhập Thông Tin Khác Trọ Thứ " + (i + 1) + " <-------");
            khach.nhapThongTin();
            dsKhach.add(khach);
        }
    }

    public void hienThiDanhSach() {
        System.out.println("\n========================> DANH SÁCH KHÁC TRỌ <======================");
        dsKhach.stream()
                .forEach(khach -> khach.hienThiThongTin());
    }
}