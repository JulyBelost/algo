//https://www.hackerrank.com/challenges/luck-balance/problem
#include <vector>
#include <iostream>

using namespace std;

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    int luck = 0;
    vector<int> imp;
    for(int i = 0; i < contests.size(); ++i){
        if(contests[i][1] == 1){
            imp.push_back(contests[i][0]);
        } else {
            luck += contests[i][0];
        }
    }
    sort(imp.begin(), imp.end(), greater<int>());
    for(int i = 0; i < imp.size(); ++i){
        if(i < k){
            luck += imp[i];
        } else {
            luck -= imp[i];
        }
    }
    return luck;
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    cout << result << "\n";

    return 0;
}
