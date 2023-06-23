package BaiTapUTT.BaiTapGhiFileVoiLuongChar.Bai1;

/*
    Bài 1 (đọc file):
    Định nghĩa các lớp theo yêu cầu sau:
        a. Hãy định nghĩa class Person với các thuộc tính: Họ tên, ngày sinh, địa
        chỉ, giới tính và các phương thức khởi tạo, hiển thị thông tin.
        b. Định nghĩa class NhanVien kế thừa từ Person, có thêm các
        thuộc tính: phòng ban, hệ số lương, thâm niên, lương cơ bản và các
        phương thức khởi tạo, tính lương thực lĩnh, hiển thị thông tin cá nhân
        Trong đó: lương thực lĩnh = Lương cơ bản * hệ số (1 + thâm niên/100)
    Yêu cầu
        a. Hãy đọc file text nhanvien.dat.dat gồm danh sách các nhân viên với định
        dạng lưu trữ như sau: mỗi nhân viên được lưu trên 1 dòng, mỗi thuộc
        tính phân cách bởi ký tự “$”. Dữ liệu đọc được lưu dưới dạng một
        mảng các đối tượng nhân viên (arraylist)
        b. Hiển thị danh sách trên trong màn hình console, đồng thời ghi nội
        dung vào file nhanvien.dat.txt dạng text.
        c. Copy nội dung sang file khác(tên file nhập từ bàn phím)
*/

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<NhanVien> danhSachNhanVien = docFileNhanVien("nhanvien.dat");

        // Hiển thị danh sách nhân viên trên màn hình console
        for (NhanVien nhanVien : danhSachNhanVien) {
            nhanVien.hienThiThongTin();
            System.out.println();
        }

        // Ghi nội dung vào file nhanvien.txt
        ghiFileNhanVien(danhSachNhanVien, "nhanvien.txt");

        // Sao chép nội dung sang file khác (tên file nhập từ bàn phím)

        System.out.println("<=> Sao chép nội dung sang file khác (tên file nhập từ bàn phím <=>)");
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập tên file mới: ");
        String tenFileMoi = scanner.nextLine();
        // String tenFileMoi = "new_nhanvien.txt"; // Tên file mới
        saoChepFile("nhanvien.txt", tenFileMoi);
    }

    public static ArrayList<NhanVien> docFileNhanVien(String tenFile) {
        ArrayList<NhanVien> danhSachNhanVien = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(tenFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] data = line.split("\\$");
                String hoTen = data[0];
                String ngaySinh = data[1];
                String diaChi = data[2];
                String gioiTinh = data[3];
                String phongBan = data[4];
                double heSoLuong = Double.parseDouble(data[5]);
                int thamNien = Integer.parseInt(data[6]);
                double luongCoBan = Double.parseDouble(data[7]);

                NhanVien nhanVien = new NhanVien(hoTen, ngaySinh, diaChi, gioiTinh, phongBan, heSoLuong, thamNien, luongCoBan);
                danhSachNhanVien.add(nhanVien);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return danhSachNhanVien;
    }

    public static void ghiFileNhanVien(ArrayList<NhanVien> danhSachNhanVien, String tenFile) {
        try (FileWriter writer = new FileWriter(tenFile)) {
            for (NhanVien nhanVien : danhSachNhanVien) {
                String line = nhanVien.getHoTen() + "$" +
                        nhanVien.getNgaySinh() + "$" +
                        nhanVien.getDiaChi() + "$" +
                        nhanVien.getGioiTinh() + "$" +
                        nhanVien.getPhongBan() + "$" +
                        nhanVien.getHeSoLuong() + "$" +
                        nhanVien.getThamNien() + "$" +
                        nhanVien.getLuongCoBan();

                writer.write(line + System.lineSeparator());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void saoChepFile(String tenFileGoc, String tenFileMoi) {
        try (BufferedReader br = new BufferedReader(new FileReader(tenFileGoc));
             FileWriter writer = new FileWriter(tenFileMoi)) {
                String line;
                while ((line = br.readLine()) != null) {
                    writer.write(line + System.lineSeparator());
                }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
