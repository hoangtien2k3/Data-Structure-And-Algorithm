
## Lý Thuyết:
Câu 1:
Hãy cho biết kết quả và lý do của đoạn chương trình sau:
 
```java
            class Msg {
                public Msg() {
                    System.out.println("Hello");
                }
                public void sayGoodbye() {
                    System.out.println("Goodbye");
                }
            }
            class TestMsg extends Msg {
                public TestMsg() {
                    super();
                    System.out.println("Hello Java");
                }
                public void sayGoodbye() {
                    System.out.println("Goodbye Java");
                }
            }
            public class Demo {
                public static void main(String args[]) {
                    Msg m1 = new Msg();
                    Msg m2 = new TestMsg();
                    m1.sayGoodbye();
                    m2.sayGoodbye();
                }
            }  
```

Kết quả:
- Hello
- Hello
- Hello Java
- Goodbye
- Goodbye Java


## Câu 2: Hãy cho biết kết quả và lý do
```java
class Msg {
    public Msg() {
        System.out.println("Hello");
    }
    public void sayGoodbye() {
        System.out.println("Goodbye");
    }
}
class TestMsg extends Msg {
    public void sayGoodbye() {
        System.out.println("Goodbye Java");
    }
}
public class Demo {
    public static void main(String args[]) {
        Msg m1 = new Msg();
        Msg m2 = new TestMsg();
        m1.sayGoodbye();
        m2.sayGoodbye();
    }
} 
```

### Kết quả:
- Hello
- Hello
- Goodbye
- Goodbye Java








































