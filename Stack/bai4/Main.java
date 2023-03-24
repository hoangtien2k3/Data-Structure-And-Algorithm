package Stack.bai4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Stack<Integer> myStack = new Stack<>();
        while(true) {
            System.out.println("__________________________________");
            System.out.println("\n1. Them gia tri vao Stack");
            System.out.println("2. Xoa gia tri khoi Stack");
            System.out.println("3. Kiem tra rong");
            System.out.println("4. Tong cac gia tri trong Stack");
            System.out.println("5. Tim kiem gia tri trong Stack");
            System.out.println("6. Xuat danh sach Stack");
            System.out.println("__________________________________\n");
            System.out.print("Nhap lua chon: ");
            int lc = input.nextInt();
            switch (lc) {
                case 1: {
                    System.out.print("Them gia tri: ");
                    int value = input.nextInt();
                    myStack.push(value);
                    System.out.println("Da them gia tri " + value + " vao Stack !");
                    break;
                }
                case 2: {
                    System.out.print("Xoa gia tri dau khoi Stack");
                    myStack.pop();
                    System.out.println("Xoa gia tri thanh cong !");
                    break;
                }
                case 3: {
                    if (myStack.isEmpty()){
                        System.out.println("Stack rong: true");
                    } else {
                        System.out.println("Stack khong rong: flase");
                    }
                    break;
                }
                case 4: {
                    System.out.println("Tong cac gia tri trong Stack: " + myStack.sumOfElements());
                    break;
                }
                case 5: {
                    System.out.print("Tim kiem gia tri: ");
                    int value = input.nextInt();
                    if (myStack.search(value)) {
                        System.out.println("Gia tri " + value + " ton tai trong Stack !");
                    } else {
                        System.out.println("Gia tri " + value + " khong ton tai trong Stack !");
                    }
                    break;
                }
                case 6: {
                    System.out.print("\nXuat danh sach Stack: ");
                    myStack.display();
                    break;
                }
                case 7:
                    System.out.print("Ket thuc chuong trinh !!!");
                    return;
                default:
                    System.out.println("Nhap lai chua chon !!!");
                    break;
            }
        }
    }
}
