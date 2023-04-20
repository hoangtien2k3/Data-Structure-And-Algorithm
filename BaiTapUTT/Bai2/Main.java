package BaiTap.Bai2;

public class Main {
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
