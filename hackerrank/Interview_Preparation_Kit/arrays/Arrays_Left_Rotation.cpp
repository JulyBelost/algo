//https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
#include <vector>
#include <iostream>

using namespace std;

void processRotPart(vector<int> & a, int i, int j, int d, int dir) {
    int n = (i + j) - 2 * min(i,j) + 1;

    if(n <= 1 || d==0){
        return;
    }

    int k = i;
    for(; (dir * k) <= (dir * j) - d; k += dir){
        swap(a[k], a[k + dir * d]);
    }

    processRotPart(a, j, k, n % d, dir * -1);
}

void rotLeft(vector<int> & a, int d) {
    processRotPart(a, 0, a.size() - 1, d, 1);
}

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> result = a;
    rotLeft(result, d);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    cout << "\n";

    return 0;
}
