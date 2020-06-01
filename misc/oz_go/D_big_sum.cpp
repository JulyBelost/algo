#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    vector<int> v(1001, 0), w(1001, 0), s(1001, 0);

    for(int i = 0; i < a.size(); ++i){
        v[v.size() - a.size() + i] = a[i] - '0';
    }
    for(int i = 0; i < b.size(); ++i){
        w[w.size() - b.size() + i] = b[i] - '0';
    }

    int rem = 0;
    for(int i = s.size() - 1; i >= 0; --i){
        int cur = v[i] + w[i] + rem;
        s[i] += cur % 10;
        rem = cur / 10;
    }

    int i = 0;
    while(i < s.size() - 1 && s[i] == 0){
        ++i;
    }
    for(; i < s.size(); ++i){
        cout << s[i];
    }
}
