#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1: -1; 2: /2; 3: /3;
int optimal_sequence(int n, vector<int> & sequence, vector<int> & v) {
    if (n == 0) {
        return 0;
    }
    if (v[n] != -1) {
        return v[n];
    }

    int m = 1000001, k = 0;
    int a[2][3] = {{1000001,1000001,1000001},{1,2,3}};
    // int x = 1000001, y = 1000001, z, o;

    if(n % 2 == 0) {
        a[0][1] = optimal_sequence(n / 2, sequence, v) + 1;
    }
    if(n % 3 == 0) {
        a[0][2] = optimal_sequence(n / 3, sequence, v) + 1;
    }
    a[0][0] = optimal_sequence(n - 1, sequence, v) + 1;

    for(int i = 0; i < 3; ++i) {
        if(a[0][i] < m) {
            m = a[0][i];
            k = a[1][i];
        }
    }

    sequence[n] = k;
    v[n] = m;
    return m;
}

int main() {
    int n, m;
    std::cin >> n;
    vector<int> sequence(n + 1, 0);
    vector<int> v(n + 1, -1);
    m = optimal_sequence(n, sequence, v);
    std::cout << m - 1 << std::endl;

    vector<int> result{n};
    for (size_t i = n; i > 1; ) {
        switch (sequence[i]) {
            case 2:
                i /= 2;
                result.push_back(i);
                break;
            case 3:
                i /= 3;
                result.push_back(i);
                break;
            default:
                i -= 1;
                result.push_back(i);
        }
    }
    reverse(result.begin(), result.end());
    for(int i = 0; i < result.size(); ++i){
      cout << result[i] << " ";
    }
}
