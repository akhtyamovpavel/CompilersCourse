#include <iostream>


int foo(int x) {

    if (x <= 5) {
        int z;
        z = 9;
        return z + x;
    } else {
        int y;
        y = 8;
        return y + x;
    }
}


int main() {
    int y = foo(5);
    std::cout << y << std::endl;
    int z = foo(9);
    std::cout << z << std::endl;
}
