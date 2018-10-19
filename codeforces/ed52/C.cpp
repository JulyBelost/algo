// http://codeforces.com/contest/1065/problem/C

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int l = 200000, h = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        h = max(h, a[i]);
        l = min(l, a[i]);
    }

    if(n == 1){
        cout << 0 << "\n";
    } else {
        int g = h - l;
        vector<int> b(g + 1);
        for(int i = 0; i < n; ++i){
            if(a[i] != l){
                ++b[(a[i] - l)];
            }
        }
        for(int i = g; i > 0; --i){
            if(i < g){
                b[i] += b[i + 1];
            }
        }

        int res = 0;

        for(int i = 1; i <= g;){
            for (int t = 0; i <= g && t + b[i] <= k; ++i) {
                t += b[i];
            }
            ++res;
        }
        cout << res << "\n";
    }
}
