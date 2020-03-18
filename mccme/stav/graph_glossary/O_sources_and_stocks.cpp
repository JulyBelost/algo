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
    for(set<int>::iterator a_it = a.begin(); a_it != a.end(); a_it++){
        cout << *a_it + 1 << "\n";
    }
    cout << b.size() << "\n";
    for(set<int>::iterator b_it = b.begin(); b_it != b.end(); b_it++){
        cout << *b_it + 1 << "\n";
    }
}
