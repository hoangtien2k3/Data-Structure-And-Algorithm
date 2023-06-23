/*
    Đề 19:
    Câu 1:
        a. Hãy định nghĩa class Person với các thuộc tính: Họ tên, ngày sinh, địa chỉ, giới tính và các phương thức khởi tạo,
        hiển thị thông tin.
        b. Định nghĩa class CanBo kế thừa tử Person, thêm các thuộc tính phòng ban (nhận 1 trong các giá trị: Đào tạo, Tổ chức cán bộ, văn phòng CNTT).
        hệ số lương, lương cơ bản, thưởng, phạt và các phương thức khởi tạo, tính lương thực lĩnh, hiển thị thông tin cá nhân.
        Trong đó: lương thực lĩnh = Lương cơ bản * hệ số + thưởng - phạt.
    
    Câu 2:
        a. Hãy đọc file canbo.dat gồm danh sách các cán bộ với định dạng lưu trữ như sau: mỗi cán bộ được lưu trữ trên 1 dòng,
        mỗi thuộc tính phân cách bởi ký tự "*". Dữ liệu đọc được lưu dưới dạng 1 mảng các đối tượng cán bộ (arraylist)
        b. Hiển thị danh sách trên một table(hiển thị trên console chỉ đượcc 1,5 điểm).

    Câu 3:

*/

package de19;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author hoang
 */
public class De19 {
    public static void main(String[] args) {
        ArrayList<CanBo> listCanBo = new ArrayList<>();

        try {
            File file = new File("C:\\Users\\hoang\\OneDrive\\Desktop\\Java\\JavaOnTap\\De19\\canbo.dat");
            try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                String line;
                while ((line = br.readLine()) != null) {
                    String[] canBoInfo = line.split("\\*");
                    String hoTen = canBoInfo[0];
                    String ngaySinh = canBoInfo[1];
                    String diaChi = canBoInfo[2];
                    String gioiTinh = canBoInfo[3];
                    String phongBan = canBoInfo[4];
                    double heSoLuong = Double.parseDouble(canBoInfo[5]);
                    double luongCoBan = Double.parseDouble(canBoInfo[6]);
                    double thuong = Double.parseDouble(canBoInfo[7]);
                    double phat = Double.parseDouble(canBoInfo[8]);
                    CanBo canBo = new CanBo(hoTen, ngaySinh, diaChi, gioiTinh, phongBan, heSoLuong, luongCoBan, thuong, phat);
                    listCanBo.add(canBo);
                }
            }
        } catch (IOException e) {
            System.out.println("Lỗi đọc file: " + e.getMessage());
        }
        
        System.out.println("+----------------------+--------------+---------------------------+------------+--------------------+--------------+--------------+------------+------------+");
        String format = "| %-20s | %-12s | %-25s | %-10s | %-18s | %-12s | %-12s | %-10s | %-10s |\n";
        System.out.format(format, "Họ tên", "Ngày sinh", "Địa chỉ", "Giới tính", "Phòng ban", "Hệ số lương", "Lương cơ bản", "Thưởng", "Phạt");
        System.out.println("+----------------------+--------------+---------------------------+------------+--------------------+--------------+--------------+------------+------------+");
        for (CanBo cb : listCanBo) {
            System.out.format(format, cb.getHoTen(), cb.getNgaySinh(), cb.getDiaChi(), cb.getGioiTinh(),
                    cb.getPhongBan(), cb.getHeSoLuong(), cb.getLuongCoBan(), cb.getThuong(), cb.getPhat());
            System.out.println("+----------------------+--------------+---------------------------+------------+--------------------+--------------+--------------+------------+------------+");
        }
    }
}
