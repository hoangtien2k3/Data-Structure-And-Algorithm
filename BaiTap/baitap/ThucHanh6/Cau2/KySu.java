package BaiTap.baitap.ThucHanh6.Cau2;

public class KySu extends CanBo {
    private String nganhDaoTao;

    public KySu(String hoTen, int namSinh, String gioiTinh, String diaChi, String nganhDaoTao) {
        super(hoTen, namSinh, gioiTinh, diaChi);
        this.nganhDaoTao = nganhDaoTao;
    }

    @Override
    public String loaiCanBo() {
        return "Kỹ sư";
    }

    // override phương thức thongTinBoSung() để cung cấp thông tin bổ sung
    @Override
    public String thongTinBoSung() {
        return "Ngành đào tạo: " + nganhDaoTao;
    }

    public String getNganhDaoTao() {
        return nganhDaoTao;
    }

    public void setNganhDaoTao(String nganhDaoTao) {
        this.nganhDaoTao = nganhDaoTao;
    }
}
