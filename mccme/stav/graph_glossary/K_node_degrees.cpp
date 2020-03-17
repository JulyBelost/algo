#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool res = false;
    int i, j, t, s;

    for(i = 0; i < n; ++i){
        s = 0;
        for(j = 0; j < n; ++j){
            cin >> t;
            s += t;
        }
        cout << s << "\n";
    }
}
