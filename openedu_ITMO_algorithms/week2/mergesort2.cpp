#include <iostream>
#include <vector>
#include <algorithm>

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

  for(int i=l; i<r; ++i){
    a[i] = m[i-l];
  }
  cout << l + 1 << " " << r << " " << a[l] << " " << a[r-1] << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> a(n);
  vector<int> m(n);

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

  mergesort(a, m, 0, a.size());

	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
}
