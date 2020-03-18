#include <vector>
#include <iostream>

using namespace std;

void check_transitivity(vector<vector<int> > &a){
    int n = a.size();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == 1){
                for(int k = 0; k < n; ++k){
                    if(a[j][k] == 1 && a[i][k] != 1 && k != i){
                        cout << "NO" << "\n";
                        return;
                    }
                }
            }
        }
    }

    cout << "YES" << "\n";
    return;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    check_transitivity(a);
}
