#include <sys/resource.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1: -1; 2: /2; 3: /3;
void optimal_sequence(int n, vector<int> & sequence, vector<int> & v) {
    int m = n + 1;
    v[1] = 0;
    for(int i = 1; i < n; ++i) {
        if(i * 2 < m && v[i] + 1 < v[i * 2]){
            v[i * 2] = v[i] + 1;
            sequence[i * 2] = 2;
        }
        if(i * 3 < m && v[i] + 1 < v[i * 3]){
            v[i * 3] = v[i] + 1;
            sequence[i * 3] = 3;
        }
        if(v[i] + 1 < v[i + 1]){
            v[i + 1] = v[i] + 1;
            sequence[i + 1] = 1;
        }
    }
}

int main() {
    int n, m;
    std::cin >> n;
    vector<int> sequence(n + 1, 0);
    vector<int> v(n + 1, 1000001);
    optimal_sequence(n, sequence, v);
    std::cout << v[n] << std::endl;

    vector<int> result{n};
    for (size_t i = n; i > 1 ; ) {
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
