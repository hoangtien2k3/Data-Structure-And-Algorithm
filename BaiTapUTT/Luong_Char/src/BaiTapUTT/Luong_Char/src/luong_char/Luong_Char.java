/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package BaiTapUTT.Luong_Char.src.luong_char;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Luong_Char {
    public static void main(String[] args) {
        ArrayList<NhanVien> danhsachnhanvien = docFileNhanVien("NhanVien.dat");
        // Hien thi nhan vien
        for(NhanVien nhanvien : danhsachnhanvien){
            nhanvien.output();
            System.out.println();
        }
        // ghi file NhanVien.txt
        ghiFileNhanVien(danhsachnhanvien, "NhanVien.txt");
        
        // Sao chep noi dung sang File khac (nhap ten tu ban phim)
        System.out.println("Sao chep noi dung sang file khac(trn file nhap tu ban phim)");
        Scanner scanner = new Scanner(System.in);
        System.out.print("nhap ten file moi : ");
        String tenFilemoi = scanner.nextLine();
        saochepFile("NhanVien.txt", tenFilemoi);
        
    }

    public static ArrayList<NhanVien> docFileNhanVien(String tenFile){
        ArrayList<NhanVien> danhsachnhanvien = new ArrayList<>();
        
        try(BufferedReader br = new BufferedReader(new FileReader(tenFile))) {
            String line ;
            while ((line = br.readLine()) != null) {                
                String[] data = line.split("\\$");
                String Hoten = data[0];
                String Ngaysinh = data[1];
                String Diachi = data[2];
                String Gioitinh = data[3];
                String Phongban = data[4];
                float Hesoluong = Float.parseFloat(data[5]);
                int Thamnien = Integer.parseInt(data[6]);
                double Luongcoban = Double.parseDouble(data[7]);
                
                NhanVien nhanvien = new NhanVien(Hoten, Ngaysinh, Diachi, Gioitinh, Phongban, Hesoluong, Thamnien, Luongcoban);
                danhsachnhanvien.add(nhanvien);
            }
        } catch (Exception e) {
        }
        return danhsachnhanvien;
    }
    public static void ghiFileNhanVien(ArrayList<NhanVien> danhsachnhanvien, String tenFile){
        try(FileWriter write = new FileWriter(tenFile)) {
            for(NhanVien nhanvien : danhsachnhanvien){
                String line =   nhanvien.getHoten() + "$" + 
                                nhanvien.getNgaysinh()+ "$" +
                                nhanvien.getDiachi() + "$" + 
                                nhanvien.getGioitinh()+ "$" +
                                nhanvien.getPhongban() + "$" + 
                                nhanvien.getHesoluong()+ "$" +
                                nhanvien.getThamnien() + "$" + 
                                nhanvien.getLuongcoban()+ "$";
                
                write.write(line+ System.lineSeparator());
            }
        } catch (Exception e) {
        }
    }
    
    public static void saochepFile(String tenFilegoc, String tenFilemoi){
        try(BufferedReader br = new BufferedReader(new FileReader(tenFilegoc))) {
            FileWriter write = new FileWriter(tenFilemoi);
                    String line;
                    while ((line = br.readLine()) != null) {                
                           write.write(line + System.lineSeparator());
            }
        } catch (Exception e) {
        }
    }
    
    
    
}
