#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector <pair <double, int> > a(n);

	for (int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	for (int j = 1; j < n; ++j){
		int i = j - 1;

		while(i >= 0 && a[i+1].first < a[i].first){
			swap(a[i+1], a[i]);
			--i;
		}
	}

	cout << a[0].second << " " << a[(n+1)/2 - 1].second << " " << a[n-1].second;
}
