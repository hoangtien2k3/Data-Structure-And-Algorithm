package BaiTapUTT.baitap.Lab6;

import java.util.*;

import java.util.ArrayList;
import java.util.List;

public class Client {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập vào line: ");
        int n_line = scanner.nextInt();
        Shape line = new Line(n_line);

        System.out.print("Nhập vào circular1: ");
        int n_circular1 = scanner.nextInt();
        Shape circular1 = new Circular(n_circular1);

        System.out.print("Nhập vào circular2: ");
        int n_circular2 = scanner.nextInt();
        Shape circular2 = new Circular(n_circular2);

        System.out.print("=> Nhập vào composite <=\n");
        System.out.print("\t+ Nhập composite1: ");
        int composite1 = scanner.nextInt(); // 8
        System.out.print("\t+ Nhập composite1: ");
        int composite2 = scanner.nextInt(); // 6
        System.out.print("\t+ Nhập composite1: ");
        int composite3 = scanner.nextInt(); // 12

        System.out.print("Nhập vào Circular: ");
        int n_Circular = scanner.nextInt();

        Shape composite = new Composite();
        ((Composite) composite).add(new Line(composite1));
        ((Composite) composite).add(new Line(composite2));
        ((Composite) composite).add(new Line(composite3));
        ((Composite) composite).add(new Circular(n_Circular));

        Shape[] figure = {line, circular1, circular2, composite};

        // Thực hiện đổi màu đồng bộ và quay 1 góc 90 độ đối với các đối tượng trong figure
        for (Shape shape : figure) {
            shape.setColor(1); // Đổi màu đồng bộ
            shape.rotate(90); // Quay 1 góc 90 độ

            // In ra thông tin chi tiết của hình học
            if (shape instanceof Line) {
                System.out.println("\nLine length: " + ((Line) shape).getLength());
            } else if (shape instanceof Circular) {
                System.out.println("Circular radius: " + ((Circular) shape).getRadius());
                System.out.println("Circular length: " + ((Circular) shape).getLength());
            } else if (shape instanceof Composite) {
                Composite compositeShape = (Composite) shape;
                for (int i = 0; i < compositeShape.getChildCount(); i++) {
                    Shape child = compositeShape.getChild(i);
                    if (child instanceof Line) {
                        System.out.println("Line length: " + ((Line) child).getLength());
                    } else if (child instanceof Circular) {
                        System.out.println("Circular radius: " + ((Circular) child).getRadius());
                        System.out.println("Circular length: " + ((Circular) child).getLength());
                    }
                }
            }
        }
    }
}


