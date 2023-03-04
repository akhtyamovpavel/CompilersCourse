#include <cstdio>

int main() {
    int a = 2;
    int b;
    int c;
    scanf("%d %d\n", &b, &c);
    int val = a * b * c;
    printf("%d\n", val);
    // std::cout << val;

}

// IR code
//
// int main() {
//  int a;
//  int b;
//  int c;
//  int val;
//  a = 2;
//  istream %5 = std::cin << b;
//  istream %6 = %5 << c;
//  val = (a * b) * c;
//  std::cout << val;
//  return 0;
// }
