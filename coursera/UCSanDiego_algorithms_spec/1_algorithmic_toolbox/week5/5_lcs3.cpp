#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n = a.size() + 1;
    int m = b.size() + 1;
    int l = c.size() + 1;

    vector<vector <vector <int> > > v(n, vector<vector<int> > (m, vector<int> (l, 0)));

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            for(int k = 1; k < l; ++k) {
                if(a[i-1] == b[j-1] && a[i-1] == c[k-1]) {
                    v[i][j][k] = v[i-1][j-1][k-1] + 1;
                } else {
                    v[i][j][k] = max(v[i][j][k-1], max(v[i][j-1][k], v[i-1][j][k]));
                }
            }
        }
    }

    return v[n - 1][m - 1][l - 1];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
