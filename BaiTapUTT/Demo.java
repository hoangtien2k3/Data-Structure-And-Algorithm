package BaiTapUTT;


class Base {
    private void f() { System.out.println("base f()"); }
    public void show() { f(); }
}
public class Demo extends Base {
    public void f() {
        System.out.println("derived f()");
    }
    public static void main(String[] args) {
        Demo d = new Demo();
        Base b = d;
        b.show();
        d.show();
    }
}









