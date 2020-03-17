#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    bool res = true;
    int i, j;

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            cin >> m[i][j];
        }
    }

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            if((i == j && m[i][j] > 0) || (m[i][j] != m[j][i])) {
                res = false;
                break;
            }
        }
        if(!res) break;
    }

    cout << (res ? "YES" : "NO");
}
