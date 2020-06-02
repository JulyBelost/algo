//https://www.hackerrank.com/challenges/ctci-merge-sort/problem
#include <iostream>
#include <vector>

using namespace std;

long mergeSort(vector<int> & a){
    if(a.size() <= 1) {
        return 0;
    }

    vector<int> b(a.begin(), a.begin() + a.size() / 2);
    vector<int> c(a.begin() + a.size() / 2, a.end());
    long b_s = mergeSort(b);
    long c_s = mergeSort(c);
    long a_s = 0;

    for(int i = 0, l = 0, r = 0; i < a.size(); ++i){
        if(l < b.size() && (b[l] <= c[r] || r >= c.size())) {
            a[i] = b[l];
            ++l;
        } else {
            a[i] = c[r];
            ++r;
            a_s += b.size() - l;
        }
    }
    return b_s + a_s + c_s;
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    return mergeSort(arr);
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long result = countInversions(arr);

        cout << result << "\n";
    }

    return 0;
}
