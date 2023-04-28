package BaiTapUTT.baitap.Lab7.bai2;

public class Nguoi {
    protected String hoTen;
    protected int tuoi;
    protected int namSinh;
    protected String soCMTND;

    public Nguoi(String hoTen, int tuoi, int namSinh, String soCMTND) {
        this.hoTen = hoTen;
        this.tuoi = tuoi;
        this.namSinh = namSinh;
        this.soCMTND = soCMTND;
    }

    // Getters and setters
    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public int getTuoi() {
        return tuoi;
    }

    public void setTuoi(int tuoi) {
        this.tuoi = tuoi;
    }

    public int getNamSinh() {
        return namSinh;
    }

    public void setNamSinh(int namSinh) {
        this.namSinh = namSinh;
    }

    public String getSoCMTND() {
        return soCMTND;
    }

    public void setSoCMTND(String soCMTND) {
        this.soCMTND = soCMTND;
    }

    @Override
    public String toString() {
        return " - Họ tên: " + hoTen + ", Tuổi: " + tuoi + ", Năm sinh: " + namSinh + ", Số CMTND: " + soCMTND;
    }
}
