#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i, j, t, s = 0;

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            cin >> t;
            if(t == 1 && i < j){
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }
}
