#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

long long lcm_fast(int a, int b) {
  long long m = (long long) a * b;
  int gcd = gcd_fast(a, b);

  return m / gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
