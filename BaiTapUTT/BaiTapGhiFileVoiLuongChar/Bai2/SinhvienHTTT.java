package BaiTapUTT.BaiTapGhiFileVoiLuongChar.Bai2;

import java.io.FileWriter;
import java.io.IOException;

public class SinhvienHTTT extends Sinhvien {
    private double hocPhi;

    public SinhvienHTTT(String maSv, String hoTen, String ngaySinh, String gioiTinh, double diemTb, double hocPhi) {
        super(maSv, hoTen, ngaySinh, gioiTinh, diemTb);
        this.hocPhi = hocPhi;
    }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Học phí: " + hocPhi);
    }

    public void luuDuLieu() {
        try {
            FileWriter writer = new FileWriter("svhttt.dat", true);
            writer.write(maSv + "," + hoTen + "," + ngaySinh + "," + gioiTinh + "," + diemTb + "," + hocPhi + "\n");
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
