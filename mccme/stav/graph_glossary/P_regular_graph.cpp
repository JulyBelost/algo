#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    int i, j;
    cin >> n >> m;
    vector<int> a(n);

    for(i = 0; i < m; ++i){
            int k,l;
            cin >> k >> l;
            a[k - 1] += 1;
            a[l - 1] += 1;
    }

    for(i = 1; i < n; ++i){
        if(a[i] != a[0]){
            cout << "NO" << "\n";
            break;
        }
    }
    if(i==n){
        cout << "YES" << "\n";
    }
}
