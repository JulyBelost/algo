// http://codeforces.com/contest/1066/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    vector<int> b(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    int res = 0;
    for(int i = 0; i < n; ){
        bool good = false;
        int j = i, k = i;
        while(j < n && j < (i == 0 ? i + r : i - 1 + 2 * r)){
            if(b[j] == 1){
                if(!good){
                    good = true;
                    ++res;
                }
                k = j + 1;
            }
            ++j;
        }
        i = k;
        if(!good){
            res = -1;
            break;
        }
        if(i >= n - r + 1){
            break;
        }
    }
    cout << res << "\n";
}
