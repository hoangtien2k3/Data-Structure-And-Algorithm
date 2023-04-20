package BaiTap.Bai2;

public class HinhVuong extends Hinh {
    private double canh;

    public HinhVuong(double canh) {
        this.canh = canh;
    }

    public double tinhChuVi() {
        return 4 * canh;
    }

    public double tinhDienTich() {
        return canh * canh;
    }
}
