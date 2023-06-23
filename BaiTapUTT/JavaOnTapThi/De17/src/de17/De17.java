/*
    Câu 1:
        a. Hãy định nghĩa class Person với các thuộc tính: Họ tên, ngày sinh, địa chỉ, giới tính và các phương thức khởi tạo,
        hiển thị thông tin.
        b. Định nghĩa class HocSinh kế thừa từ Person, còn thêm các thuộc tính: mã học sinh, lớp, điểm tổng kết và các phương thức khởi tạo,
        hiển thị thông tin.

    Câu 2:
        a. Hãy đọc file hocsinh.dat gồm danh sách các Học sinh với định dạng lưu trữ như sau: mỗi học sinh được lưu trên 1 dòng
        mỗi thuộc tính phân cách bởi ký tự "&" . Dữ liệu đọc được lưu trữ dưới dạng một mảng đối tượng Học sinh (arraylist)
        b. Hãy hiển thị danh sách trên trong một table.

    Câu 3: cho một cây kế thừa


*/

package de17;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author hoang
 */
public class De17 {
    private static ArrayList<HocSinh> getListHocSinhFromFile(String fileName) throws IOException {
        ArrayList<HocSinh> listHS = new ArrayList<>();
        FileReader fileReader = new FileReader(fileName);
        try (BufferedReader bufferedReader = new BufferedReader(fileReader)) {
            String line;
            
            System.out.println("+----------------------+-----------------+----------------------+-----------------+-----------------+------------+------------+");
            String format = "| %-20s | %-15s | %-20s | %-15s | %-15s | %-10s | %-10s |\n";
            System.out.format(format, "Họ tên", "Ngày sinh", "Địa chỉ", "Giới tính", "Mã học sinh", "Lớp", "Điểm");
            System.out.println("+----------------------+-----------------+----------------------+-----------------+-----------------+------------+------------+");
            while ((line = bufferedReader.readLine()) != null) {
                String[] hsInfo = line.split("&");
                String hoTen = hsInfo[0];
                String ngaySinh = hsInfo[1];
                String diaChi = hsInfo[2];
                String gioiTinh = hsInfo[3];
                String maHS = hsInfo[4];
                String lop = hsInfo[5];
                double diemTK = Double.parseDouble(hsInfo[6]);
                
                HocSinh hs = new HocSinh(hoTen, ngaySinh, diaChi, gioiTinh, maHS, lop, diemTK);
                System.out.format(format,
                        hs.getHoTen(), hs.getNgaySinh(), hs.getDiaChi(), hs.getGioiTinh(),
                        hs.getMaHS(), hs.getLop(), hs.getDiemTK());
                System.out.println("+----------------------+-----------------+----------------------+-----------------+-----------------+------------+------------+");
                listHS.add(hs);
            }
        }
        return listHS;
    }

    public static void main(String[] args) {
        try {
            ArrayList<HocSinh> listHS = getListHocSinhFromFile("hocsinh.dat");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
