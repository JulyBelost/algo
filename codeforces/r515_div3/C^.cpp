// http://codeforces.com/contest/1066/problem/C

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int l = 0, r = 0;
    int c[200001]  = {0};
    for(int j = 0; j < t; ++j){
        char p;
        int id;
        cin >> p >> id;
        if(j == 0){
            c[id] = l;
        } else if(p == 'L'){
            --l;
            c[id] = l;
        } else if(p == 'R'){
            ++r;
            c[id] = r;
        } else if(p == '?'){
            cout << min(c[id] - l, r - c[id]) << "\n";
        }
    }
}
