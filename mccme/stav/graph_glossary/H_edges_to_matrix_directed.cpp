#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    int i, j;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, 0));

    for(i = 0; i < m; ++i){
            int k,l;
            cin >> k >> l;
            a[k - 1][l - 1] = 1;
    }

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
