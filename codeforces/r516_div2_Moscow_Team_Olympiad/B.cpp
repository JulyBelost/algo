//http://codeforces.com/contest/1064/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        long long a;
        cin >> a;
        int s = 0;
        while(a != 0){
            s += a & 1;
            a = a >> 1;
        }
        long long res = pow(2, s);
        cout << res << "\n";
    }
}
