package BaiTapUTT.BaiTapGhiFileVoiLuongChar.Bai2;

public class Sinhvien {
    protected String maSv;
    protected String hoTen;
    protected String ngaySinh;
    protected String gioiTinh;
    protected double diemTb;

    public Sinhvien(String maSv, String hoTen, String ngaySinh, String gioiTinh, double diemTb) {
        this.maSv = maSv;
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.gioiTinh = gioiTinh;
        this.diemTb = diemTb;
    }

    public void hienThiThongTin() {
        System.out.println("Mã sinh viên: " + maSv);
        System.out.println("Họ tên: " + hoTen);
        System.out.println("Ngày sinh: " + ngaySinh);
        System.out.println("Giới tính: " + gioiTinh);
        System.out.println("Điểm trung bình: " + diemTb);
    }

}
