package BaiTap.baitap.ThucHanh6.Cau2;

public class NhanVien extends CanBo {
    private String congViec;

    public NhanVien(String hoTen, int namSinh, String gioiTinh, String diaChi, String congViec) {
        super(hoTen, namSinh, gioiTinh, diaChi);
        this.congViec = congViec;
    }

    @Override
    public String loaiCanBo() {
        return "Nhân viên";
    }

    // override phương thức thongTinBoSung() để cung cấp thông tin bổ sung
    @Override
    public String thongTinBoSung() {
        return "Công việc: " + congViec;
    }

    public String getCongViec() {
        return congViec;
    }

    public void setCongViec(String congViec) {
        this.congViec = congViec;
    }
}