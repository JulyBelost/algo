#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int i, j, t;
    vector<pair<int, int> > deg(n);

    for(i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        deg[b - 1].first += 1;
        deg[a - 1].second += 1;
    }

    for(i = 0; i < n; ++i){
        cout << deg[i].first << "\n" << deg[i].second << "\n";
    }
}
