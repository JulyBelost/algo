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
        if(a[i] > h){
            h = a[i];
        }
        if(a[i] < l){
            l = a[i];
        }
    }

    if(n == 1){
        cout << 0 << "\n";
    } else {
        int g = h - l;
        vector<int> b(g);
        for(int i = 0; i < n; ++i){
            if(a[i] != l){
                ++b[(a[i] - l) - 1];
            }
        }
        for(int i = g - 1; i >= 0; --i){
            if(i < g -1){
                b[i] += b[i + 1];
            }
        }

        int res = 0;

        for(int i = 0; i < g;){
            int t = 0;
            while(i < g && t < k){
                if(t + b[i] <= k){
                    t += b[i];
                    ++i;
                } else {
                    break;
                }
            }
            ++res;
        }
        cout << res << "\n";
    }
}
