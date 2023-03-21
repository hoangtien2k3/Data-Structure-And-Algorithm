package BaiTap.Bai2;

public class TuGiac extends Hinh {
    private double canh1;
    private double canh2;
    private double canh3;
    private double canh4;

    public TuGiac(double canh1, double canh2, double canh3, double canh4) {
        this.canh1 = canh1;
        this.canh2 = canh2;
        this.canh3 = canh3;
        this.canh4 = canh4;
    }

    public double tinhChuVi() {
        return canh1 + canh2 + canh3 + canh4;
    }

    public double tinhDienTich() {
        // Áp dụng công thức Heron để tính diện tích tứ giác bất kỳ
        double p = tinhChuVi() / 2;
        double S = Math.sqrt((p - canh1) * (p - canh2) * (p - canh3) * (p - canh4));
        return S;
    }
}