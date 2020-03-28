#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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

int get_fibonacci_partial_sum_fast(long long from, long long to) {
    int a = get_fibonacci_huge_fast(to + 2, 10);
    int b = get_fibonacci_huge_fast(from + 1, 10);

    return (a + 10 - b) % 10;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
