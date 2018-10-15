// http://codeforces.com/contest/1057/problem/C

#include <bits/stdc++.h>
using namespace std;

vector<int> a;
string col;
int t[50][2001];

int tanya(int s, int k){
    int t_sk = 1000000000;
    if(k <= 0){
        return 0;
    } else if(t[s][k] != -1){
        return t[s][k];
    } else {
        for(int i = 0; i < a.size(); ++i){
            int t_i;
            int l;
            if(i != s && col[i] != col[s] && a[i] > a[s]){
                t_i = tanya(i, k - a[i]);
                l = abs(s - i);
                if(t_i + l < t_sk){
                    t_sk = t_i + l;
                }
            }
        }
        t[s][k] = t_sk;
        return t_sk;
    }
}

int main(){
    int n, s, k, res;
    cin >> n >> s >> k;
    a.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cin >> col;
    memset(t, -1, sizeof(t));

    s -= 1;
    res = 1000000000;

    for(int i = 0; i < a.size(); ++i){
        int t_i;
        int l;
        t_i = tanya(i, k - a[i]);
        l = abs(s - i);
        if(t_i + l < res){
            res = t_i + l;
        }
    }

    cout << (res == 1000000000 ? -1 : res) << "\n";
}
