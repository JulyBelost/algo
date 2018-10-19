// http://codeforces.com/contest/1065/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i<t; ++i){
		long long s, a, b, c;
		cin >> s >> a >> b >> c;
		long long res = (s / (a * c)) * (a + b) + (s % (a * c)) / c;
		cout << res << "\n";
	}
}
