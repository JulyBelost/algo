//https://www.hackerrank.com/challenges/ctci-bubble-sort/problem
#include <iostream>
#include <vector>

using namespace std;

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    int s = 0;
    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < a.size() - 1; ++j) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j+1]);
                s++;
            }
        }
    }
    cout << "Array is sorted in " << s << " swaps.\n";
    cout << "First Element: " << a[0] << "\n";
    cout << "Last Element: " << a[a.size() - 1] << "\n";
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    countSwaps(a);

    return 0;
}
