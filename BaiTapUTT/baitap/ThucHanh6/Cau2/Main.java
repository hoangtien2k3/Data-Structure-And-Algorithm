/*
    Một đơn vị sản xuất gồm có các cán bộ là công nhân, kỹ sư, nhân viên.
    + Mỗi cán bộ cần quản lý lý các thuộc tính: Họ tên, năm sinh, giới tính,
    địa chỉ
    + Các công nhân cần quản lý: Bậc (công nhân bậc 3/7, bậc 4/7 ...)
    + Các kỹ sư cần quản lý: Ngành đào tạo
    + Các nhân viên phục vụ cần quản lý thông tin: công việc
    1. Xây dựng các lớp NhanVien, CongNhan, KySu kế thừa từ lớp CanBo
    2. Xây dựng các hàm để truy nhập, hiển thị thông tin và kiểm tra về các
    thuộc tính của các lớp.
    3. Xây dựng lớp QLCB cài đặt các phương thức thực hiện các chức năng
    sau:
    - Nhập thông tin mới cho cán bộ
    - Tìm kiếm theo họ tên
    - Hiển thị thông tin về danh sách các cán bộ
    - Thoát khỏi chương trình.
*/

package BaiTapUTT.baitap.ThucHanh6.Cau2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        QuanLyCanBo quanLyCanBo = new QLCB();
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("\n____________ QUẢN LÝ CÁN BỘ __________");
            System.out.println("  1. Thêm mới cán bộ");
            System.out.println("  2. Tìm kiếm cán bộ theo họ tên");
            System.out.println("  3. Hiển thị danh sách cán bộ");
            System.out.println("  4. Thoát");
            System.out.println("______________________________________");
            System.out.print("Chọn chức năng (1-4): ");
            int chon = scanner.nextInt();
            scanner.nextLine();
            switch (chon) {
                case 1:
                    quanLyCanBo.themMoiCanBo();
                    break;
                case 2:
                    quanLyCanBo.timKiemCanBo();
                    break;
                case 3:
                    quanLyCanBo.hienThiDanhSachCanBo();
                    break;
                case 4:
                    quanLyCanBo.thoat();
                    break;
                default:
                    System.out.println("Không đúng chức năng. Vui lòng chọn lại!");
                    break;
            }
        }
    }
}
