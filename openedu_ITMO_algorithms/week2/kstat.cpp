#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;


void interval_qsort(vector<int> &a, int l, int r, int k1, int k2){
  int n = r - l;
  if (n == 1){
    return;
  }

  mt19937 rand;
  uniform_int_distribution<int> distr(l, r - 1);
  int x = distr(rand);
  int a_x = a[x];

  int i = l, j = r - 1;
  while (i <= j){
    while (a[i] < a_x){
      ++i;
    }
    while (a[j] > a_x){
      --j;
    }
    if (i <= j){
      swap(a[i], a[j]);
      ++i;
      --j;
    }
  }
  if (l < j && j >= k1){
    interval_qsort(a, l, j + 1, k1, k2);
  }
  if (i < r - 1 && i <= k2 - 1){
    interval_qsort(a, i, r, k1, k2);
  }
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k1, k2;
  int d, b, c;
	cin >> n >> k1 >> k2;
  cin >> d >> b >> c;
	vector <int> a(n);

	for (int i = 0; i < n; ++i){
    if(i < 2){
      cin >> a[i];
    } else {
      a[i] = d * a[i - 2] + b * a[i - 1] + c;
    }
	}

  k1 -= 1;
  interval_qsort(a, 0, a.size(), k1, k2);

	for (int i = k1; i < k2; ++i){
		cout << a[i] << " ";
	}
}
