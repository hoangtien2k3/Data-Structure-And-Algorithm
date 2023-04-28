package BaiTapUTT.baitap.ThucHanh6.Cau1;

import java.util.stream.Stream;

public class PhanSo extends AbstractPhanSo{
    public PhanSo(int tuSo, int mauSo) {
        super(tuSo, mauSo);
    }

    public PhanSo() {
        super();
    }

    @Override
    public PhanSo cong(PhanSo ps) {
        int tuso = this.tuSo * ps.mauSo + this.mauSo * ps.tuSo;
        int mauso = this.mauSo * ps.mauSo;
        PhanSo newPS = new PhanSo(tuso, mauso);
        newPS.toiGian();
        return newPS;
    }

    @Override
    public PhanSo tru(PhanSo ps) {
        int tuso = this.tuSo * ps.mauSo - this.mauSo * ps.tuSo;
        int mauso = this.mauSo * ps.mauSo;
        PhanSo newPS = new PhanSo(tuso, mauso);
        newPS.toiGian();
        return newPS;
    }

    @Override
    public PhanSo nhan(PhanSo ps) {
        int tuso = this.tuSo * ps.tuSo;
        int mauso = this.mauSo * ps.mauSo;
        PhanSo newPS = new PhanSo(tuso, mauso);
        newPS.toiGian();
        return newPS;
    }

    @Override
    public PhanSo chia(PhanSo ps) {
        int tuso = this.tuSo * ps.mauSo;
        int mauso = this.mauSo * ps.tuSo;
        PhanSo newPS = new PhanSo(tuso, mauso);
        newPS.toiGian();
        return newPS;
    }

    @Override
    public void toiGian() {
        int ucln = UCLN(this.tuSo, this.mauSo);
        this.tuSo /= ucln;
        this.mauSo /= ucln;
    }

    @Override
    public boolean laToiGian() {
        return UCLN(this.tuSo, this.mauSo) == 1;
    }

    @Override
    protected int UCLN(int a, int b) {
        return super.UCLN(a, b);
    }

    @Override
    public String toString() {
        return this.tuSo + "/" + this.mauSo;
    }
}
