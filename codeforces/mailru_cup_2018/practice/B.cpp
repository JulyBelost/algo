// http://codeforces.com/contest/1057/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a = {0};
    for(int i = 0; i < n; ++i){
        int t = 0;
        cin >> t;
        a.push_back(i == 0 ? t : a[i] + t);
    }

    int res = 0;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            double l = j - i;
            double s = (a[j] - a[i]) / l;
            if(s > 100 && l > res){
                res = l;
            }
        }
    }

    cout << res << "\n";
}
