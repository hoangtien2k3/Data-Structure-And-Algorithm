package BaiTap.baitap.ThucHanh6.Cau2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class QLCB implements QuanLyCanBo {
    private List<CanBo> danhSachCanBo;

    public QLCB() {
        danhSachCanBo = new ArrayList<>();
    }

    @Override
    public void themMoiCanBo() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n_____________ Thêm mới cán bộ _________");
        System.out.print(" + Nhập họ tên: ");
        String hoTen = scanner.nextLine();
        System.out.print(" + Nhập năm sinh: ");
        int namSinh = scanner.nextInt();
        scanner.nextLine();
        System.out.print(" + Nhập giới tính: ");
        String gioiTinh = scanner.nextLine();
        System.out.print(" + Nhập địa chỉ: ");
        String diaChi = scanner.nextLine();
        System.out.print(" + Loại cán bộ: (1-Công nhân, 2-Kỹ sư, 3-Nhân viên): ");
        int loaiCanBo = scanner.nextInt();
        scanner.nextLine();
        switch (loaiCanBo) {
            case 1:
                System.out.print(" + Nhập bậc công nhân: ");
                int bac = scanner.nextInt();
                danhSachCanBo.add(new CongNhan(hoTen, namSinh, gioiTinh, diaChi, bac));
                break;
            case 2:
                System.out.print(" + Nhập ngành đào tạo: ");
                String nganhDaoTao = scanner.nextLine();
                danhSachCanBo.add(new KySu(hoTen, namSinh, gioiTinh, diaChi, nganhDaoTao));
                break;
            case 3:
                System.out.print(" + Nhập công việc: ");
                String congViec = scanner.nextLine();
                danhSachCanBo.add(new NhanVien(hoTen, namSinh, gioiTinh, diaChi, congViec));
                break;
            default:
                System.out.println(" + Không đúng loại cán bộ");
                break;
        }
        System.out.println(" => Thêm mới cán bộ thành công!");
        System.out.println("_______________________________________");
    }

    @Override
    public void timKiemCanBo() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n_______ Nhập Thông Tin Tìm kiếm _______");
        System.out.print(" + Nhập họ tên cần tim kiếm: ");
        String hoTenCanTimKiem = scanner.nextLine();
        boolean timThay = false;
        for (CanBo canBo : danhSachCanBo) {
            if (canBo.getHoTen().equals(hoTenCanTimKiem)) {
                System.out.println("\n <=> Thông tin cán bộ cần tìm kiếm <=>");
                System.out.println(" + Loại cán bộ: " + canBo.loaiCanBo());
                System.out.println(" + Họ tên: " + canBo.getHoTen());
                System.out.println(" + Năm sinh: " + canBo.getNamSinh());
                System.out.println(" + Giới tính: " + canBo.getGioiTinh());
                System.out.println(" + Địa chỉ: " + canBo.getDiaChi());
                timThay = true;
            }
        }
        if (!timThay) {
            System.out.println("Không tìm thấy cán bộ có họ tên \"" + hoTenCanTimKiem + "\"");
        }
        System.out.println("_________________________________________");
    }

    @Override
    public void hienThiDanhSachCanBo() {
        if (danhSachCanBo.isEmpty()) {
            System.out.println("Danh sách cán bộ rỗng!");
            return;
        }
        System.out.println("\n____________ Hiển Thị Thông Tin ___________");
        int i = 1;
        for (CanBo canBo : danhSachCanBo) {
            System.out.println("\n - Thông tin của cán bộ thứ " + i++ + ": ");
            System.out.println(" + Loại cán bộ: " + canBo.loaiCanBo());
            System.out.println(" + Họ tên: " + canBo.getHoTen());
            System.out.println(" + Năm sinh: " + canBo.getNamSinh());
            System.out.println(" + Giới tính: " + canBo.getGioiTinh());
            System.out.println(" + Địa chỉ: " + canBo.getDiaChi());
            System.out.println(" + " + canBo.thongTinBoSung());
            System.out.println("_____________________________________________ ");
        }
    }

    @Override
    public void thoat() {
        System.out.println("Cảm ơn đã sử dụng chương trình!!!");
        System.exit(0);
    }
}