// http://codeforces.com/contest/1066/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int j = 0; j < t; ++j){
        long long e, v, l, r;
        cin >> e >> v >> l >> r;
        long long res;
        res = e / v - (r / v - (l - 1) / v);

        cout << res << "\n";
    }
}
