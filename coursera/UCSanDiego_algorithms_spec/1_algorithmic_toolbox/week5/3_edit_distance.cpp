#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
    int n = str1.size() + 1;
    int m = str2.size() + 1;
    int i, j;
    vector<vector <int> > v(n, vector<int> (m));

    for(i = 1; i < n; ++i) {
        v[i][0] = i;
    }

    for(i = 0; i < m; ++i) {
        v[0][i] = i;
    }

    for(i = 1; i < n; ++i) {
        for(j = 1; j < m; ++j) {
            if(str1[i - 1] == str2[j - 1]) {
                v[i][j] = v[i - 1][j - 1];
            } else {
                v[i][j] = min(v[i - 1][j - 1], min(v[i - 1][j], v[i][j - 1])) + 1;
            }
        }
    }

    return v[n - 1][m - 1];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
