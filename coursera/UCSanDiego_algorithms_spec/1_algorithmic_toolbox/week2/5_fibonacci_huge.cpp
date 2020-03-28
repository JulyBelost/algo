#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long fibonacci_fast(int n, long long m, int first, int second) {
    if (n <= 1){
        return n;
    }
    long long a = first, b = second;
    for (int i = 2; i <= n; ++i){
        long long c = a;
        a = b;
        b = (c + b) % m;
    }

    return b;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    vector<vector<int> > matrix(m, vector<int>(m, -1));

    int a, b, p, c;
    int previous = 0;
    int current  = 1;

    for (int i = 0; i <= m * m; ++i) {
        if(matrix[previous][current] == -1) {
            matrix[previous][current] = i;
        } else {
            a = matrix[previous][current];
            b = i;
            p = previous;
            c = current;
            break;
        }

        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    int n2 = (n - a) % (b - a);

    return fibonacci_fast(n2, m, p, c);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
