#include <iostream>
#include <cassert>
#include <string>
#include <vector>


using namespace std;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

long long get_maximum_value(const string &exp) {
    int m = exp.size();
    int n = (m / 2) + 1;

    vector<vector <long long> > mn(n, vector<long long> (n, 100000));
    vector<vector <long long> > mx(n, vector<long long> (n, -100000));

    for(int i = 0; i < n; ++i) {
        mn[i][i] = exp[2 * i] - '0';
        mx[i][i] = exp[2 * i] - '0';
    }

    for(int l = 1; l < n; ++l) {
        for(int i = 0; i < n - l; ++i) {
            int j = i + l;

            for(int k = i; k < j; ++k) {
                long long min_t = min(
                    min(
                        eval(mn[i][k], mn[k + 1][j], exp[k * 2 + 1]),
                        eval(mn[i][k], mx[k + 1][j], exp[k * 2 + 1])),
                    min(
                        eval(mx[i][k], mn[k + 1][j], exp[k * 2 + 1]),
                        eval(mx[i][k], mx[k + 1][j], exp[k * 2 + 1]))
                );
                mn[i][j] = min(min_t, mn[i][j]);

                long long max_t = max(
                    max(
                        eval(mn[i][k], mn[k + 1][j], exp[k * 2 + 1]),
                        eval(mn[i][k], mx[k + 1][j], exp[k * 2 + 1])),
                    max(
                        eval(mx[i][k], mn[k + 1][j], exp[k * 2 + 1]),
                        eval(mx[i][k], mx[k + 1][j], exp[k * 2 + 1]))
                );
                mx[i][j] = max(max_t, mx[i][j]);

            }
        }
    }

    return mx[0][n - 1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
