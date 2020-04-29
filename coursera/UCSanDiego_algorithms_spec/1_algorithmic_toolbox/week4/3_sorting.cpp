#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void partition2(int res[], vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
    }
    }
    swap(a[l], a[j]);

    res[0] = j;
    l = j;
    x = a[l];

    for (int i = l + 1; i <= r; i++) {
    if (a[i] == x) {
      j++;
      swap(a[i], a[j]);
    }
    }
    swap(a[l], a[j]);
    res[1] = j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {

    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m[2];
    partition2(m, a, l, r);

    randomized_quick_sort(a, l, m[0] - 1);
    randomized_quick_sort(a,  m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
