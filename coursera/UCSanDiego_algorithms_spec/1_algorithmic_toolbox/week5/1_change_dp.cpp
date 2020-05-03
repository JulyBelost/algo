#include <iostream>
#include <vector>

using namespace std;

int get_change(int m, vector<int> & v) {
    if (m < 0) {
        return 10000;
    }
    if (m == 0) {
        return 0;
    }
    if (v[m] != -1) {
        return v[m];
    }

    int x = min(get_change(m - 1, v) + 1, min(get_change(m - 3, v) + 1, get_change(m - 4, v) + 1));
    v[m] = x;
    return x;
}

int main() {
    int m;
    cin >> m;
    vector<int> v(m + 1, -1);
    cout << get_change(m, v) << '\n';
}
