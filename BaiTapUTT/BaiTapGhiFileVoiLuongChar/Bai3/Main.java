package BaiTapUTT.BaiTapGhiFileVoiLuongChar.Bai3;

/*
    Bài 3 (ghi file – xóa file – copy file):
        Định nghĩa lớp theo yêu cầu sau:
        Hãy định nghĩa class Book gồm các thuộc tính id, authors, title, category
        (nhận 1 trong các giá trị: tạp chí, KHXH, KHTN, luận văn) và các phương thức
        khởi tạo, các getters/setters.
    Yêu cầu
        a. Hãy thiết kế method cho phép nhập thông tin để thêm sách
        b. Thực hiện test Thêm sách thì thực hiện khởi tạo đối tượng sách với
        các thuộc tính lấy từ bàn phím do người dùng nhập, đồng thời lưu dữ
        liệu vào file books.dat dạng text
        c. Nếu người dùng yêu cầu xóa file books.dat thì hãy thực hiện xóa file
        đồng thời backup dữ liệu sang file khác, ở thư mục khác(tên file và
        đường dẫn thư mục nhập từ bàn phím).
*/

import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Thêm sách
        System.out.println("Thêm sách:");
        System.out.print("Nhập ID sách: ");
        int id = scanner.nextInt();
        scanner.nextLine(); // Đọc dòng trống sau khi nhập số
        System.out.print("Nhập tác giả: ");
        String authors = scanner.nextLine();
        System.out.print("Nhập tiêu đề: ");
        String title = scanner.nextLine();
        System.out.print("Nhập thể loại (tạp chí, KHXH, KHTN, luận văn): ");
        String category = scanner.nextLine();

        // Tạo đối tượng sách từ thông tin nhập từ bàn phím
        Book book = new Book(id, authors, title, category);
        // Lưu dữ liệu vào tệp books.dat
        luuDuLieu(book);

        // Kiểm tra yêu cầu xóa file
        System.out.print("Bạn có muốn xóa file books.dat? (y/n): ");
        String confirm = scanner.nextLine();
        if (confirm.equalsIgnoreCase("y")) {
            System.out.println("Nhập đường dẫn thư mục và tên file backup: ");

            System.out.print("\t+ Đường dẫn đến thư mục: ");
            String backupFilePath = scanner.nextLine();

            System.out.print("\t+ Tên file muốn backup dữ liệu: ");
            String fileName = scanner.nextLine();

            xoaFile("books.dat", backupFilePath, fileName);
        }

        scanner.close();
    }

    public static void luuDuLieu(Book book) {
        try {
            File file = new File("books.dat");
            FileWriter fileWriter = new FileWriter(file, true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            // Ghi thông tin sách vào tệp
            bufferedWriter.write(book.getId() + ";" + book.getAuthors() + ";" + book.getTitle() + ";" + book.getCategory());
            bufferedWriter.newLine();

            bufferedWriter.close();
            System.out.println("Đã lưu thông tin sách vào tệp books.dat.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void xoaFile(String filePath, String backupFilePath, String fileName) {
        File file = new File(filePath);
        File backupFile = new File(backupFilePath + "\\" + fileName); // lưu đường dẫn đến thư mục cần backupFile

        // Kiểm tra nếu tệp tồn tại thì tiến hành xóa
        if (file.exists()) {
            try {
                // Tạo luồng đọc tệp
                FileReader fileReader = new FileReader(file);
                BufferedReader bufferedReader = new BufferedReader(fileReader);

                // Tạo luồng ghi tệp sao lưu
                FileWriter fileWriter = new FileWriter(backupFile);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

                String line;
                // Đọc từng dòng trong tệp và sao lưu vào tệp backup
                while ((line = bufferedReader.readLine()) != null) {
                    bufferedWriter.write(line);
                    bufferedWriter.newLine();
                }

                // Đóng luồng
                bufferedReader.close();
                bufferedWriter.close();

                // Xóa tệp gốc
                file.delete();

                System.out.println("Đã xóa tệp " + filePath + " và sao lưu dữ liệu vào " + backupFilePath);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Tệp " + filePath + " không tồn tại.");
        }
    }

}
