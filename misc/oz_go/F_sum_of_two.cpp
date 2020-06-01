#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int check_sum(const vector<int> & v, int x){
    unordered_set<int> rems;

    for(int i = 0; i < v.size(); ++i){
        if(rems.find(x - v[i]) != rems.end()){
            return 1;
        } else {
            rems.insert(v[i]);
        }
    }

    return 0;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y;
    cin >> x;

    vector<int> v;
    while(scanf("%d", &y) == 1){
        v.push_back(y);
    }

    cout << check_sum(v, x);
}
