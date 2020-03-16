#include <iostream>

int main(){
  int a = 0;
  std::cin >> a;
  long long n = 0, m = 0;
  for(int i = 0; i < a; ++i){
      int t;
      std::cin >> t;

      if(t > n && t <= m){
          n = t;
      } else if(t > m){
          n = m;
          m = t;
      }

  }
  std::cout << n * m;
  return 0;
}
