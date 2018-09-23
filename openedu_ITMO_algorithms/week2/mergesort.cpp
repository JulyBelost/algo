#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergesort(vector<int> &a, int l = 0, int r = 0){
  int n = r - l;
  if(n==1){
    return;
  }
  int ll = l;
  int rl = l + n/2;
  int lr = l + n/2;
  int rr = r;
  mergesort(a, ll, rl);
  mergesort(a, lr, rr);
  vector<int> m(n);
  merge(a.begin()+ll, a.begin()+rl, a.begin()+lr, a.begin()+rr, m.begin());
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
	vector <int> a(n);

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

  mergesort(a, 0, a.size());

	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
}
