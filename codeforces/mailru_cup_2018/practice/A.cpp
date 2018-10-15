// http://codeforces.com/contest/1057/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int l = n - 1;
    vector<int> a(l);
    vector<int> res = {n};
    for(int i = 0; i < l; ++i){
        cin >> a[i];
    }

    for(int i = l - 1; ; i = a[i] - 2){
        res.push_back(a[i]);
        if(a[i] == 1){
            break;
        }
    }

    for(int i = res.size() - 1; i >= 0; --i){
        cout << res[i] << " ";
    }
}
