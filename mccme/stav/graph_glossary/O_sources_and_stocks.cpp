#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i, j, t;
    set<int> a;
    set<int> b;

    for(i = 0; i < n; ++i){
        a.insert(i);
        b.insert(i);
    }

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            cin >> t;
            if(t == 1){
                b.erase(i);
                a.erase(j);
            }
        }
    }

    cout << a.size() << "\n";
    for(int x: a){
        cout << x + 1 << "\n";
    }
    cout << b.size() << "\n";
    for(int y: b){
        cout << y + 1 << "\n";
    }
}
