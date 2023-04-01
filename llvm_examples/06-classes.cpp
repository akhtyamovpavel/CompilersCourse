class A {
 private:
    int c_;
};

class Foo {
 public:
     Foo(int a) {
        a_ = a;
     }

     int Get() {
        return a_;
     }

     void Set(int a) {
        a_ = a;
     }

     static int GG(int a) {
        return a + 1;
     }
 
 private:
     int a_;
     bool b;
     A* d;
};


int main() {
    int x;
    Foo foo(x);
    int a = foo.Get();

    foo.Set(6);
    int b = foo.GG(10);

}
