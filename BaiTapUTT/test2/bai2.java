package BaiTap.test2;

abstract class Hinh {
    public abstract double tinhChuVi();
    public abstract double tinhDienTich();
}

class HinhVuong extends Hinh {
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

class HinhChuNhat extends Hinh {
    private double chieuDai;
    private double chieuRong;

    public HinhChuNhat(double chieuDai, double chieuRong) {
        this.chieuDai = chieuDai;
        this.chieuRong = chieuRong;
    }

    public double tinhChuVi() {
        return 2 * (chieuDai + chieuRong);
    }

    public double tinhDienTich() {
        return chieuDai * chieuRong;
    }
}

class TuGiac extends Hinh {
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

class Dinh {
    private double x;
    private double y;

    public Dinh(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }
}

public class bai2 {
    public static void main(String[] args) {
        // Tạo đối tượng hình vuông và tính chu vi, diện tích
        HinhVuong hv = new HinhVuong(5);
        System.out.println("Chu vi hinh vuong: " + hv.tinhChuVi());
        System.out.println("Dien tich hinh vuong: " + hv.tinhDienTich());

        // Tạo đối tượng hình chữ nhật và tính chu vi, diện tích
        HinhChuNhat hcn = new HinhChuNhat(3, 4);
        System.out.println("Chu vi hinh chu nhat: " + hcn.tinhChuVi());
        System.out.println("Dien tich hinh chu nhat: " + hcn.tinhDienTich());
    }
}
