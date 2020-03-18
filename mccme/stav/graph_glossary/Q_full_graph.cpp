#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    int i, j, s = 0;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(n));

    for(i = 0; i < m; ++i){
        int k,l;
        cin >> k >> l;
        if(a[k - 1][l - 1] == 0){
            a[k - 1][l - 1] = 1;
            a[l - 1][k - 1] = 1;
            s++;
        }
    }

    cout << ((s >= (n * (n-1) / 2)) ? "YES" : "NO") << "\n";
}
