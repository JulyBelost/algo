#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void mergesort(vector<int> &a, vector<int> &m, int l, int r){
  int n = r - l;
  if(n == 1){
    return;
  }
  int ll = l;
  int rl = l + n/2;
  int lr = l + n/2;
  int rr = r;
  mergesort(a, m, ll, rl);
  mergesort(a, m, lr, rr);

  for(int k = 0, i = ll, j = lr; k < (rr-ll) && (i < rl || j < rr); ++k){
    if(j == rr || (i < rl && a[i] <= a[j])){
      m[k] = a[i];
      ++i;
    } else {
      m[k] = a[j];
      ++j;
    }
  }

  for(int i = l; i < r; ++i){
    a[i] = m[i - l];
  }
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector <int> v(n);

	for(int i = 0; i < n; ++i){
    cin >> v[i];
	}

  for(int i = 0; i < k; ++i){
    vector <int> a;

    for(int j = i; j < n; j += k){
      a.push_back(v[j]);
    }
    int a_n = a.size();
    vector <int> m(a_n);
    mergesort(a, m, 0, a_n);

    for(int j = i, l = 0; j < n && l < a_n; j += k, ++l){
      v[j] = a[l];
    }
  }

  for(int i = 1; i < n; ++i){
    if(v[i - 1] > v[i]){
      cout << "NO";
      break;
    } else if(i == n - 1) {
      cout << "YES";
    }
  }
}
