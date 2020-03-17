#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool res = false;
    int i, j, t;

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            cin >> t;
            if(i == j && t == 1) {
                res = true;
            }
        } 
    }

    cout << (res ? "YES" : "NO");
}
