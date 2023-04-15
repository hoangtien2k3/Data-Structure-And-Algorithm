package BaiTap.baitap.ThucHanh6.Cau1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution{
    static Scanner input = new Scanner(System.in);
    static List<PhanSo> list = new ArrayList<>();

    public static void ThucHienPhepTinh() {
        System.out.print("Nhập vào số lượng phân số: ");
        int n = input.nextInt();
        for(int i = 0; i < n; i++) {
            System.out.println("\nNhập thông tin phân số thứ " + (i+1) + ": ");
            System.out.print("\tNhập vào tử số: ");
            int newTuSo = input.nextInt();
            System.out.print("\tNhập vào mẫu số: ");
            int newMauSo = input.nextInt();
            PhanSo ps = new PhanSo(newTuSo, newMauSo);
            ps.toiGian();
            list.add(ps);
        }

        while(true) {
            System.out.println("\n_____________ Menu ______________");
            System.out.println("  1. Tổng Tất Cả Các Phân Số");
            System.out.println("  2. Hiệu Tất Cả Các Phân Số");
            System.out.println("  3. Tích Tất Cả Các Phân Số");
            System.out.println("  4. Thương Tất Cả Các Phân Số");
            System.out.println("  5. Dãy Phân Số Tối Dãn.");
            System.out.println("  0. Thoát Chương Trình !!!");
            System.out.println("_________________________________");

            System.out.print("+ Nhập vào lựa chọn: ");
            int lc = input.nextInt();

            switch (lc) {
                case 1:{
                    PhanSo tong = new PhanSo();
                    for(PhanSo ps : list) {
                        tong = tong.cong(ps);
                    }
                    if (tong.tuSo == tong.mauSo)
                        System.out.println("=> Tổng Tất Cả Các Phân Số: " + tong.tuSo);
                    else
                        System.out.println("=> Tổng Tất Cả Các Phân Số: " + tong.toString());
                    break;
                }
                case 2: {
                    PhanSo hieu = list.get(0);
                    for (int i = 1; i < list.size(); i++) {
                        hieu = hieu.tru(list.get(i));
                    }
                    if (hieu.tuSo == hieu.mauSo)
                        System.out.println("=> Hiệu Tất Cả Các Phân Số: " + hieu.tuSo);
                    else
                        System.out.println("=> Hiệu Tất Cả Các Phân Số: " + hieu.toString());
                    break;
                }
                case 3: {
                    PhanSo tich = list.get(0);
                    for (int i = 1; i < list.size(); i++) {
                        tich = tich.nhan(list.get(i));
                    }
                    if (tich.tuSo == tich.mauSo)
                        System.out.println("=> Tích Tất Cả Các Phân Số: " + tich.tuSo);
                    else
                        System.out.println("=> Tích Tất Cả Các Phân Số: " + tich.toString());
                    break;
                }
                case 4: {
                    PhanSo thuong = list.get(0);
                    for (int i = 1; i < list.size(); i++) {
                        thuong = thuong.chia(list.get(i));
                    }
                    if (thuong.tuSo == thuong.mauSo)
                        System.out.println("=> Thương Tất Cả Các Phân Số: " + thuong.tuSo);
                    else
                        System.out.println("=> Thương Tất Cả Các Phân Số: " + thuong.toString());
                    break;
                }
                case 5: {
                    System.out.print("=> Dãy Phân Số Tối Dãn: ");
                    for(PhanSo ps : list) {
                        System.out.print(ps + "\t");
                    }
                }
                case 0:
                    return;
            }
        }
    }

}
