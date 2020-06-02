//https://www.hackerrank.com/challenges/mark-and-toys/problem
#include <iostream>
#include <vector>

using namespace std;

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    int cnt = 0;
    sort(prices.begin(), prices.end());
    int i = 0;
    while(k >= prices[i]){
        k -= prices[i];
        ++cnt;
        ++i;
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maximumToys(prices, k);

    cout << result << "\n";

    return 0;
}
