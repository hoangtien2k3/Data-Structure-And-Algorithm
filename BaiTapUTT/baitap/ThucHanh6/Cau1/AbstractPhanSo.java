package BaiTapUTT.baitap.ThucHanh6.Cau1;

public abstract class AbstractPhanSo {
    protected int tuSo;
    protected int mauSo;

    public AbstractPhanSo(int tuSo, int mauSo) {
        this.tuSo = tuSo;
        this.mauSo = mauSo;
    }

    public AbstractPhanSo() {
        this.tuSo = 0;
        this.mauSo = 1;
    }

    public abstract PhanSo cong(PhanSo ps);
    public abstract PhanSo tru(PhanSo ps);
    public abstract PhanSo nhan(PhanSo ps);
    public abstract PhanSo chia(PhanSo ps);
    public abstract void toiGian();
    public abstract boolean laToiGian();

    protected int UCLN(int a, int b) {
        if (b == 0) {
            return a;
        }
        return UCLN(b, a % b);
    }
}
