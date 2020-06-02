//https://www.hackerrank.com/challenges/greedy-florist/problem
#include <vector>
#include <iostream>

using namespace std;

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int price = 0;
    sort(c.begin(), c.end(), greater<int>());
    for(int i = 0; i < c.size(); ++i){
        price += (i / k + 1) * c[i];
    }
    return price;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int minimumCost = getMinimumCost(k, c);

    cout << minimumCost << "\n";

    return 0;
}
