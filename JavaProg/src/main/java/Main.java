public class Main {
    public static void main(String[] args) {
        Fee fee = new Fee();

        fee = setFoo(fee);

        fee.print();
    }

    public static Fee setFoo(Fee fee) {
        Foo foo = new Foo();
        fee.foo = foo;
        return fee;
    }
}
