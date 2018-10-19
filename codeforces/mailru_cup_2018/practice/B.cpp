// http://codeforces.com/contest/1057/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        a[i] = a[i - 1] + t;
    }

    int res = 0;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            int l = j - i;
            if(a[j] - a[i] > 100 * l && l > res){
                res = l;
            }
        }
    }

    cout << res << "\n";
}
