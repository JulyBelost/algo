// https://www.hackerrank.com/challenges/2d-array/problem
#include <iostream>
#include <vector>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> a) {
    int m = INT_MIN;
    for(int i = 0; i < a.size() - 2; ++i){
        for(int j = 0; j < a.size() - 2; ++j){
            m = max (a[i][j]  + a[i][j+1] + a[i][j+2] + a[i+1][j+1] + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2], m);
        }
    }
    return m;
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}
