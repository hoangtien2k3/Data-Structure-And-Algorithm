package BaiTapUTT.baitap.Lab6;

import java.util.ArrayList;
import java.util.List;

class Composite extends Shape {
    private List<Shape> shapes = new ArrayList<>();

    @Override
    public void draw() {
        System.out.println("Vẽ một hình tổng hợp");
        for (Shape shape : shapes) {
            shape.draw();
        }
    }

    @Override
    public void rotate(int angle) {
        System.out.println("Xoay một hình tổng hợp bằng " + angle + " độ");
        for (Shape shape : shapes) {
            shape.rotate(angle);
        }
    }

    @Override
    public void moveLeft(int point) {
        System.out.println("Di chuyển hình tổng hợp " + point + " chỉ sang bên trái");
        for (Shape shape : shapes) {
            shape.moveLeft(point);
        }
    }

    @Override
    public void setColor(int color) {
        System.out.println("\nĐặt màu của hình dạng tổng hợp thành " + color);
        for (Shape shape : shapes) {
            shape.setColor(color);
        }
    }

    public void add(Shape shape) {
        shapes.add(shape);
    }

    public void remove(Shape shape) {
        shapes.remove(shape);
    }

    public Shape getChild(int id) {
        return shapes.get(id);
    }

    public int getChildCount() {
        return shapes.size();
    }
}