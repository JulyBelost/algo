// http://codeforces.com/contest/1064/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b > c && b + c > a && a + c > b){
            cout << 0 << "\n";
    } else {
        if(a >= b + c){
            cout << a - (b + c) + 1 << "\n";
        } else if(b >= a + c){
            cout << b - (a + c) + 1 << "\n";
        } else if(c >= a + b){
            cout << c - (b + a) + 1 << "\n";
        }
    }
}
