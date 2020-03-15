// http://codeforces.com/problemset/problem/579/A

#include <iostream>
using namespace std;

long long count_bacteria(int x){
    int res = 0;

    while(x > 0) {
        res += x & 1;
        x >>= 1;
    }

    return res;
}

int main(){
    int n;
    cin >> n;

    cout << count_bacteria(n);
}
