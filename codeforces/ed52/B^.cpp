// http://codeforces.com/contest/1065/problem/B

#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    long long mn, mx, z = 0;
    mn = max((n - m * 2), z);

    long long k = 0;
    while((k * (k - 1)) / 2 < m && k <= n){
        ++k;
    }
    mx = n - k;
    cout << mn << " " << mx << "\n";
}
