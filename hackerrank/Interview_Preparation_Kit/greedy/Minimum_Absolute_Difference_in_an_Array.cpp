//https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    long min = arr[1] - arr[0];

    for(int i = 1; i < arr.size() - 1; ++i){
        long diff = arr[i + 1] - arr[i];
        if(diff < min){
            min = diff;
        }

    }
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = minimumAbsoluteDifference(arr);

    cout << result << "\n";

    return 0;
}
