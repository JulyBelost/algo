#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector <pair <long long, int> > a(n);
	vector <int> ind(n);

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

	for (int i = 0; i < n; ++i){
		int j = i;
		while(a[j].second != (j+1) && (a[j].second != -1 && a[a[j].second - 1].second != -1)){
			cout << "Swap elements at indices ";
			cout << min(a[j].second, j + 1) <<" and "<< max(a[j].second, j + 1) <<".\n";
			int p = j;
			j = a[j].second - 1;
			a[p].second = -1;
		}
	}

	cout << "No more swaps needed.\n";

	for (int i = 0; i < n; ++i){
		cout << a[i].first << " ";
	}
}
