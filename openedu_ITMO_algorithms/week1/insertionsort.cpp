#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	cout << "1 ";

	for (int j = 1; j < n; ++j){
		int i = j - 1;

		while(i >= 0 && a[i+1] < a[i]){
			int t = a[i+1];
			a[i+1] = a[i];
			a[i] = t;
			--i;
		}

		cout << (i == j-1 ? j + 1 : i + 2) << " ";
	}

	cout << "\n";

	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
}
