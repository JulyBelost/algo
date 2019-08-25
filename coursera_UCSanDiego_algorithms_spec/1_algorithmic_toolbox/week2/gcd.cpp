#include <iostream>
#include <cstdlib>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
    if(a < b){
        std::swap(a,b);
    }

    if(b == 0){
        return a;
    }

    int res = gcd_fast(b, a % b);
    return res;
}

void stress_test(){
    while(true){
        int a = rand() % 1000000000 + 1;
        int b = rand() % 1000000000 + 1;
        std::cout << a << " " << b << '\n';

        int r1 = gcd_fast(a, b);
        int r2 = gcd_naive(a, b);

        if(r1 != r2){
            std::cout << r1 << " " << r2 << " not ok\n";

            return;
        }
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
