#include <iostream>
#include <vector>

using namespace std;

int partition3(vector<int> &A) {
    int sum = 0;
    for(int i = 0; i < A.size(); ++i) {
        sum += A[i];
    }

    if(sum % 3 != 0) {
        return 0;
    }

    int n = A.size() + 1, m = sum / 3 + 1;
    vector<vector<vector <bool> > > v(n, vector<vector <bool> > (m, vector<bool> (m, false)));

    v[0][0][0] = true;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            for(int k = 0; k < m; ++k) {
                bool f = false;
                if (j - A[i - 1] >= 0) {
                    f = f || v[i - 1][j - A[i - 1]][k];
                }
                if (k - A[i - 1] >= 0) {
                    f = f || v[i - 1][j][k - A[i - 1]];
                }
                v[i][j][k] = f || v[i - 1][j][k];
            }
        }
    }

    return v[n - 1][m - 1][m - 1];
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);

    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }

    std::cout << partition3(A) << '\n';
}
