package BaiTapUTT.baitap.Lab6;

class Circular extends Shape {
    private int radius;

    public Circular(int radius) {
        this.radius = radius;
    }

    @Override
    public void draw() {
        System.out.println("Vẽ hình tròn");
    }

    @Override
    public void rotate(int angle) {
        System.out.println("Quay hình tròn " + angle + " độ");
    }

    @Override
    public void moveLeft(int point) {
        System.out.println("Di chuyển hình tròn " + point + " chỉ sang bên trái");
    }

    @Override
    public void setColor(int color) {
        System.out.println("\nĐặt màu của hình tròn thành " + color);
    }

    public int getRadius() {
        return radius;
    }

    public double getLength() {
        return 2 * Math.PI * radius;
    }
}