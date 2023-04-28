package BaiTapUTT.baitap.ThucHanh6.Cau2;

public class CongNhan extends CanBo {
    private int bac;

    public CongNhan(String hoTen, int namSinh, String gioiTinh, String diaChi, int bac) {
        super(hoTen, namSinh, gioiTinh, diaChi);
        this.bac = bac;
    }

    @Override
    public String loaiCanBo() {
        return "Công nhân";
    }

    // override phương thức thongTinBoSung() để cung cấp thông tin bổ sung
    @Override
    public String thongTinBoSung() {
        return "Bậc: " + bac;
    }

    public int getBac() {
        return bac;
    }

    public void setBac(int bac) {
        this.bac = bac;
    }
}
