package BaiTapUTT.baitap.Lab6;

class Line extends Shape {
    private int length;

    public Line(int length) {
        this.length = length;
    }

    @Override
    public void draw() {
        System.out.println("Vẽ một đường");
    }

    @Override
    public void rotate(int angle) {
        System.out.println("Xoay một dòng bằng " + angle + " độ");
    }

    @Override
    public void moveLeft(int point) {
        System.out.println("Di chuyển một dòng " + point + " chỉ sang bên trái");
    }

    @Override
    public void setColor(int color) {
        System.out.println("\nĐặt màu của một dòng thành " + color);
    }

    public int getLength() {
        return length;
    }
}