package BaiTapUTT.BaiTapGhiFileVoiLuongChar.Bai2;

import java.io.FileWriter;
import java.io.IOException;

public class SinhvienUTT extends Sinhvien {
    private String donVi;
    private double luong;

    public SinhvienUTT(String maSv, String hoTen, String ngaySinh, String gioiTinh, double diemTb, String donVi, double luong) {
        super(maSv, hoTen, ngaySinh, gioiTinh, diemTb);
        this.donVi = donVi;
        this.luong = luong;
    }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Đơn vị: " + donVi);
        System.out.println("Lương: " + luong);
    }

    public void luuDuLieu() {
        try {
            FileWriter writer = new FileWriter("svutt.dat", true);
            writer.write(maSv + "," + hoTen + "," + ngaySinh + "," + gioiTinh + "," + diemTb + "," + donVi + "," + luong + "\n");
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
