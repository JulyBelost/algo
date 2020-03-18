#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i, j, t;
    vector<pair<int, int> > deg(n);

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            cin >> t;
            deg[j].first += t;
            deg[i].second += t;
        }
    }

    for(i = 0; i < n; ++i){
        cout << deg[i].first << "\n" << deg[i].second << "\n";
    }
}
