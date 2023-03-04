int foo(int x) {
    if (x > 5) {
        return x + 8;
    } else {
        return x + 5;
    }
}

int main() {
    foo(4);
    foo(6);
}
