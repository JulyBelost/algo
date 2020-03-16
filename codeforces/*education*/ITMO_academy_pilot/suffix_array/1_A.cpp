#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void set_class(
    vector<int> &ord,
    vector<int> &cls,
    vector<pair<pair<int, int>, int> > &a,
    int n
){
    // sort pairs by char component
    sort(a.begin(), a.end());
    // save sorted indexes to order vector
    for(int i = 0; i < n; ++i) ord[i] = a[i].second;
    // set classes
    cls[0] = 0;
    for(int i = 1; i < n; ++i){
        cls[ord[i]] = cls[ord[i-1]] + ((a[i].first != a[i-1].first) ? 1 : 0);
    }

    return;
}

int main(){
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> ord(n), cls(n);
    vector<pair<pair<int, int>, int> > a(n);

    // make pairs of string char number and its index
    for(int i = 0; i < n; ++i) a[i] = make_pair(make_pair(s[i], s[i]), i);
    // set classes for k=0 case
    set_class(ord, cls, a, n);

    // cases for k > 0
    int k = 0;
    while((1 << k) < n) {
        vector<pair<pair<int, int>, int> > a(n);
        // pairs of number constructed of two parts' classes and element index
        for(int i = 0; i < n; ++i){
            a[i] = make_pair(make_pair(cls[i] * 10, cls[(i + (1 << k)) % n]), i);
        }

        set_class(ord, cls, a, n);
        ++k;
    }

    // output result
    for(int i = 0; i < n; ++i){
        cout << ord[i] << "\n";
    }
}
