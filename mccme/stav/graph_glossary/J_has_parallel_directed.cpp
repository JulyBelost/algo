#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(n));
    bool f = false;

    for(int i = 0; i < m; ++i){
        int k,l;
        cin >> k >> l;
        if(a[k - 1][l - 1] == 0){
            a[k - 1][l - 1] = 1;
        } else {
            f = true;
            break;
        }
    }

    cout << (f ? "YES" : "NO") << '\n';
}
