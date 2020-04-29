#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int count_element(vector<int> & a, int left, int right, int element) {
    int cnt = 0;

    for(int i = left; i < right; ++i) {
        if(a[i] == element) {
            ++cnt;
        }
    }

    return cnt;
}

int get_majority_element(vector<int> & a, int left, int right) {
    if (left >= right) {return -1;}
    if (left + 1 == right) {return a[left];}

    int middle = left + (right - left) / 2;
    int l = get_majority_element(a, left, middle);
    int r = get_majority_element(a, middle, right);

    if (l == r) {
      return l;
    } else {
      if (l != -1){
          int cnt_l = count_element(a, left, right, l);
          if (cnt_l * 2 > right - left) {
              return l;
          }
      }
      if (r != -1){
          int cnt_r = count_element(a, left, right, r);

          if (cnt_r * 2 > right - left) {
              return r;
          }
      }
    }

    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
