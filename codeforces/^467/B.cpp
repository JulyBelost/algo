// http://codeforces.com/problemset/problem/467/B

#include <iostream>
#include <vector>
using namespace std;

long long count_z(int x){
    int res = 0;

    while(x > 0) {
        res += x & 1;
        x >>= 1;
    }

    return res;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a;

    for(int i = 0; i <= m; ++i) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    int res = 0;

    for(int i = 0; i < m; ++i) {
        int t = a[i] ^ a[m];
        int s = count_z(t);
        if(s <= k) {
            ++res;
        }
    }

    cout << res;
}
