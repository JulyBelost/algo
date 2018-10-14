// http://codeforces.com/contest/1064/problem/C

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[26] = {0};
    string res = "";

    for(int i = 0; i < n; ++i){
        ++a[s[i] - 'a'];
    }

    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < a[i]; ++j){
            res += 'a' + i;
        }
    }
    cout << res;
}
